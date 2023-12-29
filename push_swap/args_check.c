#include "push_swap.h"

static int	ft_isdigit(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while(str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int ft_check_range(char *str)
{
	long n;

	n = ft_atol(str);
	if (!(n >= -2147483648 && n <= 2147483647))
	{
		return (0);
	}
	return (1);
}

static int ft_check_duplicated(char **list)
{
	int i;
	int j;
	int tmp;
	int curr;

	i = 0;
	while(list[i])
	{
		curr = ft_atol(list[i]);

		j = i + 1;
		while(list[j])
		{
			tmp = ft_atol(list[j]);
			if(curr == tmp)
				return (1);
			j++;
		}
		i++;
	}

	return (0);
}

int args_check(char **list)
{
	int i;

	i = 0;
	while(list[i])
	{
		if(!ft_isdigit(list[i]))
			return (0);
		if(!ft_check_range(list[i]))
			return (0);
		i++;
	}

	if(ft_check_duplicated(list))
		return (0);
	return (1);
}