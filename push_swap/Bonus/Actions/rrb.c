/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:24:17 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/08 16:36:06 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void stack_rrb(t_stack **b, int is_checker)
{
    stack_reverse_rotate(b);
    if(!is_checker)
        write(1, "rrb\n", 4);
}