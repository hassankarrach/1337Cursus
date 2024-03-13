/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:26:37 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/11 15:30:43 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	initialize_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (1);
	mlx_get_screen_size(mlx->ptr, &mlx->screen_width, &mlx->screen_heigth);
	if (mlx->map.width > mlx->screen_width || mlx->map.height > (mlx->screen_heigth - 60))
		error_handle("Map is not playable.");
	mlx->win = mlx_new_window(mlx->ptr,
			mlx->map.width, mlx->map.height, "so long");
	if (!mlx->win)
		return (free(mlx->ptr), 1);
	return (1);
}
