#include "get_next_line.h"

char	*get_the_line(char *str)
{
	int i;
	int len;
	char *line;

	i = 0;
	len = 0;
	if(!str)
		return (NULL);
	while(str[len] != '\n' && str[len])
		len++;
	line = (char *)malloc(len + 2);
	if(!line)
		return (NULL);
	while(str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if(str[i] == '\n')
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
	int		len;
	char	*res;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if(!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if(!str[i])
	{
		free(str);
		return (NULL);
	}

	res = malloc(sizeof(char) * (len - i));
	if (!res)
		return (NULL);

	i++; //Skip '\n'
	while (str[i])
	{
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';

	free(str);
	return (res);
}

char	*read_line(int fd, char *buffer)
{
	char	*line;
	int		read_byte;

	read_byte = 1;
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
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
	static char *str;
	char 		*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(fd, str);
	if(!str)
		return (NULL);
	line = get_the_line(str);
	str  = get_the_rest(str);
	if(line[0] == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int main()
// {
//     int fd = open("text.txt", O_RDONLY);  
//     char *line;

//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line: %s\n", line);
//         free(line);
//     }

//     close(fd); 
//     return 0;
// }