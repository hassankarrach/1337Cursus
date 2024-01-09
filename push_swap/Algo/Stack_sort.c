/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:39:05 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/08 15:43:53 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void Rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while(*a != cheapest_node->targ && *b != cheapest_node)
        stack_rr(a, b, 0);
    set_node_position(*a);
    set_node_position(*b);
}

static void Reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while(*a != cheapest_node->targ && *b != cheapest_node)
        stack_rrr(a, b, 0);
    set_node_position(*a);
    set_node_position(*b);
}

void Finalize_ratation(t_stack **head, t_stack *node, char stack_name)
{
    while((*head) != node)
    {
        if(stack_name == 'a')
        {
            if(node->is_in_top)
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
            if(node->is_in_top)
                stack_rb(head, 0);
            else
                stack_rrb(head, 0);
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
    
    stack_pa(a, b, 0);
}

void stack_sort(t_stack **a, t_stack **b)
{
    int     len_a;
    
    len_a = stack_len(*a);
    if(len_a == 5)
        Sort_five(a,b);
    else
    {
        while(stack_len(*a) > 3)
            stack_pb(b, a, 0);
    }
    tiny_sort(a);
    
    while(*b)
    {
        initialize(*a,*b);
        push(a, b);
    }

    Finish_sort(a);
}
