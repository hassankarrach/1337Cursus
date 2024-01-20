#include "../../so_long.h"

void initialize_hooks(t_mlx *mlx)
{
    mlx_hook(mlx->win, 3, 1L<<1,  &on_keypress, mlx);
    mlx_hook(mlx->win, 17, 0L, &on_destroy, mlx);
}