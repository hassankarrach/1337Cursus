/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:20:22 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/12 10:42:14 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_sb(t_stack **b, int is_checker)
{
	stack_swap(b);
	if (!is_checker)
		write(1, "sb\n", 3);
}
