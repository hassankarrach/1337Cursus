#include "../../so_long.h"

void    handle_game_lose(t_mlx *mlx)
{
     ft_printf("YOU LOST!");
     mlx->map.player1.is_lost = 1;
}