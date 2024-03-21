/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:27:17 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/20 20:36:23 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_img	*create_texture(t_mlx *mlx, char *path)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img));
	if (!texture)
		exit (1);
	texture->path = path;
	texture->height = 0;
	texture->width = 0;
	texture->x_pos = 0;
	texture->y_pos = 0;
	texture->img_data = mlx_xpm_file_to_image(mlx->ptr, texture->path,
			&texture->width, &texture->height);
	if (!texture->img_data)
	{
		write(2, "Error compiling a xpm assest.\n", 30);
		free(texture);
		on_destroy(mlx);
	}
	return (texture);
}

static void	load_cat_textures(t_mlx *mlx)
{
	mlx->cat_right = create_texture(mlx, "Assets/cat_right/0.xpm");
	mlx->cat_left = create_texture(mlx, "Assets/cat_left/0.xpm");
}

static void	load_coin_textures(t_mlx *mlx)
{
	mlx->coin = create_texture(mlx, "Assets/coin/0.xpm");
}

static void	load_other_textures(t_mlx *mlx)
{
	mlx->bg = create_texture(mlx, "Assets/0.xpm");
	mlx->wall = create_texture(mlx, "Assets/1.xpm");
	mlx->exit[0] = create_texture(mlx, "Assets/exit/0.xpm");
	mlx->exit[1] = create_texture(mlx, "Assets/exit/3.xpm");
}

void	initialize_textures(t_mlx *mlx)
{
	load_cat_textures(mlx);
	load_coin_textures(mlx);
	load_other_textures(mlx);
}
