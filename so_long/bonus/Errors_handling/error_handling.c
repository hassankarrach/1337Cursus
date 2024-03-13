/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:15:40 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/13 03:53:55 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_lines(t_mlx *mlx)
{
	char	**lines;
	char	**cpy_lines;
	int		i;

	lines = mlx->map.map_lines;
	cpy_lines = mlx->map.map_lines_cpy;
	i = 0;
	while (lines[i])
		free(lines[i++]);
	i = 0;
	while (cpy_lines[i])
		free(cpy_lines[i++]);
	free(cpy_lines);
	free(lines);
}

void	destroy_images(t_mlx *mlx)
{
	int	i;

	mlx_destroy_image(mlx->ptr, mlx->bg->img_data);
	mlx_destroy_image(mlx->ptr, mlx->wall->img_data);
	mlx_destroy_image(mlx->ptr, mlx->cat_moves->img_data);
	i = 0;
	while (i < 8)
		mlx_destroy_image(mlx->ptr, mlx->cat_right[i++]->img_data);
	i = 0;
	while (i < 8)
		mlx_destroy_image(mlx->ptr, mlx->cat_left[i++]->img_data);
	i = 0;
	while (i < 4)
		mlx_destroy_image(mlx->ptr, mlx->cat_damaged[i++]->img_data);
	i = 0;
	while (i < 4)
		mlx_destroy_image(mlx->ptr, mlx->monster[i++]->img_data);
	i = 0;
	while (i < 4)
		mlx_destroy_image(mlx->ptr, mlx->exit[i++]->img_data);
	i = 0;
	while (i < 6)
		mlx_destroy_image(mlx->ptr, mlx->coin[i++]->img_data);
}

void	free_textures(t_mlx *mlx)
{
	int	i;

	free(mlx->bg);
	free(mlx->wall);
	free(mlx->cat_moves);
	i = 0;
	while (i < 8)
		free(mlx->cat_right[i++]);
	i = 0;
	while (i < 8)
		free(mlx->cat_left[i++]);
	i = 0;
	while (i < 4)
		free(mlx->cat_damaged[i++]);
	i = 0;
	while (i < 4)
		free(mlx->monster[i++]);
	i = 0;
	while (i < 4)
		free(mlx->exit[i++]);
	i = 0;
	while (i < 6)
		free(mlx->coin[i++]);
}

void	error_handle(char *error_msg)
{
	write(2, "Error\n", 6);
	ft_printf(error_msg);
	exit(1);
}
