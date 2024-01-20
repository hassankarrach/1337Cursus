#include "../../so_long.h"

int initialize_mlx(t_mlx *mlx)
{
    mlx->ptr = mlx_init();
    if (!mlx->ptr)
		return (1);
    mlx->win = mlx_new_window(mlx->ptr, mlx->map.width, mlx->map.height, "so long def window");
    if(!mlx->win)
        return (free(mlx->ptr), 1);
    return (1);
}