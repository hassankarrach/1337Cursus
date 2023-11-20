/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:36:36 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/20 17:36:37 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
	return ((c>='a' && c<='z')||(c>='A' && c<='Z'));
}
int ft_isdigit(int c)
{
	return (c>='0' && c<='9');
}


int ft_isalnum(int c)
{
	return(ft_isalpha(c) || ft_isdigit(c));
}
