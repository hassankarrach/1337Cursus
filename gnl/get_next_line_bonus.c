/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:50:49 by hkarrach          #+#    #+#             */
/*   Updated: 2023/12/27 02:19:18 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_the_line(char *str)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[len] != '\n' && str[len])
		len++;
	line = (char *)malloc(sizeof(char) * len + 2);
	if (!line)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_the_rest(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!res)
		return (NULL);
	i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*read_line(int fd, char *buffer)
{
	char	*line;
	int		read_byte;

	read_byte = 1;
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (read_byte > 0 && !ft_strchr(buffer, '\n'))
	{
		read_byte = read(fd, line, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		line[read_byte] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_the_line(str[fd]);
	str[fd] = get_the_rest(str[fd]);
	if (line[0] == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int main()
// {
// 	char *line;
// 	char *line2;
// 	int fd = open("text.txt", O_RDONLY);
// 	int fd2 = open("text2.txt", O_RDONLY);
// 	if(fd < 0)
// 	{
// 		printf("ERR\n");
// 		return (1);
// 	}
// 	while((line = get_next_line(fd)) != NULL && (line2 = get_next_line(fd2)) != NULL)
// 	{
// 		printf("%s", line);
// 		printf("%s", line2);
// 		free(line);
// 		free(line2);
// 	}

// }