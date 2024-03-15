/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:09:57 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/15 17:44:52 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_map_rect(t_map *map, char **lines)
{
	int	map_width;
	int	map_heigth;

	map_heigth = 0;
	map_width = 0;
	while (lines[map_heigth])
		map_heigth++;
	while (lines[0][map_width])
		map_width++;
	map->width = map_width * 60;
	map->height = map_heigth * 60;
}

static void	check_map_lines_length(char **lines, t_map *map)
{
	int	i;
	int	first_line_length;
	int	line_len;

	i = 0;
	first_line_length = custom_strlen(lines[0]);
	while (lines[i])
	{
		line_len = custom_strlen(lines[i]);
		if (custom_strlen(lines[i]) != first_line_length
			|| !is_line_components_valid(lines[i])
			|| lines[i][0] != '1' || lines[i][line_len - 1] != '1')
		{
			free_lines(map);
			error_handle("Invalid Map pattern component.");
		}
		i++;
	}
}

static void	check_map_component(char **lines, t_map *map)
{
	int	x;
	int	y;
	int	e;
	int	p;

	y = 0;
	e = 0;
	p = 0;
	while (lines[y])
	{
		x = 0;
		while (lines[y][x])
		{
			if (lines[y][x] == 'C' && check_accessibility(map, x, y))
				map->collectibles++;
			else if (lines[y][x] == 'P')
				p++;
			else if (lines[y][x] == 'E' && check_accessibility(map, x, y))
				e++;
			x++;
		}
		y++;
	}
	if (map->collectibles < 1 || e != 1 || p != 1)
		free_and_error(map, "Map Error: Duplicate or missing map components!");
}

static void	check_border_walls(char **lines)
{
	int	lines_count;
	int	border_walls;
	int	line_len;

	lines_count = 0;
	border_walls = 0;
	line_len = 0;
	while (lines[lines_count])
	{
		line_len = gnl_strlen(lines[lines_count]);
		if (lines[lines_count][0] != '1'
			|| lines[lines_count][line_len - 1] != '1')
			error_handle("Invalid Map Wall pattern.");
		if (is_border_wall(lines[lines_count]))
			border_walls++;
		lines_count++;
	}
	if (!is_border_wall(lines[0]) || !is_border_wall(lines[lines_count - 1]))
		error_handle("Invalid Map Wall pattern.");
}

void	is_map_valid(char *file_path, t_map *map)
{
	int		fd;
	char	*curr_line;
	char	*full_lines;
	char	**lines_arr;

	full_lines = NULL;
	if (!is_map_file_path_valid(file_path))
		error_handle("invalid path.\n");
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_handle("can not open the map file.\n");
	curr_line = get_next_line(fd);
	while (curr_line)
	{
		full_lines = ft_strjoin(full_lines, curr_line);
		free(curr_line);
		curr_line = get_next_line(fd);
	}
	lines_arr = ft_split(full_lines, '\n');
	free(full_lines);
	setting_the_map(lines_arr, map);
	check_map_lines_length(lines_arr, map);
	check_map_component(lines_arr, map);
	check_border_walls(lines_arr);
	check_map_rect(map, lines_arr);
}
