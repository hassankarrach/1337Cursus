/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:23:11 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/08 13:45:01 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void stack_rr(t_stack **a, t_stack **b, int is_checker)
{
    stack_rotate(a);
    stack_rotate(b);
    if(!is_checker)
        write(1, "rr\n", 3);
}