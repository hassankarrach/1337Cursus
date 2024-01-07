/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:41:10 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/07 12:11:50 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_node_target(t_stack *a, t_stack *b)
{
	t_stack	*Current_Node;
	long	Current_index;

	while (b)
	{
		Current_index = LONG_MAX;
		Current_Node = a;
		while (Current_Node)
		{
			if (Current_Node->value > b->value
				&& Current_Node->value < Current_index)
			{
				Current_index = Current_Node->value;
				b->targ = Current_Node;
			}
			Current_Node = Current_Node->next;
		}
		if (Current_index == LONG_MAX)
			b->targ = smallest_node(a);
		b = b->next;
	}
}
void	set_node_position(t_stack *stack)
{
    int Stack_len;
    int Stack_Middle_line;
    int i;

    if(!stack)
        return;
        
    Stack_len = stack_len(stack);
    Stack_Middle_line = Stack_len / 2;
    i = 0;
    
    while(stack)
    {
        stack->index = i;
        if(stack->index <= Stack_Middle_line)
            stack->is_in_top = 1;
        else
            stack->is_in_top = 0;
        stack = stack->next;
        i++;
    }
}
void	set_node_cost(t_stack *a, t_stack *b)
{
    int b_len;
    int a_len;

    if(!a || !b)
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
    set_node_target(a ,b);
    set_node_cost(a ,b);
}