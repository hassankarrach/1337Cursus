/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:24:17 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 12:05:52 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_rrb(t_stack **b, int is_checker)
{
	stack_reverse_rotate(b);
	if (!is_checker)
		write(1, "rrb\n", 4);
}
