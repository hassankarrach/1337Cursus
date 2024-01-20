#include "so_long.h"

int main(int argc, char **argv)
{
    t_mlx   mlx;

    if(argc != 2)
        ft_printf("PLease Enter the map file path.\n");
    initialize_structs(&mlx);
    is_map_valid(argv[1], &mlx.map);
    initialize_mlx(&mlx);
    initialize_textures(&mlx);
    initialize_map(&mlx);
    initialize_hooks(&mlx);

    mlx_loop(mlx.ptr);
}   