/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:42:46 by hkarrach          #+#    #+#             */
/*   Updated: 2024/02/13 05:54:42 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

static int	ft_count_words(const char *s, char c)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			counter++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (counter);
}

static char	**mem_error(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**split_helper(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	tab[ft_count_words(s, c)] = NULL;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		tab[k] = ft_substr(s + j, 0, i - j);
		if (!tab[k++])
			return (mem_error(tab));
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	return (split_helper(tab, s, c));
}
