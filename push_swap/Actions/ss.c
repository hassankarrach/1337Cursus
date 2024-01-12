/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:20:45 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/12 10:42:15 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_ss(t_stack **a, t_stack **b, int is_checker)
{
	stack_swap(a);
	stack_swap(b);
	if (!is_checker)
		write(1, "ss\n", 3);
}
