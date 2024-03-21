/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:25:06 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/18 16:23:30 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	texture_attach(t_mlx *mlx, t_img *texture, int pos_x, int pos_y)
{
	texture->x_pos = pos_x * 60;
	texture->y_pos = pos_y * 60;
	return (mlx_put_image_to_window(mlx->ptr, mlx->win, texture->img_data,
			texture->x_pos, texture->y_pos));
}

static void	map_parsing_player(t_mlx *mlx, int pos_x, int pos_y)
{
	mlx->map.player1.player_pos_x = pos_x * 60;
	mlx->map.player1.player_pos_y = pos_y * 60;
	if (mlx->map.player1.is_lost)
		texture_attach(mlx, mlx->cat_damaged, pos_x, pos_y);
	else if (mlx->map.player1.is_won)
		texture_attach(mlx, mlx->exit[1], pos_x, pos_y);
	else
	{
		if (mlx->cat_direction)
			texture_attach(mlx, mlx->cat_right, pos_x, pos_y);
		else
			texture_attach(mlx, mlx->cat_left, pos_x, pos_y);
	}
}

static void	map_parsing(t_mlx *mlx, char c, int pos_x, int pos_y)
{
	if (c == '1')
		texture_attach(mlx, mlx->wall, pos_x, pos_y);
	else if (c == '0')
		texture_attach(mlx, mlx->bg, pos_x, pos_y);
	else if (c == 'C')
		texture_attach(mlx, mlx->coin, pos_x, pos_y);
	else if (c == 'E')
	{
		if (mlx->map.collectibles == mlx->map.player1.colectibles_earned)
			texture_attach(mlx, mlx->exit[1], pos_x, pos_y);
		else
			texture_attach(mlx, mlx->exit[0], pos_x, pos_y);
	}
	else if (c == 'P')
	{
		map_parsing_player(mlx, pos_x, pos_y);
	}
}

void	initialize_map(t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	mlx_clear_window(mlx->ptr, mlx->win);
	pos_y = 0;
	while (mlx->map.map_lines[pos_y])
	{
		pos_x = 0;
		while (mlx->map.map_lines[pos_y][pos_x])
		{
			map_parsing(mlx, mlx->map.map_lines[pos_y][pos_x], pos_x, pos_y);
			pos_x++;
		}
		pos_y++;
	}
	if (mlx->map.player1.is_lost)
		on_destroy(mlx);
	if (mlx->map.player1.is_won)
		on_destroy(mlx);
}
