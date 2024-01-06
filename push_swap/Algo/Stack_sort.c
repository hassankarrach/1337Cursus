/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:39:05 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/06 18:31:04 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void Finish_sort(t_stack **a)
{
    t_stack *smallest;
    
	smallest = smallest_node(*a);
	if (smallest->is_in_top)
    {
		while (*a != smallest)
            {
                stack_ra(a);
            }
    }
	else
    {		
        while (*a != smallest)
            {
                printf("%d\n", (*a)->value);
                stack_rra(a);
                printf("3232%d\n", (*a)->value);
            }
    }
}

static void initialize(t_stack **a, t_stack **b)
{
    set_nodes_index((*a), (*b));
    set_node_position((*a), (*b));
    set_node_target((*a), (*b));
    set_node_cost((*a), (*b));
}

static void Rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while(*a != cheapest_node->targ && *b != cheapest_node)
        stack_rr(a, b);
    set_node_position((*a), (*b));
}

static void Reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while(*a != cheapest_node->targ && *b != cheapest_node)
        stack_rrr(a, b);
    set_node_position((*a), (*b));
}

static void Finalize_ratation(t_stack **head, t_stack *node, char stack_name)
{
    while((*head) != node)
    {
        if(stack_name == 'a')
        {
            if(node->is_in_top)
            {
                stack_ra(head);
            }
            else
            {
                stack_rra(head);
            }
        }
        else if (stack_name == 'b')
        {
            if(node->is_in_top)
                stack_rb(head);
            else
                stack_rrb(head);
        }
    }
}

static void push(t_stack **a, t_stack **b)
{
    t_stack *Node_to_push;

    Node_to_push = get_cheapest(*b);
    
    if(Node_to_push->is_in_top && Node_to_push->targ->is_in_top)
        Rotate_both(a, b, Node_to_push);
    else if(!Node_to_push->is_in_top && !Node_to_push->targ->is_in_top)
        Reverse_rotate_both(a, b, Node_to_push);
        
    Finalize_ratation(b, Node_to_push, 'b');
    Finalize_ratation(a, Node_to_push->targ, 'a');
    
    stack_pa(a, b);
}

void stack_sort(t_stack **a, t_stack **b)
{
    while(stack_len(*a) > 3)
        stack_pb(b, a);
    tiny_sort(a);
    
    int i = 0;
    while(*b)
    {
        initialize(a,b);
        push(a, b);
    }
    
    set_node_position(*a, *b);
    Finish_sort(a);
}