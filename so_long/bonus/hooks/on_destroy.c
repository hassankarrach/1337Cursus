/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:24:03 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/19 23:23:27 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_destroy(t_mlx *mlx)
{
	free_lines(&mlx->map);
	destroy_images(mlx);
	free_textures(mlx);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	if (mlx->map.player1.is_won)
		ft_printf("%sYOU WON!%s\n", GREEN, CLEAR);
	else if (mlx->map.player1.is_lost)
		ft_printf("%sYOU LOST!%s\n", RED, CLEAR);
	ft_printf("game Ended.\n");
	exit(0);
}
