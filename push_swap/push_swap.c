#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int i;
    int Value;

    a = NULL;
    b = NULL;
    if(argc == 1 || argc == 2 && !argv[1][0])
    {
        printf("ERROR.\n");
        return (1);
    }
    else if(argc == 2)
        argv = ft_split(argv[1], ' ');

    if(argc > 2) //Skip the Output file
        argv = &argv[1];

    //Checks the args
    if(!args_check(argv))
    {
        printf("ERROR.\n");
        return (0);
    }
    //Add to the stack
    i = 0;
    while(argv[i])
    {
        Value = ft_atol(argv[i]);
        append_node(&a, new_node(Value));
        i++;
    }
   
    if(!is_sorted(a))
    {
        if(stack_len(a) == 2)
            stack_sa(&a);
        else if(stack_len(a) == 3)
            tiny_sort(&a);
        else
            stack_sort(&a, &b);
    }

    printf("\n--------A--------\n\n");
    while(a)
    {
        printf("     ---\n");
        printf("%d : |%d|\n",a->index, a->value);
        printf("     ---\n");
        a = a->next;
    }
    printf("\n--------B--------\n\n");
    while(b)
    {
        printf("     ---\n");
        printf("%d : |%d| --TARG--> %d . %d moves needed. IN TOP %d ?\n",b->index, b->value, b->targ->value, b->cost_to_push, b->is_in_top);
        printf("     ---\n");
        b = b->next;
    }
}