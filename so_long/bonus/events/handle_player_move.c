/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:21:05 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/10 18:54:27 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handle_move_up(t_mlx *mlx, int curr_x, int curr_y)
{
	if (is_next_move_valid(mlx, curr_x, curr_y - 60)
		&& !mlx->map.player1.is_lost)
	{
		if (pos_to_content(mlx, curr_x, curr_y - 60) == 'C')
			mlx->map.player1.colectibles_earned++;
		if (pos_to_content(mlx, curr_x, curr_y - 60) == 'M')
			handle_game_lose(mlx);
		else if (pos_to_content(mlx, curr_x, curr_y - 60) == 'E')
		{
			if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
			{
				ft_printf("Grab all collectibles before exiting.\n");
				return ;
			}
			else
				handle_game_exit_won(mlx);
		}
		mlx->map.player1.moves++;
		mlx->map.map_lines[curr_y / 60][curr_x / 60] = '0';
		update_positions(mlx, curr_x / 60, (curr_y - 60) / 60);
	}
}

static void	handle_move_right(t_mlx *mlx, int curr_x, int curr_y)
{
	if (is_next_move_valid(mlx, curr_x + 60, curr_y)
		&& !mlx->map.player1.is_lost)
	{
		if (pos_to_content(mlx, curr_x + 60, curr_y) == 'C')
			mlx->map.player1.colectibles_earned++;
		if (pos_to_content(mlx, curr_x + 60, curr_y) == 'M')
			handle_game_lose(mlx);
		else if (pos_to_content(mlx, curr_x + 60, curr_y) == 'E')
		{
			if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
			{
				ft_printf("Grab all collectibles before exiting.\n");
				return ;
			}
			else
				handle_game_exit_won(mlx);
		}
		mlx->map.player1.moves++;
		mlx->cat_direction = 1;
		mlx->map.map_lines[curr_y / 60][curr_x / 60] = '0';
		update_positions(mlx, (curr_x + 60) / 60, curr_y / 60);
	}
}

static void	handle_move_left(t_mlx *mlx, int curr_x, int curr_y)
{
	if (is_next_move_valid(mlx, curr_x - 60, curr_y)
		&& !mlx->map.player1.is_lost)
	{
		if (pos_to_content(mlx, curr_x - 60, curr_y) == 'C')
			mlx->map.player1.colectibles_earned++;
		if (pos_to_content(mlx, curr_x - 60, curr_y) == 'M')
			handle_game_lose(mlx);
		else if (pos_to_content(mlx, curr_x - 60, curr_y) == 'E')
		{
			if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
			{
				ft_printf("Grab all collectibles before exiting.\n");
				return ;
			}
			else
				handle_game_exit_won(mlx);
		}
		mlx->map.player1.moves++;
		mlx->cat_direction = 0;
		mlx->map.map_lines[curr_y / 60][curr_x / 60] = '0';
		update_positions(mlx, (curr_x - 60) / 60, curr_y / 60);
	}
}

static void	handle_move_down(t_mlx *mlx, int curr_x, int curr_y)
{
	if (is_next_move_valid(mlx, curr_x, curr_y + 60)
		&& !mlx->map.player1.is_lost)
	{
		if (pos_to_content(mlx, curr_x, curr_y + 60) == 'C')
			mlx->map.player1.colectibles_earned++;
		if (pos_to_content(mlx, curr_x, curr_y + 60) == 'M')
			handle_game_lose(mlx);
		else if (pos_to_content(mlx, curr_x, curr_y + 60) == 'E')
		{
			if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
			{
				ft_printf("Grab all collectibles before exiting.\n");
				return ;
			}
			else
				handle_game_exit_won(mlx);
		}
		mlx->map.player1.moves++;
		mlx->map.map_lines[curr_y / 60][curr_x / 60] = '0';
		update_positions(mlx, curr_x / 60, (curr_y + 60) / 60);
	}
}

void	handle_player_move(t_mlx *mlx, char move_direction)
{
	int	curr_x;
	int	curr_y;

	curr_x = mlx->map.player1.player_pos_x;
	curr_y = mlx->map.player1.player_pos_y;
	if (move_direction == 'u' && !mlx->map.player1.is_won)
		handle_move_up(mlx, curr_x, curr_y);
	else if (move_direction == 'l' && !mlx->map.player1.is_won)
		handle_move_left(mlx, curr_x, curr_y);
	else if (move_direction == 'r' && !mlx->map.player1.is_won)
		handle_move_right(mlx, curr_x, curr_y);
	else if (move_direction == 'd' && !mlx->map.player1.is_won)
		handle_move_down(mlx, curr_x, curr_y);
}
