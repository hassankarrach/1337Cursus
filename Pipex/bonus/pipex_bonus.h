/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:39 by hkarrach          #+#    #+#             */
/*   Updated: 2024/02/26 11:19:36 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../Libft/mini_libft.h"

typedef struct s_pipex
{
	char	**env_paths;
	char	**envp;
	char	**curr_cmd;
	char	*curr_cmd_executable;
	char	*limiter;
	int		is_here_doc;
	int		cmds_count;
}	t_pipex;

char	*get_env_paths(char **envp);
char	*get_exec_full_path(char *exec, char **paths);
void	handle_execute(t_pipex *pipex);
void	handle_here_doc(t_pipex *pipex, int argc);
void	handle_error(t_pipex *pipex, char *err_txt);
void	free_2d(char **doub_ptr);

#endif