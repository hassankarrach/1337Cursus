/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:34:56 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/07 13:07:07 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *new_node(int value)
{
    t_stack *node;
    int     index;

    node = (t_stack *)malloc(sizeof(t_stack));
    if(!node)
        return (NULL);
    node->cost_to_push = 0;
    node->is_in_top = 0;
    node->value = value;
    node->index = 0;
    node->targ = node;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}
t_stack *find_last_node(t_stack *head)
{
    if(!head)
        return (NULL);
    while(head->next)
    {
        head = head->next;
    }
    return (head);
}
void append_node(t_stack **head, t_stack *node)
{
    t_stack *last_node;

    if(head == NULL)
        return ;

    if(*head == NULL)
    {
        *head = node;
        return ;
    }
    
    last_node = find_last_node(*head);
    last_node->next = node;
    node->prev = last_node;
}
