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
    if (mlx->map.map_lines[next_monster_y][next_monster_x] == '0')
        return 1;
    else
        return 0;
}

void    update_monster_position(t_mlx *mlx, int monster_curr_x, int monster_curr_y)
{
    if (is_move_valid(mlx, monster_curr_x + 1, monster_curr_y))
    {
        mlx->map.map_lines[monster_curr_y][monster_curr_x] = '0';
        mlx->map.map_lines[monster_curr_y][monster_curr_x + 1] = 'M';

        return ;
    }
    else if (is_move_valid(mlx, monster_curr_x - 1, monster_curr_y))
    {
        mlx->map.map_lines[monster_curr_y][monster_curr_x] = '0';
        mlx->map.map_lines[monster_curr_y][monster_curr_x - 1] = 'M';

        return ;
    }
}

void handle_monster_move(t_mlx *mlx)
{
    static time_t last_move_time = 0;
    int i;

    i = 0;
    if(has_elapsed_1_seconds(&last_move_time))
    {
        printf("reached.\n");
        while(mlx->map.monsters[i] != NULL)
        {

        }
    }
}
