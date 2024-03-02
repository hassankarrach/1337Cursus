/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:26:37 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/28 11:17:35 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	initialize_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (1);
	mlx->win = mlx_new_window(mlx->ptr,
			mlx->map.width, mlx->map.height, "so long");
	if (!mlx->win)
		return (free(mlx->ptr), 1);
	return (1);
}
