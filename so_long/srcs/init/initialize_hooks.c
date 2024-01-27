/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:24:38 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 05:24:48 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	initialize_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, 3, 1L << 1, &on_keypress, mlx);
	mlx_hook(mlx->win, 17, 0L, &on_destroy, mlx);
}
