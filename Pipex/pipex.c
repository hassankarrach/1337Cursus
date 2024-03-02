/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:16:40 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/02 10:47:06 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parse_arguments(int argc, char **argv, char **envp, t_pipex *pipex)
{
	char	*env_full_paths;

	if (argc != 5 || !envp)
	{
		perror("Invalid number of arguments or envp not found");
		exit(EXIT_FAILURE);
	}
	pipex->i = 0;
	pipex->envp = envp;
	env_full_paths = get_env_full_paths(envp) + 5;
	pipex->paths = ft_split(env_full_paths, ':');
	pipex->in_file = argv[1];
	pipex->first_cmd = ft_split(argv[2], ' ');
	pipex->sec_cmd = ft_split(argv[3], ' ');
	pipex->out_file = argv[4];
	pipex->first_cmd_executable = get_exec_full_path
		(pipex->first_cmd[0], pipex);
	pipex->sec_cmd_executable = get_exec_full_path(pipex->sec_cmd[0],
			pipex);
	if (!pipex->first_cmd_executable || !pipex->sec_cmd_executable)
		error(pipex);
	if (access(pipex->in_file, R_OK) == -1
		|| access(pipex->first_cmd_executable, F_OK) == -1
		|| access(pipex->sec_cmd_executable, F_OK) == -1)
		error(pipex);
}

static void	child_proc2(t_pipex *pipex, int fd[])
{
	int	out_file_fd;

	out_file_fd = open(pipex->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out_file_fd == -1)
		error(pipex);
	dup2(out_file_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	execve(pipex->sec_cmd_executable, pipex->sec_cmd, pipex->envp);
	error(pipex);
}

static void	child_proc(t_pipex *pipex, int fd[])
{
	int	in_file_fd;

	in_file_fd = open(pipex->in_file, O_RDONLY, 0777);
	if (in_file_fd == -1)
		error(pipex);
	dup2(in_file_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execve(pipex->first_cmd_executable, pipex->first_cmd, pipex->envp);
	error(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		fd[2];
	int		pid;

	parse_arguments(argc, argv, envp, &pipex);
	if (pipe(fd) == -1)
		error(&pipex);
	while (pipex.i < 2)
	{
		pid = fork();
		if (pid == -1)
			error(&pipex);
		if (pid == 0)
		{
			if (pipex.i == 0)
				child_proc(&pipex, fd);
			else if (pipex.i == 1)
				child_proc2(&pipex, fd);
		}
		pipex.i++;
		close(fd[1]);
		wait(NULL);
	}
	freer(&pipex);
}
