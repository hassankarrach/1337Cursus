/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 04:20:01 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 04:23:47 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  on_evry_frame(void *param)
{
    t_mlx       *mlx;
    static int  coin_frame = 0;
    static int  cat_frame = 0;
    static int  monster_frame = 0;

    mlx = (t_mlx *)param;
    if (mlx->map.collectibles == mlx->map.player1.colectibles_earned && mlx->exit_frame < 3)
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
    t_mlx mlx;

    if (argc != 2)
        error_handle("Please enter the file path for the map.");
    initialize_structs(&mlx);
    is_map_valid(argv[1], &mlx.map);
    initialize_mlx(&mlx);
    initialize_textures(&mlx);
    initialize_hooks(&mlx);
    mlx_loop_hook(mlx.ptr, &on_evry_frame, &mlx);
    mlx_loop(mlx.ptr);
}
