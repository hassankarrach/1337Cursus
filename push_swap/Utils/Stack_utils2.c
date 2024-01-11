/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:36:06 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/10 11:11:52 by hkarrach         ###   ########.fr       */
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
	int				highest;
	t_stack	*highest_node;

	if (NULL == head)
		return (NULL);
	highest = INT_MIN;
	while (head)
	{
		if (head->value > highest)
		{
			highest = head->value;
			highest_node = head;
		}
		head = head->next;
	}
	return (highest_node);
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
