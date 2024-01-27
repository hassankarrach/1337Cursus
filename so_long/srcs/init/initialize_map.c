#include "../../so_long.h"

int texture_attach(t_mlx *mlx, t_img *texture, int pos_x, int pos_y)
{
    texture->x_pos = pos_x * 60;
    texture->y_pos = pos_y * 60;
    return (mlx_put_image_to_window(mlx->ptr, mlx->win, texture->img_data, texture->x_pos, texture->y_pos));
}

static void map_parsing(t_mlx *mlx, char c, int pos_x, int pos_y, int CoinFrame, int cat_frame, int exit_frame, int monster_frame)
{
    if(c == '1')
        texture_attach(mlx, mlx->wall, pos_x, pos_y);
    else if(c == '0')
        texture_attach(mlx, mlx->bg, pos_x, pos_y);
    else if(c == 'C')
        texture_attach(mlx, mlx->coin[CoinFrame], pos_x, pos_y);
    else if(c == 'E')
        texture_attach(mlx, mlx->exit[exit_frame], pos_x, pos_y);
    else if(c == 'P')
    {
        mlx->map.player1.player_pos_x = pos_x * 60;
        mlx->map.player1.player_pos_y = pos_y * 60;
        if(mlx->map.player1.is_lost)
            texture_attach(mlx, mlx->cat_damaged[monster_frame], pos_x, pos_y);
        else if(mlx->map.player1.is_won)
            texture_attach(mlx, mlx->exit[3], pos_x, pos_y);
        else
        {
            if(mlx->cat_direction)
                texture_attach(mlx, mlx->cat_right[cat_frame], pos_x, pos_y);
            else
                texture_attach(mlx, mlx->cat_left[cat_frame], pos_x, pos_y);
        }
    }
    else if(c == 'M')
        texture_attach(mlx, mlx->monster[monster_frame], pos_x, pos_y);
}

static void put_cat_moves(t_mlx *mlx)
{
    int     textX;
    int     textY;
    char    *cat_moves;

    textX = mlx->cat_moves->width + 25;
    textY = mlx->map.height + 33;
    cat_moves = ft_itoa(mlx->map.player1.moves);
    mlx_string_put(mlx->ptr, mlx->win, textX, textY, 0xFFFFFF, cat_moves);
    free(cat_moves);
}

void initialize_map(t_mlx *mlx, int CoinFrame, int cat_frame, int exit_frame, int monster_frame)
{
    int     pos_x;
    int     pos_y;
    char    **lines;
    
    mlx_clear_window(mlx->ptr, mlx->win);
    pos_y = 0;
    lines = mlx->map.map_lines;

    while(lines[pos_y])
    { 
        pos_x = 0;
        while(lines[pos_y][pos_x])
        {
            map_parsing(mlx, lines[pos_y][pos_x], pos_x, pos_y, CoinFrame, cat_frame, exit_frame, monster_frame);
            pos_x++;
        }
        pos_y++;
    }
    if(mlx->map.player1.is_lost)
        mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->you_lose->img_data, mlx->map.width/2 - 120, mlx->map.height/2);
    if(mlx->map.player1.is_won)
        mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->you_win->img_data, mlx->map.width/2 - 120, mlx->map.height/2);
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->cat_moves->img_data, 15, mlx->map.height + 15);
    put_cat_moves(mlx);
}
