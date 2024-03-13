/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_helper2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:14:57 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/12 04:05:09 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_player_pos(char **map_cpy, char flag)
{
	int	y;
	int	x;

	y = 0;
	while (map_cpy[y])
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == 'P')
			{
				if (flag == 'y')
					return (y);
				else if (flag == 'x')
					return (x);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

void	f_fill(char **map_cpy, t_pos map_size, int start_y, int start_x)
{
	if (start_y < 0 || start_x < 0 || start_y >= map_size.y
		|| start_x >= map_size.x)
		return ;
	if (map_cpy[start_y][start_x] == 'F' ||
			(map_cpy[start_y][start_x] != '0'
			&& map_cpy[start_y][start_x] != 'P' &&
			map_cpy[start_y][start_x] != 'E'
			&& map_cpy[start_y][start_x] != 'C'))
		return ;
	map_cpy[start_y][start_x] = 'F';
	f_fill(map_cpy, map_size, start_y -1, start_x);
	f_fill(map_cpy, map_size, start_y +1, start_x);
	f_fill(map_cpy, map_size, start_y, start_x - 1);
	f_fill(map_cpy, map_size, start_y, start_x + 1);
}

void	flood_fill_map_cpy(char	**map_cpy)
{
	t_pos	map_size;
	t_pos	begin;

	map_size.x = ft_strlen(map_cpy[0]);
	map_size.y = 0;
	while (map_cpy[map_size.y] != NULL)
		map_size.y++;
	begin.x = get_player_pos(map_cpy, 'x');
	begin.y = get_player_pos(map_cpy, 'y');
	f_fill(map_cpy, map_size, begin.y, begin.x);
}

int	check_accessibility(t_map *map, int clc_x, int clc_y)
{
	if (map->map_lines_cpy[clc_y][clc_x] == 'F')
		return (1);
	else
		error_handle("unreachable component!");
	return (0);
}
