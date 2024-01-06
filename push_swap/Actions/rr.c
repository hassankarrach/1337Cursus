/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:23:11 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/06 10:43:35 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void stack_rr(t_stack **a, t_stack **b)
{
    stack_rotate(a);
    stack_rotate(b);
    write(1, "rr\n", 3);
}