#include "../../so_long.h"

int texture_attach(t_mlx *mlx, t_img *texture, int pos_x, int pos_y)
{
    texture->x_pos = pos_x * 60;
    texture->y_pos = pos_y * 60;
    return (mlx_put_image_to_window(mlx->ptr, mlx->win, texture->img_data, texture->x_pos, texture->y_pos));
}

static void map_parsing(t_mlx *mlx, char c, int pos_x, int pos_y)
{
    if(c == '1')
        texture_attach(mlx, mlx->assets[1], pos_x, pos_y);
    else if(c == '0')
        texture_attach(mlx, mlx->assets[0], pos_x, pos_y);
    else if(c == 'C')
    {
        mlx->map.collectibles++;
        texture_attach(mlx, mlx->assets[4], pos_x, pos_y);
    }
    else if(c == 'E')
        texture_attach(mlx, mlx->assets[3], pos_x, pos_y);
    else if(c == 'P')
    {
        mlx->map.player1.player_pos_x = pos_x * 60;
        mlx->map.player1.player_pos_y = pos_y * 60;
        texture_attach(mlx, mlx->assets[2], pos_x, pos_y);
    }
}

void initialize_map(t_mlx *mlx)
{
    int     pos_x;
    int     pos_y;
    char    **lines;

    pos_y = 0;
    lines = mlx->map.map_lines;
    while(lines[pos_y])
    { 
        pos_x = 0;
        while(lines[pos_y][pos_x])
        {
            map_parsing(mlx, lines[pos_y][pos_x], pos_x, pos_y);
            pos_x++;
        }
        pos_y++;
    }
}