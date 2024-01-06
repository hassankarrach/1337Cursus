/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:18:50 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/06 18:49:47 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//SWAP
void stack_swap(t_stack **head)
{
    t_stack *tmp;
    t_stack *next_node;

    next_node = (*head)->next;
    tmp = (*head);
    if (head == NULL || *head == NULL || stack_len(*head) == 1)
        return ;
    (next_node->next)->prev = (*head);

    (*head)->prev = next_node; //x
    (*head)->next = next_node->next;

    next_node->next = (*head);
    next_node->prev = NULL; //x

    *head = next_node;
}

//PUSH
void stack_push(t_stack **dest, t_stack **src)
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
    t_stack *new_head;
    t_stack *new_Last;

    if(stack == NULL || *stack == NULL || !((*stack)->next))
        return ;
    
    new_head = find_last_node((*stack));
    printf("-----%d\n", new_head->value);
    new_Last = new_head->prev;
    // if(!new_Last) //FIX THAaaaaaaaaaaT.
    //     printf("-----%d\n", new_head->value);
    if(new_Last)
        new_Last->next = NULL;

    new_head->next = (*stack);
    new_head->prev = NULL;
    (*stack) = new_head;
}