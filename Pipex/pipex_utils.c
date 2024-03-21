/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:33:40 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/18 03:13:09 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

char	*get_env_full_paths(char **envp)
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
	free (dir_path);
	return (res);
}

char	*get_exec_full_path(char *exec, t_pipex *pipex)
{
	char	*exec_full_path;
	int		i;

	i = 0;
	if (!exec)
		return (NULL);
	if (access(exec, X_OK) == 0)
		return (ft_strdup(exec));
	if (!pipex->paths)
		return (NULL);
	if (exec && (exec[0] == '/' || exec[0] == '.'))
		return (NULL);
	while (pipex->paths[i])
	{
		exec_full_path = joiner(pipex->paths[i], exec);
		if (access(exec_full_path, X_OK) == 0)
			return (exec_full_path);
		free(exec_full_path);
		i++;
	}
	return (NULL);
}

void	freer(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->first_cmd[i])
		free(pipex->first_cmd[i++]);
	free(pipex->first_cmd);
	i = 0;
	while (pipex->sec_cmd[i])
		free(pipex->sec_cmd[i++]);
	free(pipex->sec_cmd);
	i = 0;
	if (pipex->paths)
	{
		while (pipex->paths[i])
			free(pipex->paths[i++]);
		free(pipex->paths);
	}
	if (pipex->first_cmd_executable)
		free(pipex->first_cmd_executable);
	if (pipex->sec_cmd_executable)
		free(pipex->sec_cmd_executable);
}

void	error(t_pipex *pipex, int exit_status)
{
	perror("error ");
	freer(pipex);
	exit (exit_status);
}
