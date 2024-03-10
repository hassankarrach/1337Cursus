/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:00:25 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/10 17:39:28 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char    **get_map_cpy(char **map)
{
	char    **map_cpy;
	int     map_rows;
	int     i;

	i = 0;
	map_rows = 0;
	while (map[i++])
		map_rows++;
	map_cpy = malloc(sizeof(char *) * (map_rows + 1));
	if (!map_cpy)
		return (NULL);
	i = 0;
	map[map_rows] = NULL;
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		i++;
	}
	return (map_cpy);
}

void    setting_the_map(char **map_lines, t_map *map)
{
    map->map_lines = map_lines;
    map->map_lines_cpy = get_map_cpy(map_lines);
    flood_fill_map_cpy(map->map_lines_cpy);
}
