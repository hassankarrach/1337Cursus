#include "../../so_long.h"

static void update_positions(t_mlx *mlx, int curr_pos_x, int curr_pos_y, int next_pos_x, int next_pos_y)
{
    mlx->map.map_lines[curr_pos_y][curr_pos_x] = '0';
    mlx->map.map_lines[next_pos_y][next_pos_x] = 'P';
    mlx->map.player1.player_pos_x = next_pos_x;
    mlx->map.player1.player_pos_y = next_pos_y;

    printf("Number of Moves : %d.\n", mlx->map.player1.moves);
    printf("%d/%d collectibles you've earned.\n", mlx->map.player1.colectibles_earned, mlx->map.collectibles);
}

static void handle_move_up(t_mlx *mlx, int curr_x, int curr_y)
{
    if(is_next_move_valid(mlx, curr_x, curr_y - 60) && !mlx->map.player1.is_lost)
    {
        if(is_next_move_earn_clb(mlx, curr_x, curr_y - 60))
            mlx->map.player1.colectibles_earned++;
        if(is_next_move_enemy(mlx, curr_x, curr_y - 60))
            handle_game_lose(mlx);
        else if(is_next_move_exit(mlx, curr_x, curr_y - 60))
        {
            if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
            {
                printf("complete clcs to exit!\n");
                return ;
            }
            else
                handle_game_exit_won();
        }
        mlx->map.player1.moves++;
        update_positions(mlx, curr_x/60, curr_y/60, curr_x / 60, (curr_y - 60) / 60);
        // initialize_map(mlx, 0, 0);
    }
}
static void handle_move_right(t_mlx *mlx, int curr_x, int curr_y)
{
    if(is_next_move_valid(mlx, curr_x + 60, curr_y) && !mlx->map.player1.is_lost)
    {
        if(is_next_move_earn_clb(mlx, curr_x + 60, curr_y))
                mlx->map.player1.colectibles_earned++;
        if(is_next_move_enemy(mlx, curr_x + 60, curr_y))
            handle_game_lose(mlx);
        else if(is_next_move_exit(mlx, curr_x + 60, curr_y))
        {
            if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
            {
                printf("complete clcs to exit!\n");
                return ;
            }
            else
                handle_game_exit_won();
        }
        mlx->map.player1.moves++;
        mlx->cat_direction = 1;
        update_positions(mlx, curr_x/60, curr_y/60, (curr_x + 60) / 60, curr_y / 60);
        // initialize_map(mlx, 0, 0);
    }
}
static void handle_move_left(t_mlx *mlx, int curr_x, int curr_y)
{
    if(is_next_move_valid(mlx, curr_x - 60, curr_y) && !mlx->map.player1.is_lost)
    {
        if(is_next_move_earn_clb(mlx, curr_x - 60, curr_y))
            mlx->map.player1.colectibles_earned++;
        if(is_next_move_enemy(mlx, curr_x - 60, curr_y))
            handle_game_lose(mlx);
        else if(is_next_move_exit(mlx, curr_x - 60, curr_y))
        {
            if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
            {
                printf("complete clcs to exit!\n");
                return ;
            }
            else
                handle_game_exit_won();
        }

        mlx->map.player1.moves++;
        mlx->cat_direction = 0;
        update_positions(mlx, curr_x/60, curr_y/60, (curr_x - 60) / 60, curr_y / 60);
        // initialize_map(mlx, 0, 0);
    }
}
static void handle_move_down(t_mlx *mlx, int curr_x, int curr_y)
{
    if(is_next_move_valid(mlx, curr_x, curr_y + 60) && !mlx->map.player1.is_lost)
    {
        if(is_next_move_earn_clb(mlx, curr_x, curr_y + 60))
            mlx->map.player1.colectibles_earned++;
        if(is_next_move_enemy(mlx, curr_x, curr_y + 60))
            handle_game_lose(mlx);
        else if (is_next_move_exit(mlx, curr_x, curr_y + 60))
        {
            if (mlx->map.player1.colectibles_earned != mlx->map.collectibles)
            {
                printf("complete clcs to exit!\n");
                return ;
            }
            else
                handle_game_exit_won();
        }
        mlx->map.player1.moves++;
        update_positions(mlx, curr_x/60, curr_y/60, curr_x / 60, (curr_y + 60) / 60);
        // initialize_map(mlx, 0, 0);
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