#include "../push_swap.h"

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

int is_sorted(t_stack *a)
{
    if(!a)
        return (0);
    while(a->next)
    {
        if(a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}

t_stack *get_cheapest(t_stack *b)
{
    t_stack *cheapest;
    int MAX;

    cheapest = NULL;
    MAX = 2147483647;
    if (!b)
        return (NULL);

    while(b)
    {
        if(b->cost_to_push < MAX)
        {
            cheapest = b;
            MAX = b->cost_to_push;
        }
        b = b->next;
    }

    return (cheapest);
}
