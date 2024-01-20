/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:34:56 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/16 17:17:46 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
//test
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
	else
	{
		last_node = find_last_node(*head);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	set_bigger_in_top(t_stack **b)
{
	t_stack	*biggest;

	set_node_position(*b);
	biggest = higgest_node(*b);
	if (biggest->is_in_top)
		while (*b != biggest)
			stack_rb(b, 0);
	else
		while (*b != biggest)
			stack_rrb(b, 0);
}

int	the_bigger(int index1, int index2)
{
	if (index1 > index2)
		return (index1);
	else
		return (index2);
}
