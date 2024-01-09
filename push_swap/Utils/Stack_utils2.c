/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:36:06 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/07 17:18:19 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int stack_len(t_stack *head)
{
    int len;

    len = 0;
    if(head == NULL)
        return (0);
    while (head)
    {
        len++;
        head = head->next;    
    }

    return (len);
}
t_stack *higgest_node(t_stack *head)
{
    int     tmp_value;
    t_stack *Higgest_node;

    if(!head)
        return (NULL);
    tmp_value = head->value;
    Higgest_node = head;
    while(head->next)
    {
        head = head->next;
        if(head->value > tmp_value)
        {
            tmp_value = head->value;
            Higgest_node = head;
        }
    }
    return (Higgest_node);
}
t_stack *smallest_node(t_stack *head)
{
    int     tmp_value;
    t_stack *smallest_node;

    if(!head)
        return (NULL);
    tmp_value = head->value;
    smallest_node = head;
    while(head)
    {
        if(head->value < tmp_value)
        {
            tmp_value = head->value;
            smallest_node = head;
        }
        head = head->next;
    }
    return (smallest_node);
}
