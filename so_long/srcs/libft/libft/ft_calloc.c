/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:36:32 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/20 17:36:34 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elements_count, size_t element_size)
{
	void	*result;
	size_t	buffer_size;

	buffer_size = elements_count * element_size;
	if (elements_count > 0 && element_size > 0 && buffer_size
		/ elements_count != element_size)
		return (NULL);
	result = (void *)malloc(buffer_size);
	if (!result)
		return (NULL);
	else
		ft_bzero(result, buffer_size);
	return (result);
}
