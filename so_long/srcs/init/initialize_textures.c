#include "../../so_long.h"

static void *texture_loader(t_mlx *mlx, char *path, int *width, int *height)
{
    return (mlx_xpm_file_to_image(mlx->ptr, path, width, height));
}

static t_img *create_texture(t_mlx *mlx,char *path)
{
    t_img *texture;

    texture = malloc(sizeof(t_img));
    if(!texture)
        return (NULL);
    texture->path = path;
    texture->height = 0;
    texture->width = 0;
    texture->x_pos = 0;
    texture->y_pos = 0;
    texture->img_data = texture_loader(mlx, texture->path, &texture->width, &texture->height);

    return (texture);
}

void initialize_textures(t_mlx *mlx)
{
    mlx->assets[0] = create_texture(mlx, "Assets/floor.xpm");
    mlx->assets[1] = create_texture(mlx, "Assets/wall.xpm");
    mlx->assets[2] = create_texture(mlx, "Assets/player/frames_right/0.xpm");
    mlx->assets[3] = create_texture(mlx, "Assets/exit.xpm");
    mlx->assets[4] = create_texture(mlx, "Assets/coins/frames/1.xpm");
}