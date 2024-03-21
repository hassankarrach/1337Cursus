/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:15:40 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/21 01:33:37 by hkarrach         ###   ########.fr       */
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
	while (lines[i])
		free(lines[i++]);
	i = 0;
	while (cpy_lines[i])
		free(cpy_lines[i++]);
	free(cpy_lines);
	free(lines);
}

static void free_helper(t_mlx *mlx, int flag)
{
	if (flag == 1)
	{
		if (mlx->bg)
			free(mlx->bg);
		if (mlx->wall)
			free(mlx->wall);
		if (mlx->cat_moves)
			free(mlx->cat_moves);
	}
	else if (flag == 0)
	{
		if(mlx->bg)
			mlx_destroy_image(mlx->ptr, mlx->bg->img_data);
		if(mlx->wall)
			mlx_destroy_image(mlx->ptr, mlx->wall->img_data);
		if(mlx->cat_moves)
			mlx_destroy_image(mlx->ptr, mlx->cat_moves->img_data);
	}
}

void	destroy_images(t_mlx *mlx)
{
	int	i;

	free_helper(mlx, 0);
	i = 0;
	while (i < 8 && mlx->cat_right[i])
		mlx_destroy_image(mlx->ptr, mlx->cat_right[i++]->img_data);
	i = 0;
	while (i < 8 && mlx->cat_left[i])
		mlx_destroy_image(mlx->ptr, mlx->cat_left[i++]->img_data);
	i = 0;
	while (i < 4 && mlx->cat_damaged[i])
		mlx_destroy_image(mlx->ptr, mlx->cat_damaged[i++]->img_data);
	i = 0;
	while (i < 4 && mlx->monster[i])
		mlx_destroy_image(mlx->ptr, mlx->monster[i++]->img_data);
	i = 0;
	while (i < 4 && mlx->exit[i])
		mlx_destroy_image(mlx->ptr, mlx->exit[i++]->img_data);
	i = 0;
	while (i < 6 && mlx->coin[i])
		mlx_destroy_image(mlx->ptr, mlx->coin[i++]->img_data);
}

void	free_textures(t_mlx *mlx)
{
	int	i;

	free_helper(mlx, 1);
	i = 0;
	while (i < 8 && mlx->cat_right[i])
		free(mlx->cat_right[i++]);
	i = 0;
	while (i < 8 && mlx->cat_left[i])
		free(mlx->cat_left[i++]);
	i = 0;
	while (i < 4 && mlx->cat_damaged[i])
		free(mlx->cat_damaged[i++]);
	i = 0;
	while (i < 4 && mlx->monster[i])
		free(mlx->monster[i++]);
	i = 0;
	while (i < 4 && mlx->exit[i])
		free(mlx->exit[i++]);
	i = 0;
	while (i < 6 && mlx->coin[i])
		free(mlx->coin[i++]);
}

void	error_handle(t_mlx *mlx, char *error_msg, int flag)
{
	if (flag == 1)
	{
		free_lines(&mlx->map);
	}
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	write(2, "Error\n", 6);
	ft_printf(error_msg);
	exit(1);
}
