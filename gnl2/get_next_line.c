#include "get_next_line.h"

int check_the_end_of_line(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if(buff[i] != '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

char	*extract_line(char *str)
{
	char *final_line;
	int line_len;
	int i;

	line_len = 0;
	i = 0;
	while(str[line_len] != '\n' && str[line_len]) //get \n index.
		line_len++;

	line_len++; //add \n also.
	final_line = malloc(sizeof(char) * line_len);
	while(str[line_len] && line_len)
	{
		final_line[i] = str[i];
		line_len--;
		i++;
	}
	final_line[i] = '\0';
	return (final_line);
}

char	*get_rest_of_line(char *str)
{
	char *final_line;
	int line_len;
	int full_len;
	int i;

	line_len = 0;
	full_len = 0;
	i = 0;
	while(str[line_len] != '\n' && str[line_len])
		line_len++;
	while(str[full_len])
		full_len++;
	final_line = malloc(sizeof(char) * (full_len - line_len));
	line_len++; //Skip \n

	while(str[line_len])
	{
		final_line[i] = str[line_len];
		i++;
		line_len++;
	}
	final_line[i]= '\0';
	return (final_line);
}

char	*get_next_line(int fd)
{
	static char *line;
	char *buff;

	buff = malloc(sizeof(char) * 10);
	if(!buff)
		return (0);

	line = NULL;
	read(fd, buff, 9);
	line = ft_strjoin(line, buff);

	while(!check_the_end_of_line(buff))
	{
		read(fd, buff, 9);
		line = ft_strjoin(line, buff);
	}
	return (extract_line(line));
}

int main()
{
	int fd;
	int bytesReaded;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		printf("error!");

	printf("\n-%s", get_next_line(fd));
	// printf("\n-%s", get_next_line(fd));
}