/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:08:02 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/15 12:52:23 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = higgest_node(*a);
	if (*a == highest_node)
		stack_ra(a, 0);
	else if ((*a)->next == highest_node)
		stack_rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		stack_sa(a, 0);
}

int	is_sorted(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*get_cheapest(t_stack *a)
{
	t_stack	*cheapest;
	int		max;

	cheapest = NULL;
	max = INT_MAX;
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cost_to_push < max)
		{
			cheapest = a;
			max = a->cost_to_push;
		}
		a = a->next;
	}
	return (cheapest);
}

void	finish_sort(t_stack **a)
{
	t_stack	*smallest;

	set_node_position(*a);
	smallest = smallest_node(*a);
	if (smallest->is_in_top)
		while (*a != smallest)
			stack_ra(a, 0);
	else
		while (*a != smallest)
			stack_rra(a, 0);
}
