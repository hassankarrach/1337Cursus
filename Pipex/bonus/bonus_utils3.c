/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zero <zero@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:37:52 by zero              #+#    #+#             */
/*   Updated: 2024/03/25 04:36:25 by zero             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	handle_last_cmd(t_pipex *pipex, int out_file_fd, char *full_cmd)
{
	int	pid;

	pipex->curr_cmd = ft_split(full_cmd, ' ');
	pipex->curr_cmd_executable = get_exec_full_path(pipex->curr_cmd[0],
			pipex->env_paths);
	pid = fork();
	pipex->last_cmd_pid = pid;
	if (pid == -1)
		handle_error(pipex, "Error forking", EXIT_FAILURE);
	else if (pid == 0)
	{
		dup2(out_file_fd, STDOUT_FILENO);
		close(out_file_fd);
		handle_execute(pipex);
	}
	else
	{
		free_2d(pipex->curr_cmd);
		free(pipex->curr_cmd_executable);
		close(STDIN_FILENO);
	}
}
static void	child_proc(t_pipex *pipex, char *full_cmd)
{
	int	pid;
	int	fd[2];

	pipex->curr_cmd = ft_split(full_cmd, ' ');
	pipex->curr_cmd_executable = get_exec_full_path(pipex->curr_cmd[0],
			pipex->env_paths);
	if (pipe(fd) == -1)
		handle_error(pipex, "Error creating pipe", EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		handle_error(pipex, "Error forking", EXIT_FAILURE);
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
		close(fd[0]);
		free_2d(pipex->curr_cmd);
		free(pipex->curr_cmd_executable);
	}
}

static void waiting(t_pipex *pipex, int argc)
{
	// int tmp_exit_status;
	// int	extracted_exit_status;
		// extracted_exit_status = (tmp_exit_status >> 8) & 0xFF;
		(void)argc;
    
	int cmds_count = pipex->cmds_count;
	printf("%d\n", cmds_count);
	// while (cmds_count--)
	// {
	// 	wait (NULL);
	// }
}

void piping_and_clear(t_pipex *pipex, char **argv, int argc, int *out_file_fd)
{
    while (pipex->i < argc - 2)
	    child_proc(pipex, argv[pipex->i++]);
	handle_last_cmd(pipex, *out_file_fd, argv[argc - 2]);
    waiting(pipex, argc);
	free_2d(pipex->env_paths);
}