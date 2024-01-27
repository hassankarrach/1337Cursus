/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_events.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:23:34 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 05:23:46 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static char	pos_to_content(t_mlx *mlx, int pos_x, int pos_y)
{
	return ((mlx->map.map_lines[pos_y / 60][pos_x / 60]));
}

int	is_next_move_valid(t_mlx *mlx, int next_x, int next_y)
{
	char	next_move_content;

	next_move_content = pos_to_content(mlx, next_x, next_y);
	if (next_move_content == '1')
		return (0);
	else
		return (1);
}

int	is_next_move_earn_clb(t_mlx *mlx, int next_x, int next_y)
{
	char	next_move_content;

	next_move_content = pos_to_content(mlx, next_x, next_y);
	if (next_move_content == 'C')
		return (1);
	else
		return (0);
}

int	is_next_move_exit(t_mlx *mlx, int next_x, int next_y)
{
	char	next_move_content;

	next_move_content = pos_to_content(mlx, next_x, next_y);
	if (next_move_content == 'E')
		return (1);
	else
		return (0);
}

int	is_next_move_enemy(t_mlx *mlx, int next_x, int next_y)
{
	char	next_move_content;

	next_move_content = pos_to_content(mlx, next_x, next_y);
	if (next_move_content == 'M')
		return (1);
	else
		return (0);
}

void	handle_next_move_exit(t_mlx *mlx)
{
	if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
	{
		ft_printf("complete clcs to exit!\n");
	}
	else
	{
		handle_game_exit_won(mlx);
	}
}
