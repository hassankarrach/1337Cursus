/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:36:55 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/20 17:36:55 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if( lst == NULL)
		return;
	if( *lst == NULL)
	{
		*lst = new;
		return;
	}

	last = ft_lstlast(*lst);
	last->next = new;
}
