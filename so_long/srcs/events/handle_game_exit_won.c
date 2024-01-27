#include "../../so_long.h"

void handle_game_exit_won(t_mlx *mlx)
{
    ft_printf("YOU WON!\n");
    mlx->map.player1.is_won = 1;
}
