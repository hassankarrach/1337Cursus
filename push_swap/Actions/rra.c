/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:23:31 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 12:05:44 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_rra(t_stack **a, int is_checker)
{
	stack_reverse_rotate(a);
	if (!is_checker)
		write(1, "rra\n", 4);
}
