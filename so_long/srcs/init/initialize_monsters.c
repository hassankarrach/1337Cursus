#include "../../so_long.h"

void initialize_monsters(t_mlx *mlx)
{
    int x;
    int y;
    int monsters_count;

    y = 0;
    monsters_count = 0;
    while(mlx->map.map_lines[y])
    {
        x = 0;
        while(mlx->map.map_lines[y][x])
        {
            if(mlx->map.map_lines[y][x] == 'M')
            {
                mlx->map.monsters[monsters_count].reached_edge = 0;
                mlx->map.monsters[monsters_count].x_pos = x;
                mlx->map.monsters[monsters_count].y_pos = y;
                monsters_count++;
            }
        }
    }
}