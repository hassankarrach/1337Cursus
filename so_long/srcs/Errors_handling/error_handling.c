#include "../../so_long.h"

void    error_handle(char *error_name)
{
    ft_printf("%s\n", error_name);
    exit(1);
}