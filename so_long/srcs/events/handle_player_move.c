#include "../../so_long.h"

static char pos_to_content(t_mlx *mlx, int pos_x, int pos_y)
{
    return ((mlx->map.map_lines[pos_y / 60][pos_x / 60]));
}

static int is_next_move_valid(t_mlx *mlx, int next_x, int next_y)
{
    char next_move_content;

    next_move_content = pos_to_content(mlx, next_x, next_y);
    if(next_move_content == '1')
        return (0);
    else
        return (1);
}
static void handle_move_up(t_mlx *mlx, int curr_x, int curr_y)
{
    if(is_next_move_valid(mlx, curr_x, curr_y - 60))
    {
        mlx->map.player1.moves++;
        mlx->map.map_lines[curr_y / 60][ curr_x / 60] = '0';
        mlx->map.map_lines[(curr_y - 60) / 60][ curr_x / 60] = 'P';
        mlx->map.player1.player_pos_x = curr_x;
        mlx->map.player1.player_pos_y = curr_y - 60;

        initialize_map(mlx);
    }
}
static void handle_move_right(t_mlx *mlx, int curr_x, int curr_y)
{
    if(is_next_move_valid(mlx, curr_x + 60, curr_y))
    {
        mlx->map.player1.moves++;
        mlx->map.map_lines[curr_y / 60][curr_x / 60] = '0';
        mlx->map.map_lines[curr_y / 60][(curr_x + 60) / 60] = 'P';
        mlx->map.player1.player_pos_x = curr_x + 60;
        mlx->map.player1.player_pos_y = curr_y;

        initialize_map(mlx);
    }
}
static void handle_move_left(t_mlx *mlx, int curr_x, int curr_y)
{
    if(is_next_move_valid(mlx, curr_x - 60, curr_y))
    {
        mlx->map.player1.moves++;
        mlx->map.map_lines[curr_y / 60][curr_x / 60] = '0';
        mlx->map.map_lines[curr_y / 60][(curr_x - 60) / 60] = 'P';
        mlx->map.player1.player_pos_x = curr_x - 60;
        mlx->map.player1.player_pos_y = curr_y;

        initialize_map(mlx);
    }
}
static void handle_move_down(t_mlx *mlx, int curr_x, int curr_y)
{
    if(is_next_move_valid(mlx, curr_x, curr_y + 60))
    {
        mlx->map.player1.moves++;
        mlx->map.map_lines[curr_y / 60][ curr_x / 60] = '0';
        mlx->map.map_lines[(curr_y + 60) / 60][ curr_x / 60] = 'P';
        mlx->map.player1.player_pos_x = curr_x;
        mlx->map.player1.player_pos_y = curr_y + 60;

        initialize_map(mlx);
    }
}
void    handle_player_move(t_mlx *mlx, char move_direction)
{
    int curr_x;
    int curr_y;


    curr_x = mlx->map.player1.player_pos_x;
    curr_y = mlx->map.player1.player_pos_y;
    if(move_direction == 'u')
        handle_move_up(mlx, curr_x, curr_y);
    else if(move_direction == 'l')
        handle_move_left(mlx, curr_x, curr_y);
    else if(move_direction == 'r')
        handle_move_right(mlx, curr_x, curr_y);
    else if(move_direction == 'd')
        handle_move_down(mlx, curr_x, curr_y);
}