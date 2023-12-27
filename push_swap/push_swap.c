#include "push_swap.h"

int main(int argc, char **argv)
{
    int i = 1;
    int curr;
    while(i < argc)
    {
        curr = ft_atoi(argv[i]);
        printf("%d\n", curr - 10);
        i++;
    }
}