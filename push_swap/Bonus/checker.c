/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:38:15 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/08 17:28:57 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "checker.h"

static void stack_init(char **argv, t_stack **a, int argc)
{
    int i;
    long Value;

    i = 0;
    while(argv[i])
    {
        //Check Syntax.
        if(!ft_isdigit(argv[i]))
            Free_on_error(a, argv, 2 == argc);
        //Check Range.
        Value = ft_atol(argv[i]);
        if(Value > INT_MAX || Value < INT_MIN)
            Free_on_error(a, argv, 2 == argc);
        //Check Repetition.
        if(ft_check_duplicated((*a), (int)Value))
            Free_on_error(a, argv, 2 == argc);
        //Appending the value if OK.
        append_node(a, new_node(Value));
        i++;
    }
    if (argc)
    	Free_argv(argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*next_line;
	int		len;
	int		dummy;

    a = NULL;
    b = NULL;
    if(argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if(argc == 2)
        argv = ft_split(argv[1], ' ');
    else
        argv++;
    stack_init(argv, &a, argc == 2);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		Commands_cmp(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a) && stack_len(a) == len)
	{
		dummy = write(1, "OK\n", 3);
		(void)dummy;
	}
	else
	{
		dummy = write(1, "KO\n", 3);
		(void)dummy;
	}
	free(a);
}