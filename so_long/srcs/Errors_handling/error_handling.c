/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:15:40 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/13 02:53:43 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_lines(t_map *map)
{
	char	**lines;
	char	**cpy_lines;
	int		i;

	lines = map->map_lines;
	cpy_lines = map->map_lines_cpy;
	i = 0;
	if (lines)
	{
		while (lines[i])
			free(lines[i++]);
		free(lines);
	}
	i = 0;
	if (cpy_lines)
	{
		while (cpy_lines[i])
			free(cpy_lines[i++]);
		free(cpy_lines);
	}
}

void	destroy_images(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->bg->img_data);
	mlx_destroy_image(mlx->ptr, mlx->wall->img_data);
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

void	free_and_error(t_map *map, char *err_msg)
{
	free_lines(map);
	write(2, "Error\n", 6);
	ft_printf(err_msg);
	exit(1);
}
