/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 04:20:01 by hkarrach          #+#    #+#             */
/*   Updated: 2024/03/20 20:09:01 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
	{
		write(2, "Please enter the path of the map file.", 38);
		exit(1);
	}
	initialize_structs(&mlx);
	initialize_mlx(&mlx);
	is_map_valid(argv[1], &mlx);
	initialize_mlx_window(&mlx);
	initialize_textures(&mlx);
	initialize_map(&mlx);
	initialize_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
