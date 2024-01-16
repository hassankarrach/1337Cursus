/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:38:15 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/16 09:53:09 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_empty_or_whitespace(char *str)
{
	char	*trimmed;
	int		result;

	trimmed = ft_strtrim(str, " ");
	result = (ft_strlen(trimmed) == 0);
	free(trimmed);
	return (result);
}

static int	ft_count_words(const char *s, char c)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			counter++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (counter);
}

static int	check_args_and_push(char *arg, t_stack **a)
{
	long	value;

	if (!arg)
		return (0);
	if (!ft_isdigit(arg))
		return (0);
	value = ft_atol(arg);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	if (ft_check_duplicated(*a, value))
		return (0);
	append_node(a, new_node(value));
	return (1);
}

void	stack_init(char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	while (argv[i])
	{
		if (ft_count_words(argv[i], ' ') == 1)
		{
			if (check_args_and_push(argv[i], a) == 0)
				handle_error(a);
		}
		else
		{
			tmp = ft_split(argv[i], ' ');
			j = 0;
			while (tmp[j])
			{
				if (!check_args_and_push(tmp[j++], a))
					handle_error_with_free(tmp, a);
			}
			free_argv(tmp);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*next_line;
	int		len;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		if (is_empty_or_whitespace(argv[1]))
			bonus_only_error_print();
	stack_init(++argv, &a);
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
