#include "push_swap.h"

static void stack_init(char **argv, t_stack **a, int argc)
{
    int i;
    long Value;

    i = 0;
    while(argv[i])
    {
        //Check Syntax.
        if(!ft_isdigit(argv[i]))
            Free_on_error(a, argv, argc == 2);
        //Check Range.
        Value = ft_atol(argv[i]);
        if(Value > INT_MAX || Value < INT_MIN)
            Free_on_error(a, argv, argc == 2);
        //Check Repetition.
        if(ft_check_duplicated((*a), (int)Value))
            Free_on_error(a, argv, argc == 2);
        //Appending the value if OK.
        append_node(a, new_node(Value));
        i++;
    }
    if (argc == 2)
		Free_array(argv);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if(argc == 1 || argc == 2 && !argv[1][0])
        return (1);
    else if(argc == 2)
        argv = ft_split(argv[1], ' ');
    if(argc > 2) //Skip the Output file
        argv = &argv[1];
    stack_init(argv, &a, argc);
  
    if(!is_sorted(a))
    {
        if(stack_len(a) == 2)
            stack_sa(&a);
        else if(stack_len(a) == 3)
            tiny_sort(&a);
        else
            stack_sort(&a, &b);
    }
    Free_stack(&a);
}
