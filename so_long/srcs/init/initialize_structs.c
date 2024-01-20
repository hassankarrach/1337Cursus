#include "../../so_long.h"

void initialize_structs(t_mlx *mlx)
{
    mlx->map.collectibles = 0;
    mlx->map.height = 0;
    mlx->map.width = 0;
    mlx->map.player1.moves = 0;
    mlx->map.player1.colectibles_earned = 0;
    mlx->map.player1.player_pos_x = 0;
    mlx->map.player1.player_pos_y = 0;
}