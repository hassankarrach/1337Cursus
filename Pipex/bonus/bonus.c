/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:26:57 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/02 14:02:23 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	parse_args(t_pipex *pipex, int argc, char **argv, char **envp)
{
	char	*env_paths;
	char	**splitted_env_paths;

	if (!envp || argc < 5)
	{
		perror("invalid envirement path or number of arguments.");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
	{
		pipex->is_here_doc = 1;
		pipex->limiter = argv[2];
		pipex->cmds_count = argc - 4;
	}
	else
	{
		pipex->is_here_doc = 0;
		pipex->cmds_count = argc - 3;
	}
	env_paths = get_env_paths(envp) + 5;
	splitted_env_paths = ft_split(env_paths, ':');
	pipex->env_paths = splitted_env_paths;
	pipex->envp = envp;
	pipex->curr_cmd = NULL;
	pipex->curr_cmd_executable = NULL;
}

static int	file_opener(t_pipex *pipex, char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		fd = open(argv, O_RDONLY, 0777);
	if (fd == -1)
		handle_error(pipex, "error opening the file");
	return (fd);
}

static void	child_proc(t_pipex *pipex, char *full_cmd)
{
	int	pid;
	int	fd[2];

	pipex->curr_cmd = ft_split(full_cmd, ' ');
	pipex->curr_cmd_executable = get_exec_full_path(pipex->curr_cmd[0],
			pipex->env_paths);
	if (pipe(fd) == -1)
		handle_error(pipex, "Error creating pipe");
	pid = fork();
	if (pid == -1)
		handle_error(pipex, "Error forking");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		handle_execute(pipex);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		free_2d(pipex->curr_cmd);
		free(pipex->curr_cmd_executable);
	}
}

static void	handle_last_cmd(t_pipex *pipex, int out_file_fd, char *full_cmd)
{
	int	pid;
	int	i;

	pipex->curr_cmd = ft_split(full_cmd, ' ');
	pipex->curr_cmd_executable = get_exec_full_path(pipex->curr_cmd[0],
			pipex->env_paths);
	pid = fork();
	if (pid == -1)
		handle_error(pipex, "Error forking");
	else if (pid == 0)
	{
		dup2(out_file_fd, STDOUT_FILENO);
		handle_execute(pipex);
	}
	else
	{
		i = 0;
		wait(NULL);
		free_2d(pipex->curr_cmd);
		free(pipex->curr_cmd_executable);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;
	int		in_file_fd;
	int		out_file_fd;

	parse_args(&pipex, argc, argv, envp);
	if (pipex.is_here_doc)
	{
		i = 3;
		out_file_fd = file_opener(&pipex, argv[argc -1], 0);
		handle_here_doc(&pipex, argc);
	}
	else
	{
		i = 2;
		in_file_fd = file_opener(&pipex, argv[1], 2);
		out_file_fd = file_opener(&pipex, argv[argc - 1], 1);
		dup2(in_file_fd, STDIN_FILENO);
	}
	while (i < argc - 2)
		child_proc(&pipex, argv[i++]);
	handle_last_cmd(&pipex, out_file_fd, argv[argc - 2]);
	free_2d(pipex.env_paths);
}
