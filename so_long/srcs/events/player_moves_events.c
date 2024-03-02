/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_events.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:23:34 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 17:44:01 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	pos_to_content(t_mlx *mlx, int pos_x, int pos_y)
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

void	handle_next_move_exit(t_mlx *mlx)
{
	if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
		ft_printf("Grab all collectibles before exiting. !\n");
	else
		handle_game_exit_won(mlx);
}

void	update_positions(t_mlx *mlx, int next_pos_x, int next_pos_y)
{
	mlx->map.map_lines[next_pos_y][next_pos_x] = 'P';
	mlx->map.player1.player_pos_x = next_pos_x;
	mlx->map.player1.player_pos_y = next_pos_y;
	ft_printf("Number of Moves => %d.\n", mlx->map.player1.moves);
}
