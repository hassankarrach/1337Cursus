#include "../../so_long.h"

int on_destroy(t_mlx *mlx)
{
	// mlx_destroy_window(mlx->ptr, mlx->ptr);
	// mlx_destroy_display(mlx->ptr);
	// free(mlx->ptr);
    printf("game destroyed.\n");
	exit(0);
	return (0);
}