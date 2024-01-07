/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:24:43 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/06 10:44:01 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void stack_rrr(t_stack **a, t_stack **b)
{
    stack_reverse_rotate(a);
    stack_reverse_rotate(b);
    write(1, "rrr\n", 4);
}