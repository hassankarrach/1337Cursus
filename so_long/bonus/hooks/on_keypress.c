/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:24:09 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 17:33:53 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_keypress(int keysym, t_mlx *mlx)
{
	(void)mlx;
	if (keysym == 119 || keysym == 65362)
		handle_player_move(mlx, 'u');
	else if (keysym == 97 || keysym == 65361)
		handle_player_move(mlx, 'l');
	else if (keysym == 100 || keysym == 65363)
		handle_player_move(mlx, 'r');
	else if (keysym == 115 || keysym == 65364)
		handle_player_move(mlx, 'd');
	else if (keysym == 65307)
		on_destroy(mlx);
	return (0);
}
