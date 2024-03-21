/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:15:40 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/21 01:22:28 by hkarrach         ###   ########.fr       */
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
	if (mlx->bg)
		mlx_destroy_image(mlx->ptr, mlx->bg->img_data);
	if (mlx->wall)
		mlx_destroy_image(mlx->ptr, mlx->wall->img_data);
	if (mlx->cat_right)
		mlx_destroy_image(mlx->ptr, mlx->cat_right->img_data);
	if (mlx->cat_left)
		mlx_destroy_image(mlx->ptr, mlx->cat_left->img_data);
	if (mlx->exit[0])
		mlx_destroy_image(mlx->ptr, mlx->exit[0]->img_data);
	if (mlx->exit[1])
		mlx_destroy_image(mlx->ptr, mlx->exit[1]->img_data);
	if (mlx->coin)
		mlx_destroy_image(mlx->ptr, mlx->coin->img_data);
}

void	free_textures(t_mlx *mlx)
{
	if (mlx->bg)
		free(mlx->bg);
	if (mlx->wall)
		free(mlx->wall);
	if (mlx->cat_right)
		free(mlx->cat_right);
	if (mlx->cat_left)
		free(mlx->cat_left);
	if (mlx->exit[0])
		free(mlx->exit[0]);
	if (mlx->exit[1])
		free(mlx->exit[1]);
	if (mlx->coin)
		free(mlx->coin);
}

void	error_handle(t_mlx *mlx, char *error_msg)
{
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	write(2, "Error\n", 6);
	ft_printf("%s%s", RED, error_msg);
	exit(1);
}

void	free_and_error(t_mlx *mlx, char *err_msg)
{
	free_lines(&mlx->map);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	write(2, "Error\n", 6);
	ft_printf("%s%s", RED, err_msg);
	exit(1);
}
