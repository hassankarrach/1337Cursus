/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:18 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/02 14:13:20 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "./Libft/mini_libft.h"

typedef struct s_pipex
{
	char	*in_file;
	char	*out_file;
	char	**first_cmd;
	char	**sec_cmd;
	char	*first_cmd_executable;
	char	*sec_cmd_executable;
	char	**envp;
	char	**paths;
	int		i;
}	t_pipex;

char	*get_exec_full_path(char *exec, t_pipex *pipex);
char	*get_env_full_paths(char **envp);
void	error(t_pipex *pipex);
void	freer(t_pipex *pipex);

#endif