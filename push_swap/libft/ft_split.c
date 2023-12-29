#include "libft.h"

static int ft_count_words(const char *s, char c) //Count The Words
{
	unsigned int i;
	int counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while(s[i] == c) //Skip the --C--.
			i++;
		if(s[i]) //Begening of the word.
			counter++;
		while (s[i] && (s[i] != c)) //move to the last of the word.
			i++;
	}
	return (counter);
}

static char *ft_strndup(const char *s, size_t n) //Alloc Memory for the required string.
{
	char *res;

	res = (char *)malloc(sizeof(char) * n + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, n + 1); // Copy the string
    return (res);
}

char **ft_split(char const *s, char c)
{
	char **tab;
	int i; //track string --s--.
	int j; //keep track the first of the word.
	int k; //track the element of the tab.

	if(!s)
		return (NULL);

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char*) * (ft_count_words(s, c)) + 1); //Alloc Array of char * + space fr NULL.
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while(s[i] == c) //Skip the --C--
			i++;
		j = i; //Mark the begening of the word.
		while (s[i] && s[i] != c) //Move to The last of the lettr.
			i++;
		if (i > j) 
		{
			tab[k] = ft_strndup(s + j, i-j); //Give it the pointer of the ltr and the length would be i -j;
			k++;//move to the next element of the tab;
		}	
	}
	tab[k] = NULL;
	return (tab);
}
