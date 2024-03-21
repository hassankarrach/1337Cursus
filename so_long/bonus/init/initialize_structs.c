/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:27:04 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/21 01:11:26 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void textures_struct_init(t_mlx *mlx)
{
	int	i;
	
	mlx->bg = NULL;
	mlx->wall = NULL;
	mlx->cat_moves = NULL;
	i = 0;
	while (i < 8)
		mlx->cat_left[i++] = NULL;
	i = 0;
	while (i < 8)
		mlx->cat_right[i++] = NULL;
	i = 0;
	while (i < 6)
		mlx->coin[i++] = NULL;
	mlx->exit[0] = NULL;
	mlx->exit[1] = NULL;
	i = 0;
	while (i < 4)
		mlx->cat_damaged[i++] = NULL;
	i = 0;
	while (i < 4)
		mlx->monster[i++] = NULL;
}

void	initialize_structs(t_mlx *mlx)
{
	textures_struct_init(mlx);
	mlx->map.collectibles = 0;
	mlx->map.height = 0;
	mlx->map.width = 0;
	mlx->map.player1.moves = 0;
	mlx->map.player1.colectibles_earned = 0;
	mlx->map.player1.player_pos_x = 0;
	mlx->map.player1.player_pos_y = 0;
	mlx->cat_direction = 1;
	mlx->map.player1.is_won = 0;
	mlx->map.player1.is_lost = 0;
	mlx->frames.exit_frame = 0;
	mlx->frames.cat_frame = 0;
	mlx->frames.coin_frame = 0;
	mlx->frames.monster_frame = 0;
	mlx->map.map_lines_cpy = NULL;
	mlx->map.map_lines_num = 0;
}
