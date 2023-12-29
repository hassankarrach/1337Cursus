#include "push_swap.h"

void tiny_sort(t_stack **head)
{
    t_stack *Highest = higgest_node(*head);
    if((*head)->value == Highest->value)
        {
            stack_ra(head);
        }
    else if((*head)->next->value == Highest->value)
        {
            stack_rra(head);
        }
    if((*head)->value > (*head)->next->value)
        {
            stack_sa(head);
        }
}