/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:08:04 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/17 22:58:58 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_execute(t_pipex *pipex)
{
	if (!pipex->curr_cmd_executable)
		handle_error(pipex, "invalid command", EXIT_COMMAND_NOT_FOUND);
	if (execve(pipex->curr_cmd_executable, pipex->curr_cmd, pipex->envp) == -1)
		handle_error(pipex, "error executing the command", EXIT_FAILURE);
}

char	*get_env_paths(char **envp)
{
	char	*curr_env;
	int		i;

	i = 0;
	while (envp[i])
	{
		curr_env = envp[i];
		if (ft_strncmp(curr_env, "PATH=", 5) == 0)
			return (curr_env);
		i++;
	}
	return (NULL);
}

static char	*joiner(char *dir, char *executable)
{
	char	*dir_path;
	char	*res;

	dir_path = ft_strjoin(dir, "/");
	res = ft_strjoin(dir_path, executable);
	free(dir_path);
	return (res);
}

char	*get_exec_full_path(char *exec, char **paths)
{
	char	*exec_full_path;
	int		i;

	if (!exec)
		return (NULL);
	if (access(exec, X_OK) == 0)
		return (ft_strdup(exec));
	i = 0;
	if (!paths)
		return (NULL);
	if (exec && exec[0] == '/')
		return (NULL);
	while (paths[i])
	{
		exec_full_path = joiner(paths[i], exec);
		if (access(exec_full_path, X_OK) == 0)
			return (exec_full_path);
		free(exec_full_path);
		i++;
	}
	return (NULL);
}

void	free_2d(char **doub_ptr)
{
	int	i;

	i = 0;
	if (!doub_ptr)
		return ;
	while (doub_ptr[i])
		free (doub_ptr[i++]);
	free (doub_ptr);
}
