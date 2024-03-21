/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:18 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/17 23:02:55 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./Libft/mini_libft.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_FILE_ERROR 3
# define EXIT_MEMORY_ERROR 4
# define EXIT_COMMAND_NOT_FOUND 127
# define EXIT_COMMAND_FAILED 126

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
	int		exit_status;
	int		i;
}	t_pipex;

char	*get_exec_full_path(char *exec, t_pipex *pipex);
char	*get_env_full_paths(char **envp);
void	error(t_pipex *pipex, int exit_status);
void	freer(t_pipex *pipex);

#endif