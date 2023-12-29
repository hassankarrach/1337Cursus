#include "push_swap.h"

t_stack *new_node(int value)
{
    t_stack *node;
    int     index;

    node = (t_stack *)malloc(sizeof(t_stack));
    if(!node)
        return (NULL);
    node->value = value;
    node->index = index;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

t_stack *find_last_node(t_stack *head)
{
    if(!head)
        return (NULL);
    while(head->next)
    {
        head = head->next;
    }
    return (head);
}

void append_node(t_stack **head, t_stack *node)
{
    t_stack *last_node;
    if(head == NULL)
        return ;
    if(*head == NULL)
        *head = node;
    else
    {
        last_node = find_last_node(*head);
        last_node->next = node;
        node->prev = last_node;
    }
}

int stack_len(t_stack *head)
{
    int len;

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
