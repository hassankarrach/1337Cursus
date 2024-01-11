/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:02:34 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 14:02:57 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->cost_to_push = 0;
	node->is_in_top = 0;
	node->value = value;
	node->index = 0;
	node->targ = node;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

void	append_node(t_stack **head, t_stack *node)
{
	t_stack	*last_node;

	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	last_node = find_last_node(*head);
	last_node->next = node;
	node->prev = last_node;
}

int	is_sorted(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	stack_len(t_stack *head)
{
	int	len;

	len = 0;
	if (head == NULL)
		return (0);
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}
