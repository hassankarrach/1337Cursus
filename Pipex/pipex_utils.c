/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:33:40 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/09 04:09:35 by hkarrach         ###   ########.fr       */
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
	if (access(exec, X_OK) == 0)
		return (ft_strdup(exec));
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
	while (pipex->paths[i])
		free(pipex->paths[i++]);
	free(pipex->paths);
	free(pipex->first_cmd_executable);
	free(pipex->sec_cmd_executable);
}

void	error(t_pipex *pipex)
{
	perror("error ");
	freer(pipex);
	exit (EXIT_FAILURE);
}
