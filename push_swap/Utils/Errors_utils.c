#include "../push_swap.h"

//Free the Split allocations.
void    Free_argv(char **argv)
{
	int	i;
	
	if (!argv || !*argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

//Free the stack Nodes.
void    Free_stack(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*current;

	if (NULL == head)
		return ;
	current = *head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*head = NULL;
}

void	Free_on_error(t_stack **a, char **argv, bool is_arc2)
{
	Free_stack(a);
	if (is_arc2)
		Free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}