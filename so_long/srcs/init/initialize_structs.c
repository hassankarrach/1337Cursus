/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:27:04 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/20 03:06:11 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void textures_struct_init(t_mlx *mlx)
{
	mlx->bg = NULL;
	mlx->wall = NULL;
	mlx->cat_left = NULL;
	mlx->cat_right =NULL;
	mlx->exit[0] = NULL;
	mlx->exit[1] = NULL;
	mlx->coin = NULL;
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
	mlx->map.map_lines_cpy = NULL;
	mlx->map.map_lines_num = 0;
}
