/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:01:25 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/16 09:27:32 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Free the Split allocations.
void	free_argv(char **argv)
{
	int	i;

	if (!argv || !*argv)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
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

void	handle_error(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	handle_error_with_free(char **tmp, t_stack **a)
{
	free_argv(tmp);
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	only_error_print(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
