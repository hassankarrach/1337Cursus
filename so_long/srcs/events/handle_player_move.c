#include "../../so_long.h"

static void handle_move_up(t_mlx *mlx, int curr_x, int curr_y)
{
    if(is_next_move_valid(mlx, curr_x, curr_y - 60))
    {
        if(is_next_move_earn_clb(mlx, curr_x, curr_y - 60))
            mlx->map.player1.colectibles_earned++;
        else if(is_next_move_exit(mlx, curr_x, curr_y - 60) && mlx->map.player1.colectibles_earned == mlx->map.collectibles)
            handle_game_exit_won();
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
        if(is_next_move_earn_clb(mlx, curr_x + 60, curr_y))
            mlx->map.player1.colectibles_earned++;
        else if(is_next_move_exit(mlx, curr_x + 60, curr_y) && mlx->map.player1.colectibles_earned == mlx->map.collectibles)
            handle_game_exit_won();
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
        if(is_next_move_earn_clb(mlx, curr_x - 60, curr_y))
            mlx->map.player1.colectibles_earned++;
        else if(is_next_move_exit(mlx, curr_x - 60, curr_y) && mlx->map.player1.colectibles_earned == mlx->map.collectibles)
            handle_game_exit_won();
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
        if(is_next_move_earn_clb(mlx, curr_x, curr_y + 60))
            mlx->map.player1.colectibles_earned++;
        else if(is_next_move_exit(mlx, curr_x, curr_y + 60) && mlx->map.player1.colectibles_earned == mlx->map.collectibles)
            handle_game_exit_won();
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

    printf("Number of Moves : %d.\n", mlx->map.player1.moves); //should be inside handlers.
    printf("%d/%d collectibles you've earned.\n", mlx->map.player1.colectibles_earned, mlx->map.collectibles);
}