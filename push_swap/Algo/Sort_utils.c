#include "../push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = higgest_node(*a);
	if (*a == highest_node)
		stack_ra(a, 0);
	else if ((*a)->next == highest_node)
		stack_rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		stack_sa(a, 0);
}
void Sort_five(t_stack **a, t_stack **b)
{
    while (stack_len(*a) > 3)
    {
        initialize(*a, *b);
        Finalize_ratation(a, smallest_node(*a), 'a');
        stack_pb(b, a, 0);
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
void Finish_sort(t_stack **a)
{
    t_stack *smallest;
    
    set_node_position(*a);
	smallest = smallest_node(*a);
	if (smallest->is_in_top)
		while (*a != smallest)
                stack_ra(a, 0);
	else
        while (*a != smallest)
                stack_rra(a, 0);
}