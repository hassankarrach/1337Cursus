/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:15:40 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 17:24:41 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_lines(t_mlx *mlx)
{
	char	**lines;
	int		i;

	lines = mlx->map.map_lines;
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

void	destroy_images(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->bg->img_data);
	mlx_destroy_image(mlx->ptr, mlx->wall->img_data);
	mlx_destroy_image(mlx->ptr, mlx->you_lose->img_data);
	mlx_destroy_image(mlx->ptr, mlx->you_win->img_data);
	mlx_destroy_image(mlx->ptr, mlx->cat_right->img_data);
	mlx_destroy_image(mlx->ptr, mlx->cat_left->img_data);
	mlx_destroy_image(mlx->ptr, mlx->exit[0]->img_data);
	mlx_destroy_image(mlx->ptr, mlx->exit[1]->img_data);
	mlx_destroy_image(mlx->ptr, mlx->coin->img_data);
}

void	free_textures(t_mlx *mlx)
{
	free(mlx->bg);
	free(mlx->wall);
	free(mlx->you_lose);
	free(mlx->you_win);
	free(mlx->cat_right);
	free(mlx->cat_left);
	free(mlx->exit[0]);
	free(mlx->exit[1]);
	free(mlx->coin);
}

void	error_handle(char *error_msg)
{
	write(2, "Error\n", 6);
	ft_printf(error_msg);
	exit(1);
}
