/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:18:50 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/07 16:07:19 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void stack_swap(t_stack **head) {
    t_stack *first;
    t_stack *second;
    
    if (*head == NULL || (*head)->next == NULL)
        return;
    first = *head;
    second = first->next;
    first->next = second->next;
    if (second->next != NULL) {
        second->next->prev = first;
    }
    second->prev = NULL;
    second->next = first;
    first->prev = second;

    *head = second;
}

void    stack_push(t_stack **dest, t_stack **src)
{
    t_stack *Next_of_Src;

    Next_of_Src = NULL;
    if(src == NULL || *src == NULL)
        return ;
    
    if((*src)->next)
    {
        Next_of_Src = (*src)->next;
        Next_of_Src->prev = NULL;
    }
    
    if(*dest != NULL)
    {
      (*dest)->prev = *src;
    }
    
    (*src)->next = (*dest);
    (*src)->prev = NULL;

    *dest = *src;
    if(Next_of_Src)
        *src = Next_of_Src;
    else
        *src = NULL;
}

//Rotate
void stack_rotate(t_stack **stack)
{
    t_stack *Next;
    t_stack *Last;

    if(stack == NULL || *stack == NULL || !((*stack)->next))
        return ;

    Next = (*stack)->next;
    Last = find_last_node((*stack));

    Last->next = (*stack);
    (*stack)->next = NULL;
    Next->prev = NULL;
    (*stack)->prev = Last;

    (*stack) = Next;
}

//Reverse_Rotate
void stack_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int				len;

	len = stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
