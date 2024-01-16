/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:41:10 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/16 09:21:15 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*biggest_node(t_stack *stack)
{
	t_stack	*biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->value > biggest->value)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

void	set_node_target(t_stack *a, t_stack *b)
{
	long	current_best;
	t_stack	*temp_b;

	while (a)
	{
		current_best = LONG_MIN;
		temp_b = b;
		while (temp_b)
		{
			if (a->value > temp_b->value && temp_b->value > current_best)
			{
				a->targ = temp_b;
				current_best = temp_b->value;
			}
			temp_b = temp_b->next;
		}
		if (current_best == LONG_MIN)
			a->targ = biggest_node(b);
		a = a->next;
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
	set_node_cost_helper(a, a_len, b_len);
}

void	initialize(t_stack *a, t_stack *b)
{
	set_node_position(a);
	set_node_position(b);
	set_node_target(a, b);
	set_node_cost(a, b);
}
