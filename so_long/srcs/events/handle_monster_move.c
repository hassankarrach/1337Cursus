/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_monster_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:17:01 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 15:51:16 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <time.h>

static int	has_elapsed_1_seconds(time_t *last_time)
{
	time_t	current_time;

	current_time = time(NULL);
	if (current_time - *last_time >= 1)
	{
		*last_time = current_time;
		return (1);
	}
	return (0);
}

static void	handle_moving_left(t_mlx *mlx, int *monster_curr_x,
		int monster_curr_y)
{
	if (mlx->map.map_lines[monster_curr_y][(*monster_curr_x) - 1] == 'P')
	{
		mlx->map.player1.is_lost = 1;
		mlx->map.map_lines[monster_curr_y][*monster_curr_x] = '0';
		return ;
	}
	mlx->map.map_lines[monster_curr_y][*monster_curr_x] = '0';
	mlx->map.map_lines[monster_curr_y][*monster_curr_x - 1] = 'M';
}

static void	handle_moving_right(t_mlx *mlx, int *monster_curr_x,
		int monster_curr_y)
{
	if (mlx->map.map_lines[monster_curr_y][(*monster_curr_x) + 1] == 'P')
	{
		mlx->map.player1.is_lost = 1;
		mlx->map.map_lines[monster_curr_y][*monster_curr_x] = '0';
		return ;
	}
	mlx->map.map_lines[monster_curr_y][*monster_curr_x] = '0';
	mlx->map.map_lines[monster_curr_y][(*monster_curr_x) + 1] = 'M';
}

void	update_monster_position(t_mlx *mlx, int *curr_x, int curr_y)
{
	static int	reached_right_edge = 0;
	static int	reached_left_edge = 0;

	if (is_monster_move_valid(mlx, (*curr_x) - 1, curr_y) && !reached_left_edge)
	{
		handle_moving_left(mlx, curr_x, curr_y);
		if (!is_monster_move_valid(mlx, (*curr_x) - 2, curr_y))
		{
			reached_left_edge = 1;
			reached_right_edge = 0;
		}
		return ;
	}
	if (is_monster_move_valid(mlx, (*curr_x) + 1, curr_y)
		&& !reached_right_edge)
	{
		handle_moving_right(mlx, curr_x, curr_y);
		if (!is_monster_move_valid(mlx, (*curr_x) + 2, curr_y))
		{
			reached_right_edge = 1;
			reached_left_edge = 0;
		}
		(*curr_x)++;
		return ;
	}
}

void	handle_monster_move(t_mlx *mlx)
{
	static time_t	last_move_time = 0;
	int				i;
	int				x;
	int				y;

	i = 0;
	y = 0;
	if (has_elapsed_1_seconds(&last_move_time))
	{
		while (mlx->map.map_lines[y])
		{
			x = 0;
			while (mlx->map.map_lines[y][x])
			{
				if (mlx->map.map_lines[y][x] == 'M')
					update_monster_position(mlx, &x, y);
				x++;
			}
			y++;
		}
	}
}
