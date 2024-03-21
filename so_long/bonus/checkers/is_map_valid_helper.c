/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:07:04 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/21 01:36:04 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_map_file_path_valid(char *file_path)
{
	char	*file_path_ext;

	file_path_ext = ft_strrchr(file_path, '.');
	if (!file_path_ext)
		return 0;
	if ( ft_strlen(file_path_ext) != 4)
		return (0);
	return (!ft_strncmp(file_path_ext, ".ber", 4));
}

int	custom_strlen(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] != '\n')
			len++;
		i++;
	}
	return (len);
}

int	is_line_components_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'M' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_border_wall(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (line[--i] == '\n')
		i--;
	while (i >= 0)
	{
		if (line[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

void	is_line_valid(t_mlx *mlx, char *curr_line, char *full_lines)
{
	int	line_len;
	int is_out_of_screen;

	is_out_of_screen = 0;
	is_line_components_valid(curr_line);
	line_len = custom_strlen(curr_line);
	mlx->map.map_lines_num++;
	if (line_len > (mlx->screen_width / 60)
		|| mlx->map.map_lines_num > (mlx->screen_heigth / 60 - 1))
		is_out_of_screen = 1;
	if (curr_line[0] != '1' || curr_line[line_len - 1] != '1' || is_out_of_screen)
	{
		free(curr_line);
		free(full_lines);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		if (is_out_of_screen)
			ft_printf("%sMap is out of screen.%s\n", RED, CLEAR);
		else
			ft_printf("%sinvalid map line.%s\n", RED, CLEAR);
		exit(1);
	}
}
