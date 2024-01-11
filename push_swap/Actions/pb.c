/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:21:55 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 12:05:01 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_pb(t_stack **b, t_stack **a, int is_checker)
{
	stack_push(b, a);
	if (!is_checker)
		write(1, "pb\n", 3);
}
