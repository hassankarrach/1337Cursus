/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:41:10 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/06 18:04:20 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void set_nodes_index(t_stack *a, t_stack *b)
{
    int i;

    i = 0;
    if(!a || !b)
        return ;
    while(a)
    {
        a->index = i;
        i++;
        a = a->next;
    }
    i = 0;
    while(b)
    {
        b->index = i;
        i++;
        b = b->next;
    }
}

void set_node_target(t_stack *a, t_stack *b)
{
    t_stack *target;
    t_stack *current_a;
    t_stack *SmallestNode;
    int the_diff;
    int tmp;

    if(!a || !b)
        return ;
    while (b)
    {
        target = NULL; 
        the_diff = 2147483647;

        current_a = a;
        while (current_a)
        {
            tmp = current_a->value - b->value;

            if (tmp >= 0 && tmp < the_diff)
            {
                the_diff = tmp;
                target = current_a;
                b->targ = target;
            }

            current_a = current_a->next;
        }

        if(!target)
        {
            SmallestNode = smallest_node(a);
            b->targ = SmallestNode;
        }

        b = b->next;
    }
}

void set_node_position(t_stack *a, t_stack *b)
{
    int a_len;
    int b_len;

    if(!a || !b)
        return ;
            
    a_len = stack_len(a);
    b_len = stack_len(b);

    while(a)
    {
        if(a->index < (a_len/2 + 1))
            a->is_in_top = 1;
        else
            a->is_in_top = 0;
        a = a->next;
    }
    while(b)
    {
        if(b->index < (b_len/2 + 1))
            b->is_in_top = 1;
        else
            b->is_in_top = 0;
        b = b->next;
    }
}

void set_node_cost(t_stack *a, t_stack *b)
{
    int b_len;
    int a_len;

    if(!a || !b)
        return ;
    b_len = stack_len(b);
    a_len = stack_len(a);
    while(b)
    {
        if(b->is_in_top && b->targ->is_in_top)
        {
            if(b->index > b->targ->index)
                b->cost_to_push = b->index;
            else
                b->cost_to_push = b->targ->index;
        }
        else if(!b->is_in_top && !b->targ->is_in_top)
        {
            if((b_len - b->index) >= (a_len - b->targ->index))
                b->cost_to_push = b_len - b->index;
            else
                b->cost_to_push = a_len - (b->targ->index);
        }
        else
        {
            if(b->is_in_top && !b->targ->is_in_top)
                b->cost_to_push = b->index + (a_len - b->targ->index);
            else if(!b->is_in_top && b->targ->is_in_top)
                b->cost_to_push = (b_len - b->index) + a->index;
        }
        b = b->next;
    }
}
