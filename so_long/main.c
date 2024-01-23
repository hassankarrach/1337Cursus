#include "so_long.h"

static int on_evry_frame(void *param) {
    t_mlx *mlx = (t_mlx *)param;
    static int coin_frame = 0;
    static int cat_frame = 0;
    static int monster_frame = 0;

    if(mlx->map.collectibles == mlx->map.player1.colectibles_earned && mlx->exit_frame < 3)
        mlx->exit_frame++;

    handle_monster_move(mlx);
    initialize_map(mlx, coin_frame, cat_frame, mlx->exit_frame, monster_frame);

    coin_frame = (coin_frame + 1) % 6;
    cat_frame = (cat_frame + 1) % 6;
    monster_frame = (monster_frame + 1) % 4;
    usleep(100000);
    return 0;
}

int main(int argc, char **argv)
{
    t_mlx   mlx;

    if(argc != 2)
       printf("PLease Enter the map file path.\n");
    initialize_structs(&mlx);
    is_map_valid(argv[1], &mlx.map);
    
    initialize_mlx(&mlx);
    initialize_textures(&mlx);
    initialize_hooks(&mlx);
    mlx_loop_hook(mlx.ptr, &on_evry_frame, &mlx);
    mlx_loop(mlx.ptr);  

}

/*
--TBD--
1- Re-code is_map_valid with uses of the 2d Array instead of checks evry line. x
2- inside is_map_valid it should update the map number of collectibles. x
3- render animation.
4- figuer out if there's a need to split the project into bonus section and mend part.
5- Handle printing of number of moves.
6- open the exit animation whene all colls earned. 
...
*/
