/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:00:50 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 14:05:44 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			counter++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (counter);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, n + 1);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 2));
	if (!tab)
		return (NULL);
	tab[k++] = ft_strndup("", 0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			tab[k++] = ft_strndup(s + j, i - j);
	}
	tab[k] = NULL;
	return (tab);
}
