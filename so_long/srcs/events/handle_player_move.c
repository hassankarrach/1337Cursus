/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:21:05 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 05:22:59 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	update_positions(t_mlx *mlx, int curr_pos_x, int curr_pos_y,
		int next_pos_x, int next_pos_y)
{
	mlx->map.map_lines[curr_pos_y][curr_pos_x] = '0';
	mlx->map.map_lines[next_pos_y][next_pos_x] = 'P';
	mlx->map.player1.player_pos_x = next_pos_x;
	mlx->map.player1.player_pos_y = next_pos_y;
	ft_printf("Number of Moves : %d.\n", mlx->map.player1.moves);
	ft_printf("%d/%d collectibles you've earned.\n",
		mlx->map.player1.colectibles_earned, mlx->map.collectibles);
}

static void	handle_move_up(t_mlx *mlx, int curr_x, int curr_y)
{
	if (is_next_move_valid(mlx, curr_x, curr_y - 60)
		&& !mlx->map.player1.is_lost)
	{
		if (is_next_move_earn_clb(mlx, curr_x, curr_y - 60))
			mlx->map.player1.colectibles_earned++;
		if (is_next_move_enemy(mlx, curr_x, curr_y - 60))
			handle_game_lose(mlx);
		else if (is_next_move_exit(mlx, curr_x, curr_y - 60))
		{
			if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
			{
				ft_printf("complete clcs to exit!\n");
				return ;
			}
			else
				handle_game_exit_won(mlx);
		}
		mlx->map.player1.moves++;
		update_positions(mlx, curr_x / 60, curr_y / 60, curr_x / 60, (curr_y
				- 60) / 60);
	}
}

static void	handle_move_right(t_mlx *mlx, int curr_x, int curr_y)
{
	if (is_next_move_valid(mlx, curr_x + 60, curr_y)
		&& !mlx->map.player1.is_lost)
	{
		if (is_next_move_earn_clb(mlx, curr_x + 60, curr_y))
			mlx->map.player1.colectibles_earned++;
		if (is_next_move_enemy(mlx, curr_x + 60, curr_y))
			handle_game_lose(mlx);
		else if (is_next_move_exit(mlx, curr_x + 60, curr_y))
		{
			if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
			{
				ft_printf("complete clcs to exit!\n");
				return ;
			}
			else
				handle_game_exit_won(mlx);
		}
		mlx->map.player1.moves++;
		mlx->cat_direction = 1;
		update_positions(mlx, curr_x / 60, curr_y / 60, (curr_x + 60) / 60,
			curr_y / 60);
	}
}

static void	handle_move_left(t_mlx *mlx, int curr_x, int curr_y)
{
	if (is_next_move_valid(mlx, curr_x - 60, curr_y)
		&& !mlx->map.player1.is_lost)
	{
		if (is_next_move_earn_clb(mlx, curr_x - 60, curr_y))
			mlx->map.player1.colectibles_earned++;
		if (is_next_move_enemy(mlx, curr_x - 60, curr_y))
			handle_game_lose(mlx);
		else if (is_next_move_exit(mlx, curr_x - 60, curr_y))
		{
			if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
			{
				ft_printf("complete clcs to exit!\n");
				return ;
			}
			else
				handle_game_exit_won(mlx);
		}
		mlx->map.player1.moves++;
		mlx->cat_direction = 0;
		update_positions(mlx, curr_x / 60, curr_y / 60, (curr_x - 60) / 60,
			curr_y / 60);
	}
}

static void	handle_move_down(t_mlx *mlx, int curr_x, int curr_y)
{
	if (is_next_move_valid(mlx, curr_x, curr_y + 60)
		&& !mlx->map.player1.is_lost)
	{
		if (is_next_move_earn_clb(mlx, curr_x, curr_y + 60))
			mlx->map.player1.colectibles_earned++;
		if (is_next_move_enemy(mlx, curr_x, curr_y + 60))
			handle_game_lose(mlx);
		else if (is_next_move_exit(mlx, curr_x, curr_y + 60))
		{
			if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
			{
				ft_printf("complete clcs to exit!\n");
				return ;
			}
			else
				handle_game_exit_won(mlx);
		}
		mlx->map.player1.moves++;
		update_positions(mlx, curr_x / 60, curr_y / 60, curr_x / 60, (curr_y
				+ 60) / 60);
	}
}

void	handle_player_move(t_mlx *mlx, char move_direction)
{
	int	curr_x;
	int	curr_y;

	curr_x = mlx->map.player1.player_pos_x;
	curr_y = mlx->map.player1.player_pos_y;
	if (move_direction == 'u')
		handle_move_up(mlx, curr_x, curr_y);
	else if (move_direction == 'l')
		handle_move_left(mlx, curr_x, curr_y);
	else if (move_direction == 'r')
		handle_move_right(mlx, curr_x, curr_y);
	else if (move_direction == 'd')
		handle_move_down(mlx, curr_x, curr_y);
}
