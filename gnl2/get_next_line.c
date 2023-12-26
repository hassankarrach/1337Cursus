#include "get_next_line.h"

char	*get_the_line(char *str)
{
	int i; //len until '\n'
	char *res;

	if(!str)
		return (NULL);
	i = 0;
	while(str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
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

char	*read_line(int fd, char *str)
{
	char	*buff;
	int		bytes_readed;

	bytes_readed = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (bytes_readed && !ft_strchr(str, '\n'))
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if(bytes_readed < 0)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[bytes_readed] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
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
	if(line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int main()
{
    int fd = open("text.txt", O_RDONLY);  
    char *line;

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd); 
    return 0;
}