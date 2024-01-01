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

static void set_nodes_index(t_stack *a, t_stack *b)
{
    int i;

    i = 0;
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

static void set_node_target(t_stack *a, t_stack *b)
{
    t_stack *target;
    t_stack *current_a;
    t_stack *SmallestNode;
    int the_diff;
    int tmp;

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

static void set_node_position(t_stack *a, t_stack *b)
{
    int a_len;
    int b_len;

    a_len = stack_len(a);
    b_len = stack_len(b);

    while(a)
    {
        if(a->index < (a_len/2 + 1))
            a->is_in_top = 1;
        a = a->next;
    }
    while(b)
    {
        if(b->index < (b_len/2 + 1))
            b->is_in_top = 1;
        b = b->next;
    }
}

static void set_node_cost(t_stack *a, t_stack *b)
{
    int b_len;
    int a_len;
    //Needs RECOOOOOOOOOODE.
    b_len = stack_len(b);
    a_len = stack_len(a);
    while(b)
    {
        b->cost_to_push = b->index;
        if(!b->is_in_top)
            b->cost_to_push = b_len - b->index;

        if(b->is_in_top)
            b->cost_to_push += b->targ->index;
        else
            b->cost_to_push += a_len - (b->targ->index);
        b = b->next;
    }
}

static t_stack *get_cheapest(t_stack *b)
{
    t_stack *cheapest;
    int MAX;

    cheapest = NULL;
    MAX = 2147483647;

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

static void push(t_stack **a, t_stack **b)
{
    t_stack *Node_to_push;
    Node_to_push = find_last_node((*a));

    while(*b)
    {

    }

    while(Node_to_push->targ->prev)
        stack_rb(a);

    if(Node_to_push->is_in_top && Node_to_push->targ->is_in_top)
    {

    }
    else
    {

    }
}

void stack_sort(t_stack **a, t_stack **b)
{
    int only_two;

    only_two = 0;
    //Push to stack b until 3 in a.
    while(stack_len(*a) > 3)
        stack_pb(b, a);
    //Sort 3 nodes in A.
    tiny_sort(a);
    //Set Target of each Node from B.
    set_node_target((*a), (*b));
    //Set Nodes Index
    set_nodes_index((*a), (*b));
    //set_nodes_position (top/bottom)
    set_node_position((*a), (*b));
    //Set Nodes Cost
    set_node_cost((*a), (*b));
    //Push from B to A.
    push(a, b);
}

