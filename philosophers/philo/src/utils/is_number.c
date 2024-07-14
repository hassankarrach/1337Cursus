#include "../../includes/philo.h"

void is_only_numbers(char **av)
{
    int i;
    int j;

    i = 0;
    av++;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] == ' ')
            {
                j++;
                continue;
            }
            if (av[i][j] < '0' || av[i][j] > '9')
            {
                print_error("invalid arg!", 1);
            }
            j++;
        }    
        i++;
    }
}