/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:38:39 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/17 23:04:52 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/mini_libft.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_FILE_ERROR 3
# define EXIT_MEMORY_ERROR 4
# define EXIT_COMMAND_NOT_FOUND 127
# define EXIT_COMMAND_FAILED 126

typedef struct s_pipex
{
	char	**env_paths;
	char	**envp;
	char	**curr_cmd;
	char	*curr_cmd_executable;
	char	*limiter;
	int		is_here_doc;
	int		cmds_count;
	int		i;
}	t_pipex;

char	*get_env_paths(char **envp);
char	*get_exec_full_path(char *exec, char **paths);
void	handle_execute(t_pipex *pipex);
void	handle_here_doc(t_pipex *pipex, int argc);
void	handle_error(t_pipex *pipex, char *err_txt, int EXIT_STATUS);
void	free_2d(char **doub_ptr);

#endif