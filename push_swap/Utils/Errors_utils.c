/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:01:25 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 14:13:04 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Free the Split allocations.
void	free_argv(char **argv)
{
	int	i;

	if (!argv || !*argv)
		return ;
	i = -1;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

// Free the stack Nodes.
void	free_stack(t_stack **head)
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

void	free_on_error(t_stack **a, char **argv, bool is_arc2)
{
	free_stack(a);
	if (is_arc2)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}
