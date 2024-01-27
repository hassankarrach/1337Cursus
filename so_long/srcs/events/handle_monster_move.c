#include "../../so_long.h"
#include <time.h>

static int has_elapsed_1_seconds(time_t *last_time)
{
    time_t current_time = time(NULL);

    if (current_time - *last_time >= 1) {
        *last_time = current_time;
        return 1;
    }

    return 0;
}

static int is_move_valid(t_mlx *mlx, int next_monster_x, int next_monster_y)
{
    if (mlx->map.map_lines[next_monster_y][next_monster_x] == '0' || mlx->map.map_lines[next_monster_y][next_monster_x] == 'P')
        return 1;
    else
        return 0;
}

void    update_monster_position(t_mlx *mlx, int *monster_curr_x, int monster_curr_y)
{
    static int reached_right_edge = 0;
    static int reached_left_edge = 0;
    
    if (is_move_valid(mlx, (*monster_curr_x) - 1, monster_curr_y) && !reached_left_edge)
    {
        if(mlx->map.map_lines[monster_curr_y][(*monster_curr_x) - 1] == 'P')
        {
            mlx->map.player1.is_lost = 1;
            mlx->map.map_lines[monster_curr_y][*monster_curr_x] = '0';
            return ;
        }

        mlx->map.map_lines[monster_curr_y][*monster_curr_x] = '0';
        mlx->map.map_lines[monster_curr_y][*monster_curr_x - 1] = 'M';

        if(!is_move_valid(mlx, (*monster_curr_x) - 2, monster_curr_y))
        {
            reached_left_edge = 1;
            reached_right_edge = 0;
        }
        return ;
    }

    if (is_move_valid(mlx, (*monster_curr_x) + 1, monster_curr_y)  && !reached_right_edge)
    {
        if( mlx->map.map_lines[monster_curr_y][(*monster_curr_x) + 1] == 'P')
        {
            mlx->map.player1.is_lost = 1;
            mlx->map.map_lines[monster_curr_y][*monster_curr_x] = '0';
            return ;
        }

        mlx->map.map_lines[monster_curr_y][*monster_curr_x] = '0';
        mlx->map.map_lines[monster_curr_y][(*monster_curr_x) + 1] = 'M';
        
        if(!is_move_valid(mlx, (*monster_curr_x) + 2, monster_curr_y))
        {
            reached_right_edge = 1;
            reached_left_edge = 0;
        }

        (*monster_curr_x)++;
        return ;
    }
}

void handle_monster_move(t_mlx *mlx)
{
    static time_t last_move_time = 0;
    int i;
    int x;
    int y;

    i = 0;
    y = 0;
    if(has_elapsed_1_seconds(&last_move_time))
    {
        while(mlx->map.map_lines[y])
        {
            x = 0;
            while(mlx->map.map_lines[y][x])
            {
                if(mlx->map.map_lines[y][x] == 'M')
                    update_monster_position(mlx, &x, y);
                x++;
            }
            y++;
        }
    }
}
