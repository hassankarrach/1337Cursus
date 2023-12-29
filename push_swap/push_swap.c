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
        printf("ERROR\n");
        return (0);
    }
    //Add to the stack
    i = 0;
    while(argv[i])
    {
        Value = ft_atol(argv[i]);
        append_node(&a, new_node(Value));
        append_node(&b, new_node(Value));
        i++;
    }

    tiny_sort(&a);

    while(a)
    {
        printf("%d\n", a->value);
        a = a->next;
    }
    printf("\n----------------\n\n");
    while(b)
    {
        printf("%d\n", b->value);
        b = b->next;
    }



    // printf("total len of the stack : %d\n", stack_len(a));
}