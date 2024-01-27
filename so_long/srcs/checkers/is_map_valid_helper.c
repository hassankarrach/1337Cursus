#include "../../so_long.h"

int is_map_file_path_valid(char * file_path)
{
    char *file_path_ext;

    file_path_ext = ft_strrchr(file_path, '.');
    if(ft_strlen(file_path_ext) != 4)
        return (0);
    return (!ft_strncmp(file_path_ext, ".ber", 4));
}

int custom_strlen(char *line)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while(line[i])
    {
        if(line[i] != '\n')
            len++;
        i++;
    }
    return (len);
}

void is_line_components_valid(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if(line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'C' && line[i] != 'E' && line[i] != '\n')
        {
            ft_printf("invalid map components.\n");
            exit (1);
        }
        i++;
    }
}

int is_border_wall(char *line)
{
    int i;

    i = ft_strlen(line);
    if(line[--i] == '\n')
        i--;
    while(i >= 0)
    {
        if(line[i] != '1')
            return (0);
        i--;
    }
    return (1);
}

void is_line_valid(char *curr_line)
{
    int line_len;
    
    is_line_components_valid(curr_line);

    line_len = custom_strlen(curr_line);
    if(curr_line[0] != '1' || curr_line[line_len - 1] != '1')
    {
        ft_printf("unvalid map pattern.\n");
        exit(1);
    }
}