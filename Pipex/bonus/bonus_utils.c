/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:08:04 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/02 14:34:09 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_execute(t_pipex *pipex)
{
	if (!pipex->curr_cmd_executable)
		handle_error(pipex, "invalid command");
	if (execve(pipex->curr_cmd_executable, pipex->curr_cmd, pipex->envp) == -1)
		handle_error(pipex, "error executing the command");
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

	if (access(exec, F_OK) == 0)
		return (ft_strdup(exec));
	i = 0;
	while (paths[i])
	{
		exec_full_path = joiner(paths[i], exec);
		if (access(exec_full_path, F_OK) == 0)
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
	while (doub_ptr[i])
		free (doub_ptr[i++]);
	free (doub_ptr);
}
