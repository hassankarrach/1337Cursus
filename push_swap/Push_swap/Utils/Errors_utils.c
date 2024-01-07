#include "../push_swap.h"

//Free the Split allocations.
void    Free_array(char **argv)
{
	int	i;

	i = -1;
	if (!argv || !*argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

//Free the stack Nodes.
void    Free_stack(t_stack **head)
{
    t_stack *tmp;

    if(!*head || !head)
        return ;
    while(*head)
    {
        tmp = (*head)->next;
        free(head);
        *head = tmp;
    }
    *head = NULL;
}

void	Free_on_error(t_stack **a, char **argv, bool is_arc2)
{
	Free_stack(a);
	if (is_arc2)
		Free_array(argv);
	write(2, "Error\n", 6);
	exit(1);
}