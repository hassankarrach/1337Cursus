#include "../../so_long.h"

static void is_line_valid(char *line)
{
    int line_len;
    
    is_line_components_valid(line);

    line_len = custom_strlen(line);
    if(line[0] != '1' || line[line_len - 1] != '1')
    {
        printf("unvalid map pattern.\n");
        exit(1);
    }
}
static void check_line_length(char *curr_line)
{
    static int curr_line_len = 0;

    if(curr_line_len != custom_strlen(curr_line) && curr_line_len != 0)
    {
        printf("invalid map pattern.\n");
        exit (1);
    }
    curr_line_len = custom_strlen(curr_line);
}
static void check_map_component(char *full_line)
{
    int i;
    int c;
    int p;
    int e;

    i = 0;
    c = 0;
    p = 0;
    e = 0;
    while(full_line[i])
    {
        if(full_line[i] == 'C')
            c++;
        else if(full_line[i] == 'P')
            p++;
        else if(full_line[i] == 'E')
            e++;
        i++;
    }
    if(c < 1 || e != 1 || p != 1)
        error_handle("Invalid Map pattern (duplicated or not found map component).");
}
static void check_map_rect(int map_width, int map_heigth, t_map **map)
{
    if(!(map_width > map_heigth))
        error_handle("Invalid Map pattern (the map is not rectangular!).");
    (*map)->width = map_width * 60;
    (*map)->height = map_heigth * 60;
}
static void check_border_walls(char *curr_line, int *curr_border_wall_count)
{
    if((*curr_border_wall_count) == 0 && !is_border_wall(curr_line))
        error_handle("Invalid Map borders Wall pattern.");
    if((*curr_border_wall_count) == 2)
        error_handle("Invalid Map borders Wall pattern.");
    if(is_border_wall(curr_line))
        (*curr_border_wall_count)++;
}

void    is_map_valid(char * file_path, t_map *map)
{
    int     fd;
    char    *curr_line;
    char    *full_lines;
    int     lines_count;
    int     line_length;
    int     border_wall;

    full_lines = NULL;
    lines_count = 0;
    border_wall = 0;
    if(!is_map_file_path_valid(file_path) || (fd = open(file_path, O_RDONLY)) < 0)
        error_handle("Error processing the path or opening the file.");
    while((curr_line = get_next_line(fd)))
    {
        line_length = custom_strlen(curr_line);
        check_border_walls(curr_line, &border_wall);
        check_line_length(curr_line);
        is_line_valid(curr_line);
        lines_count++;
        full_lines = ft_strjoin(full_lines, curr_line);
    }
    check_map_component(full_lines);
    check_map_rect(line_length, lines_count, &map);
    map->map_lines = ft_split(full_lines, '\n');
}
