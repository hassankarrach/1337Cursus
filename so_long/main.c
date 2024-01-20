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


/*
--TBD--
1- Re-code is_map_valid with uses of the 2d Array instead of checks evry line.
2- inside is_map_valid it should update the map number of collectibles.
3- render animation.
4- figuer out if there's a need to split the project into bonus section and mend part.
5- Handle printing of number of moves.
6- open the exit animation on all colls earned. 
...
*/