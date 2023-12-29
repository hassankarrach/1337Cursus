#include "push_swap.h"

//SWAP
static void stack_swap(t_stack **head)
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

void stack_sa(t_stack **a)
{
    stack_swap(a);
}

void stack_sb(t_stack **b)
{
    stack_swap(b);
}

void stack_ss(t_stack **a, t_stack **b)
{
    stack_swap(a);
    stack_swap(b);
}

//PUSH
static void stack_push(t_stack **dest, t_stack **src)
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

void stack_pa(t_stack **a, t_stack **b)
{
    stack_push(a,b);
}

void stack_pb(t_stack **b, t_stack **a)
{
    stack_push(b,a);
}

//Rotate
static void stack_rotate(t_stack **stack)
{
    t_stack *Next;
    t_stack *Last;

    if(stack == NULL || *stack == NULL || !((*stack)->next))
        return ;

    Next = (*stack)->next;
    Last = find_last_node((*stack));

    Last->next = (*stack);
    (*stack)->next = NULL;
    (*stack)->prev = Last;

    (*stack) = Next;
}

void stack_ra(t_stack **a)
{
    stack_rotate(a);
}

void stack_rb(t_stack **b)
{
    stack_rotate(b);
}

void stack_rr(t_stack **a, t_stack **b)
{
    stack_rotate(a);
    stack_rotate(b);
}
//Reverse_Rotate
static void stack_reverse_rotate(t_stack **stack)
{
    t_stack *Last;
    t_stack *new_Last;

    if(stack == NULL || *stack == NULL || !((*stack)->next))
        return ;
    Last = find_last_node((*stack));
    new_Last = Last->prev;
    Last->next = (*stack);
    Last->prev = NULL;
    new_Last->next = NULL;

    (*stack) = Last;
}

void stack_rra(t_stack **a)
{
    stack_reverse_rotate(a);
}

void stack_rrb(t_stack **b)
{
    stack_reverse_rotate(b);
}

void stack_rrr(t_stack **a, t_stack **b)
{
    stack_reverse_rotate(a);
    stack_reverse_rotate(b);
}