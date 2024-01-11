/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:38:15 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 14:01:18 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void	stack_init(char **argv, t_stack **a, int argc)
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
	char	*next_line;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(++argv, &a, argc == 2);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		commands_cmp(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
}
