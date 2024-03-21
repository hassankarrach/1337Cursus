/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:09:57 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/21 03:51:04 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_map_rect(t_mlx *mlx)
{
	int	map_width;
	int	map_heigth;

	map_heigth = 0;
	map_width = 0;
	while (mlx->map.map_lines[map_heigth])
		map_heigth++;
	while (mlx->map.map_lines[0][map_width])
		map_width++;
	mlx->map.width = map_width * 60;
	mlx->map.height = map_heigth * 60;
}

static void	check_map_lines_length(t_mlx *mlx)
{
	int	i;
	int	first_line_length;

	if (!mlx->map.map_lines)
		error_handle(mlx, "Map is empty.", 0);
	i = 0;
	first_line_length = custom_strlen(mlx->map.map_lines[0]);
	while (mlx->map.map_lines[i])
	{
		if (custom_strlen(mlx->map.map_lines[i]) != first_line_length
			|| !is_line_components_valid(mlx->map.map_lines[i]))
			error_handle(mlx, "Invalid Map.", 1);
		i++;
	}
}

static void	check_map_component(t_mlx *mlx)
{
	int	x;
	int	y;
	int	e;
	int	p;

	y = 0;
	e = 0;
	p = 0;
	while (mlx->map.map_lines[y])
	{
		x = 0;
		while (mlx->map.map_lines[y][x])
		{
			if (mlx->map.map_lines[y][x] == 'C' && check_accessibility(mlx, x, y))
				mlx->map.collectibles++;
			else if (mlx->map.map_lines[y][x] == 'P')
				p++;
			else if (mlx->map.map_lines[y][x] == 'E' && check_accessibility(mlx, x, y))
				e++;
			x++;
		}
		y++;
	}
	if (mlx->map.collectibles < 1 || e != 1 || p != 1)
		error_handle(mlx, "Map Error: Duplicate or missing map components!", 1);
}

static void	check_border_walls(t_mlx *mlx)
{
	int	lines_count;
	int	border_walls;

	lines_count = 0;
	border_walls = 0;
	while (mlx->map.map_lines[lines_count])
	{
		if (is_border_wall(mlx->map.map_lines[lines_count]))
			border_walls++;
		lines_count++;
	}
	if (!is_border_wall(mlx->map.map_lines[0]) || !is_border_wall(mlx->map.map_lines[lines_count - 1]))
		error_handle(mlx, "Invalid Map Wall pattern.", 1);
}

void	is_map_valid(char *file_path, t_mlx *mlx)
{
	int		fd;
	char	*curr_line;
	char	*full_lines;
	char	**lines_arr;

	full_lines = NULL;
	if (!is_map_file_path_valid(file_path))
		error_handle(mlx, "invalid path.\n", 0);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_handle(mlx, "can not open the map file.\n", 0);
	curr_line = get_next_line(fd);
	while (curr_line)
	{
		is_line_valid(mlx, curr_line, full_lines);
		full_lines = ft_strjoin(full_lines, curr_line);
		free(curr_line);
		curr_line = get_next_line(fd);
	}
	lines_arr = ft_split(full_lines, '\n');
	setting_the_map(lines_arr, &mlx->map, full_lines);
	check_map_lines_length(mlx);
	check_map_component(mlx);
	check_border_walls(mlx);
	check_map_rect(mlx);
}
