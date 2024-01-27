/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_lose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:16:29 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 05:16:42 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	handle_game_lose(t_mlx *mlx)
{
	ft_printf("YOU LOST!");
	mlx->map.player1.is_lost = 1;
}
