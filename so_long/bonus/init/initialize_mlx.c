/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:26:37 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/21 03:49:33 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
		write(2, "Error.", 6);
		exit(1);
	}
	mlx_get_screen_size(mlx->ptr, &mlx->screen_width, &mlx->screen_heigth);
}

void	initialize_mlx_window(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, mlx->map.width, mlx->map.height + 60,
			"so long");
	if (!mlx->win)
	{
		free(mlx->ptr);
		write(2, "Error.", 6);
		exit (1);
	}
}
