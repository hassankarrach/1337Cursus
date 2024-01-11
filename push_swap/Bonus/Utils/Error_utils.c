/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:02:04 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 14:02:16 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	free_argv(char **argv)
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
