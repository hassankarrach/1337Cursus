/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:27:04 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 05:27:05 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	initialize_structs(t_mlx *mlx)
{
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
	mlx->exit_frame = 0;
}