/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:39:05 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/16 08:10:38 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->targ)
		stack_rr(a, b, 0);
	set_node_position(*a);
	set_node_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b,
		t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->targ)
		stack_rrr(a, b, 0);
	set_node_position(*a);
	set_node_position(*b);
}

void	finalize_ratation(t_stack **head, t_stack *node, char stack_name)
{
	while ((*head) != node)
	{
		if (stack_name == 'a')
		{
			if (node->is_in_top)
				stack_ra(head, 0);
			else
				stack_rra(head, 0);
		}
		else if (stack_name == 'b')
		{
			if (node->is_in_top)
				stack_rb(head, 0);
			else
				stack_rrb(head, 0);
		}
	}
}

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*node_to_push;

	node_to_push = get_cheapest(*a);
	if (node_to_push->is_in_top && node_to_push->targ->is_in_top)
		rotate_both(a, b, node_to_push);
	else if (!node_to_push->is_in_top && !node_to_push->targ->is_in_top)
		reverse_rotate_both(a, b, node_to_push);
	finalize_ratation(a, node_to_push, 'a');
	finalize_ratation(b, node_to_push->targ, 'b');
	stack_pb(b, a, 0);
}

void	stack_sort(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 5)
	{
		sort_five(a, b);
		return ;
	}
	stack_pb(b, a, 0);
	stack_pb(b, a, 0);
	while (*a)
	{
		initialize(*a, *b);
		push(a, b);
	}
	set_bigger_in_top(b);
	initialize(*a, *b);
	while (*b)
		stack_pa(a, b, 0);
}
