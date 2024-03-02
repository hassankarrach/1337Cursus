/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:26:54 by hkarrach          #+#    #+#             */
/*   Updated: 2024/02/29 15:21:43 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_error(t_pipex *pipex, char *err_txt)
{
	perror(err_txt);
	if (pipex->env_paths)
		free_2d(pipex->env_paths);
	if (pipex->curr_cmd)
		free_2d(pipex->curr_cmd);
	if (pipex->curr_cmd_executable)
		free(pipex->curr_cmd_executable);
	exit(EXIT_FAILURE);
}

static char	*get_next_line(t_pipex *pipex)
{
	int		readed;
	char	*buff;
	char	*line;
	int		pipes_number;

	line = NULL;
	pipes_number = pipex->cmds_count - 1;
	buff = malloc(2 * sizeof(char));
	if (!buff)
		return (0);
	buff[1] = '\0';
	while (pipes_number--)
		write(STDOUT_FILENO, "pipe ", 5);
	write(STDOUT_FILENO, "heredoc> ", 9);
	readed = read(STDIN_FILENO, buff, 1);
	while (readed > 0)
	{
		if (buff[0] == '\n')
			break ;
		line = ft_gnl_strjoin(line, buff);
		readed = read(STDIN_FILENO, buff, 1);
	}
	free(buff);
	line = ft_gnl_strjoin(line, "\n");
	return (line);
}

static void	handle_parent_proc(int fd[])
{
	wait(NULL);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
}

static void	child_proc(t_pipex *pipex, int fd[])
{
	char	*line;

	close(fd[0]);
	line = get_next_line(pipex);
	while (line)
	{
		if (ft_strncmp(line, pipex->limiter,
				ft_strlen(pipex->limiter)) == 0)
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(pipex);
	}
	free(line);
	if (pipex->env_paths)
		free_2d(pipex->env_paths);
	if (pipex->curr_cmd)
		free_2d(pipex->curr_cmd);
	if (pipex->curr_cmd_executable)
		free(pipex->curr_cmd_executable);
	exit(EXIT_SUCCESS);
}

void	handle_here_doc(t_pipex *pipex, int argc)
{
	int		pid;
	int		fd[2];

	if (argc >= 6)
	{
		if (pipe(fd) == -1)
			handle_error(pipex, "Error creating pipe");
		pid = fork();
		if (pid == 0)
			child_proc(pipex, fd);
		else
			handle_parent_proc(fd);
	}
	else
		handle_error(pipex, "incorrect number of arguments");
}
