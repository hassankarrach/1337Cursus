/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 04:20:01 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/10 18:37:47 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{//
	t_mlx	mlx;

	if (argc != 2)
		error_handle("Please enter the file path for the map.");
	initialize_structs(&mlx);
	is_map_valid(argv[1], &mlx.map);
	initialize_mlx(&mlx);
	initialize_textures(&mlx);
	initialize_map(&mlx);
	initialize_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
