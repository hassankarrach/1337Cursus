#include "../../so_long.h"

int on_destroy(t_mlx *mlx)
{
	free_lines(mlx);
	destroy_images(mlx);
	free_textures(mlx);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
    ft_printf("game Ended.\n");
	exit(0);
	return (0);
}