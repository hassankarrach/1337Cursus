#include "get_next_line.h"

char	*ft_join_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

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

char	*read_file(int fd, char *str)
{
	char	*Buffer;
	int		byte_readed;

	if (!str)
		str = ft_calloc(1, 1);
	// malloc buffer
	Buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_readed = 1;
	while (byte_readed > 0)
	{
		// while not EOF read
		byte_readed = read(fd, Buffer, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free(Buffer);
			return (NULL);
		}
		// 0 to end for leak
		Buffer[byte_readed] = 0;
		// join and free
		str = ft_join_free(str, Buffer);
		// quit if \n find
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str; //Full Str
	char		*line;//Final Line

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	line = extract_line(str);
	str = get_rest_of_line(str);
	return (line);
}
int main()
{
	int fd;
	int bytesReaded;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		printf("error!");

	printf("-%s", get_next_line(fd));
	printf("-%s", get_next_line(fd));
	printf("-%s", get_next_line(fd));
	printf("-%s", get_next_line(fd));
}