/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zero <zero@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:16:40 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/24 20:28:30 by zero             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parse_arguments(int argc, char **argv, char **envp, t_pipex *pipex)
{
	char	*env_full_paths;

	if (argc != 5)
	{
		perror("Invalid number of arguments.");
		exit(EXIT_FAILURE);
	}
	pipex->i = 0;
	pipex->envp = envp;
	env_full_paths = get_env_full_paths(envp);
	if (env_full_paths)
		pipex->paths = ft_split(env_full_paths + 5, ':');
	else
		pipex->paths = NULL;
	pipex->in_file = argv[1];
	pipex->first_cmd = ft_split(argv[2], ' ');
	pipex->sec_cmd = ft_split(argv[3], ' ');
	pipex->out_file = argv[4];
	pipex->first_cmd_executable = get_exec_full_path
		(pipex->first_cmd[0], pipex);
	pipex->sec_cmd_executable = get_exec_full_path(pipex->sec_cmd[0],
			pipex);
	pipex->exit_status = 0;
}

static void	child_proc2(t_pipex *pipex, int fd[])
{
	int	out_file_fd;

	out_file_fd = open(pipex->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (out_file_fd == -1)
		error(pipex, EXIT_FILE_ERROR);
	if (!pipex->sec_cmd_executable)
		error(pipex, EXIT_COMMAND_NOT_FOUND);
	close(fd[1]);
	dup2(out_file_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(out_file_fd);
	close(fd[0]);
	execve(pipex->sec_cmd_executable, pipex->sec_cmd, pipex->envp);
	error(pipex, EXIT_COMMAND_FAILED);
}

static void	child_proc(t_pipex *pipex, int fd[])
{
	int	in_file_fd;

	in_file_fd = open(pipex->in_file, O_RDONLY, 0666);
	if (in_file_fd == -1)
		error(pipex, EXIT_FILE_ERROR);
	if( !pipex->first_cmd_executable)
		error(pipex, EXIT_FAILURE);
	dup2(in_file_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(in_file_fd);
	execve(pipex->first_cmd_executable, pipex->first_cmd, pipex->envp);
	error(pipex, EXIT_COMMAND_FAILED);
}

static void	close_and_wait(t_pipex *pipex, int (*fd)[2])
{
	int	i;
	int tmp_exit_status;
	int	extracted_exit_status;

	i = 0;
	close((*fd)[1]);
	close((*fd)[0]);
	while (i++ < 2)
	{
		wait(&tmp_exit_status);
		extracted_exit_status = (tmp_exit_status >> 8) & 0xFF;
		if (i == 2)
			pipex->exit_status = extracted_exit_status;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		fd[2];
	int		pid;

	parse_arguments(argc, argv, envp, &pipex);
	if (pipe(fd) == -1)
		error(&pipex, EXIT_FAILURE);
	while (pipex.i < 2)
	{
		pid = fork();
		if (pid == -1)
			error(&pipex, EXIT_FAILURE);
		if (pid == 0)
		{
			if (pipex.i == 0)
				child_proc(&pipex, fd);
			else
				child_proc2(&pipex, fd);
		}
		pipex.i++;
	}
	close_and_wait(&pipex, &fd);
	freer(&pipex);
	exit(pipex.exit_status);
}
