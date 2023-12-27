#include "push_swap.h"

static t_stack *new_node(int value)
{
    t_stack *node;
    int     index;

    node = (t_stack *)malloc(sizeof(t_stack));
    if(!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    
}