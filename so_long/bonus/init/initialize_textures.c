/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:27:17 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/08 03:40:31 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_img	*create_texture(t_mlx *mlx, char *path)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->path = path;
	texture->height = 0;
	texture->width = 0;
	texture->x_pos = 0;
	texture->y_pos = 0;
	texture->img_data = mlx_xpm_file_to_image(mlx->ptr, texture->path,
			&texture->width, &texture->height);
	return (texture);
}

static void	load_cat_textures(t_mlx *mlx)
{
	mlx->cat_right[0] = create_texture(mlx, "Assets/cat_right/0.xpm");
	mlx->cat_right[1] = create_texture(mlx, "Assets/cat_right/1.xpm");
	mlx->cat_right[2] = create_texture(mlx, "Assets/cat_right/2.xpm");
	mlx->cat_right[3] = create_texture(mlx, "Assets/cat_right/3.xpm");
	mlx->cat_right[4] = create_texture(mlx, "Assets/cat_right/4.xpm");
	mlx->cat_right[5] = create_texture(mlx, "Assets/cat_right/5.xpm");
	mlx->cat_right[6] = create_texture(mlx, "Assets/cat_right/6.xpm");
	mlx->cat_right[7] = create_texture(mlx, "Assets/cat_right/7.xpm");
	mlx->cat_left[0] = create_texture(mlx, "Assets/cat_left/0.xpm");
	mlx->cat_left[1] = create_texture(mlx, "Assets/cat_left/1.xpm");
	mlx->cat_left[2] = create_texture(mlx, "Assets/cat_left/2.xpm");
	mlx->cat_left[3] = create_texture(mlx, "Assets/cat_left/3.xpm");
	mlx->cat_left[4] = create_texture(mlx, "Assets/cat_left/4.xpm");
	mlx->cat_left[5] = create_texture(mlx, "Assets/cat_left/5.xpm");
	mlx->cat_left[6] = create_texture(mlx, "Assets/cat_left/6.xpm");
	mlx->cat_left[7] = create_texture(mlx, "Assets/cat_left/7.xpm");
	mlx->cat_damaged[0] = create_texture(mlx, "Assets/cat_lost/left/0.xpm");
	mlx->cat_damaged[1] = create_texture(mlx, "Assets/cat_lost/left/1.xpm");
	mlx->cat_damaged[2] = create_texture(mlx, "Assets/cat_lost/left/2.xpm");
	mlx->cat_damaged[3] = create_texture(mlx, "Assets/cat_lost/left/3.xpm");
}

static void	load_coin_textures(t_mlx *mlx)
{
	mlx->coin[0] = create_texture(mlx, "Assets/coin/0.xpm");
	mlx->coin[1] = create_texture(mlx, "Assets/coin/1.xpm");
	mlx->coin[2] = create_texture(mlx, "Assets/coin/2.xpm");
	mlx->coin[3] = create_texture(mlx, "Assets/coin/3.xpm");
	mlx->coin[4] = create_texture(mlx, "Assets/coin/4.xpm");
	mlx->coin[5] = create_texture(mlx, "Assets/coin/5.xpm");
}

static void	load_other_textures(t_mlx *mlx)
{
	mlx->bg = create_texture(mlx, "Assets/0.xpm");
	mlx->wall = create_texture(mlx, "Assets/1.xpm");
	mlx->exit[0] = create_texture(mlx, "Assets/exit/0.xpm");
	mlx->exit[1] = create_texture(mlx, "Assets/exit/1.xpm");
	mlx->exit[2] = create_texture(mlx, "Assets/exit/2.xpm");
	mlx->exit[3] = create_texture(mlx, "Assets/exit/3.xpm");
	mlx->monster[0] = create_texture(mlx, "Assets/monster/0.xpm");
	mlx->monster[1] = create_texture(mlx, "Assets/monster/1.xpm");
	mlx->monster[2] = create_texture(mlx, "Assets/monster/2.xpm");
	mlx->monster[3] = create_texture(mlx, "Assets/monster/3.xpm");
	mlx->cat_moves = create_texture(mlx, "Assets/moves.xpm");
	mlx->you_win = create_texture(mlx, "Assets/you_win.xpm");
	mlx->you_lose = create_texture(mlx, "Assets/you_lose.xpm");
}

void	initialize_textures(t_mlx *mlx)
{
	load_cat_textures(mlx);
	load_coin_textures(mlx);
	load_other_textures(mlx);
}
