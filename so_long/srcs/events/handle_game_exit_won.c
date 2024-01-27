/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_exit_won.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:16:15 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 05:16:16 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	handle_game_exit_won(t_mlx *mlx)
{
	ft_printf("YOU WON!\n");
	mlx->map.player1.is_won = 1;
}
