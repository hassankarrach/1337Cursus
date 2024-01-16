/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:26:22 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/16 08:26:50 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (stack_len(*a) > 3)
	{
		initialize(*a, *b);
		cheapest = smallest_node(*a);
		finalize_ratation(a, cheapest, 'a');
		stack_pb(b, a, 0);
	}
	tiny_sort(a);
	while (*b)
		stack_pa(a, b, 0);
}
