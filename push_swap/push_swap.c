/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:11:21 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 14:11:38 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(char **argv, t_stack **a, int argc)
{
	int		i;
	long	value;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			free_on_error(a, argv, 2 == argc);
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			free_on_error(a, argv, 2 == argc);
		if (ft_check_duplicated((*a), (int)value))
			free_on_error(a, argv, 2 == argc);
		append_node(a, new_node(value));
		i++;
	}
	if (argc)
		free_argv(argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	argv++;
	stack_init(argv, &a, argc == 2);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			stack_sa(&a, 0);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			stack_sort(&a, &b);
	}
	free_stack(&a);
}
