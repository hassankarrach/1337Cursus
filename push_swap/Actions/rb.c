/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:22:52 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/12 10:42:10 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_rb(t_stack **b, int is_checker)
{
	stack_rotate(b);
	if (!is_checker)
		write(1, "rb\n", 3);
}