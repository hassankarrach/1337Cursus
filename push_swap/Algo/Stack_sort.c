/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:39:05 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 13:38:07 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->targ && *b != cheapest_node)
		stack_rr(a, b, 0);
	set_node_position(*a);
	set_node_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b,
		t_stack *cheapest_node)
{
	while (*a != cheapest_node->targ && *b != cheapest_node)
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
			{
				stack_ra(head, 0);
			}
			else
			{
				stack_rra(head, 0);
			}
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

	node_to_push = get_cheapest(*b);
	if (node_to_push->is_in_top && node_to_push->targ->is_in_top)
		rotate_both(a, b, node_to_push);
	else if (!node_to_push->is_in_top && !node_to_push->targ->is_in_top)
		reverse_rotate_both(a, b, node_to_push);
	finalize_ratation(b, node_to_push, 'b');
	finalize_ratation(a, node_to_push->targ, 'a');
	stack_pa(a, b, 0);
}

void	stack_sort(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (stack_len(*a) > 3)
			stack_pb(b, a, 0);
	}
	tiny_sort(a);
	while (*b)
	{
		initialize(*a, *b);
		push(a, b);
	}
	finish_sort(a);
}
