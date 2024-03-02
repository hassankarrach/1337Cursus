/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:09:57 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/29 08:24:18 by hkarrach         ###   ########.fr       */
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
	if (!(map_width > map_heigth))
		error_handle("Invalid Map pattern (the map is not rectangular!).");
	map->width = map_width * 60;
	map->height = map_heigth * 60;
}

static void	check_map_lines_length(char **lines)
{
	int	i;
	int	first_line_length;

	i = 0;
	first_line_length = custom_strlen(lines[0]);
	while (lines[i])
	{
		if (custom_strlen(lines[i]) != first_line_length)
			error_handle("Invalid Map: Uneven line lengths!");
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
			if (lines[y][x] == 'C')
				map->collectibles++;
			else if (lines[y][x] == 'P')
				p++;
			else if (lines[y][x] == 'E')
				e++;
			x++;
		}
		y++;
	}
	if (map->collectibles < 1 || e != 1 || p != 1)
		error_handle("Map Error: Duplicate or missing map components!");
}

static void	check_border_walls(char **lines)
{
	int	lines_count;
	int	border_walls;

	lines_count = 0;
	border_walls = 0;
	while (lines[lines_count])
	{
		if (is_border_wall(lines[lines_count]))
			border_walls++;
		lines_count++;
	}
	if (!is_border_wall(lines[0]) || !is_border_wall(lines[lines_count - 1])
		|| border_walls > 2)
		error_handle("Invalid Map Wall pattern.");
}

void	is_map_valid(char *file_path, t_map *map)
{
	int		fd;
	char	*curr_line;
	char	*full_lines;
	char	**lines_arr;

	full_lines = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_handle("can not open the map file.\n");
	if (!is_map_file_path_valid(file_path))
		error_handle("invalid path.\n");
	curr_line = get_next_line(fd);
	while (curr_line)
	{
		full_lines = ft_strjoin(full_lines, curr_line);
		free(curr_line);
		curr_line = get_next_line(fd);
	}
	lines_arr = ft_split(full_lines, '\n');
	map->map_lines = lines_arr;
	check_map_lines_length(lines_arr);
	check_map_component(lines_arr, map);
	check_border_walls(lines_arr);
	check_map_rect(map, lines_arr);
	free(full_lines);
}
