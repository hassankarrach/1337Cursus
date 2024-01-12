/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:47:09 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/12 14:21:56 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2 && *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}


void	commands_cmp(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		stack_pa(a, b, 1);
	else if (!ft_strcmp(cmd, "pb\n"))
		stack_pb(b, a, 1);
	else if (!ft_strcmp(cmd, "sa\n"))
		stack_sa(a, 1);
	else if (!ft_strcmp(cmd, "sb\n"))
		stack_sb(b, 1);
	else if (!ft_strcmp(cmd, "ss\n"))
		stack_ss(a, b, 1);
	else if (!ft_strcmp(cmd, "ra\n"))
		stack_ra(a, 1);
	else if (!ft_strcmp(cmd, "rb\n"))
		stack_rb(b, 1);
	else if (!ft_strcmp(cmd, "rr\n"))
		stack_rr(a, b, 1);
	else if (!ft_strcmp(cmd, "rra\n"))
		stack_rra(a, 1);
	else if (!ft_strcmp(cmd, "rrb\n"))
		stack_rrb(b, 1);
	else if (!ft_strcmp(cmd, "rrr\n"))
		stack_rrr(a, b, 1);
	else
		handle_error_parsing(a, b);
}

int	ft_check_duplicated(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
