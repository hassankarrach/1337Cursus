#include "get_next_line.h"

// typedef struct t_list{
// 	char *Line;
// 	struct t_list *Next;
// }



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

	line_len = 0;
	while(str[line_len] != '\n' && str[line_len])
	{
		line_len++;
	}

	printf("%d\n", line_len);
	return (NULL);
}

char	*get_exact_line(int fd,char *buff)
{
	char *line;

	line = NULL;
	read(fd, buff, 9);
	line = ft_strjoin(line, buff);

	while(!check_the_end_of_line(buff))
	{
		read(fd, buff, 9);
		line = ft_strjoin(line, buff);
	}
	return (line);
}

int main()
{
	int fd;
	int bytesReaded;
	char *buff;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		printf("error!");

	buff = malloc(sizeof(char) * 10);
	if(!buff)
		return (0);

	extract_line(get_exact_line(fd, buff));
}