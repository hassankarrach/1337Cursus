/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:41:10 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 12:14:08 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_node_target(t_stack *a, t_stack *b)
{
	t_stack	*current_node;
	long	current_index;

	while (b)
	{
		current_index = LONG_MAX;
		current_node = a;
		while (current_node)
		{
			if (current_node->value > b->value
				&& current_node->value < current_index)
			{
				current_index = current_node->value;
				b->targ = current_node;
			}
			current_node = current_node->next;
		}
		if (current_index == LONG_MAX)
			b->targ = smallest_node(a);
		b = b->next;
	}
}

void	set_node_position(t_stack *stack)
{
	int	stacklen;
	int	stack_middle_line;
	int	i;

	if (!stack)
		return ;
	stacklen = stack_len(stack);
	stack_middle_line = stacklen / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (stack->index <= stack_middle_line)
			stack->is_in_top = 1;
		else
			stack->is_in_top = 0;
		stack = stack->next;
		i++;
	}
}

void	set_node_cost(t_stack *a, t_stack *b)
{
	int	b_len;
	int	a_len;

	if (!a || !b)
		return ;
	b_len = stack_len(b);
	a_len = stack_len(a);
	while (b)
	{
		if (b->is_in_top)
			b->cost_to_push = b->index;
		else
			b->cost_to_push = b_len - (b->index);
		if (b->targ->is_in_top)
			b->cost_to_push += b->targ->index;
		else
			b->cost_to_push += a_len - (b->targ->index);
		b = b->next;
	}
}

void	initialize(t_stack *a, t_stack *b)
{
	set_node_position(a);
	set_node_position(b);
	set_node_target(a, b);
	set_node_cost(a, b);
}
