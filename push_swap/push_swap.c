#include "push_swap.h"

void stack_init(char **argv, t_stack **a, int argc)
{
    int i;
    long Value;

    i = 0;
    while(argv[i])
    {
        if(!ft_isdigit(argv[i]))
            Free_on_error(a, argv, 2 == argc);
        Value = ft_atol(argv[i]);
        if(Value > INT_MAX || Value < INT_MIN)
            Free_on_error(a, argv, 2 == argc);
        if(ft_check_duplicated((*a), (int)Value))
            Free_on_error(a, argv, 2 == argc);
        append_node(a, new_node(Value));
        i++;
    }
    if (argc)
    	Free_argv(argv);
}
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if(argc == 1 || (argc == 2 && !argv[1][0])) //./push_swap 
        return (1);
    else if(argc == 2)
        argv = ft_split(argv[1], ' ');
    argv++;
    stack_init(argv, &a, argc == 2);
    if(!is_sorted(a))
    {
        if(stack_len(a) == 2)
            stack_sa(&a, 0);
        else if(stack_len(a) == 3)
            tiny_sort(&a);
        else
            stack_sort(&a, &b);
    }
    Free_stack(&a);
}
