/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zero <zero@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:26:57 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/25 04:22:14 by zero             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	parse_args(t_pipex *pipex, int argc, char **argv, char **envp)
{
	char	**splitted_env_paths;

	if (argc < 5)
	{
		perror("invalid number of arguments.");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
	{
		pipex->is_here_doc = 1;
		pipex->limiter = argv[2];
		pipex->cmds_count = argc - 4;
	}
	else
		pipex->is_here_doc = 0;
	if (get_env_paths(envp))
		splitted_env_paths = ft_split(get_env_paths(envp) + 5, ':');
	else
		splitted_env_paths = NULL;
	pipex->env_paths = splitted_env_paths;
	pipex->envp = envp;
	pipex->curr_cmd = NULL;
	pipex->curr_cmd_executable = NULL;
	pipex->i = 0;
	pipex->exit_status = 0;
}

static int	file_opener(t_pipex *pipex, char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (i == 2)
		fd = open(argv, O_RDONLY, 0666);
	if (fd == -1)
		handle_error(pipex, "error opening the file", EXIT_FILE_ERROR);
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		in_file_fd;
	int		out_file_fd;

	parse_args(&pipex, argc, argv, envp);
	if (pipex.is_here_doc)
	{
		pipex.i = 3;
		out_file_fd = file_opener(&pipex, argv[argc -1], 0);
		handle_here_doc(&pipex, argc);
		in_file_fd = open(".here_doc", O_RDONLY, 0777);
		if (in_file_fd < 0)
			handle_error(&pipex, "error opening the file", EXIT_FILE_ERROR);
		dup2(in_file_fd, STDIN_FILENO);
	}
	else
	{
		pipex.i = 2;
		in_file_fd = file_opener(&pipex, argv[1], 2);
		out_file_fd = file_opener(&pipex, argv[argc - 1], 1);
		dup2(in_file_fd, STDIN_FILENO);
	}
	piping_and_clear(&pipex, argv, argc, &out_file_fd);
	exit (pipex.exit_status);
}
