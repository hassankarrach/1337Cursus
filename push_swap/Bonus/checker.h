#ifndef CHECKER_H
# define CHECKER_H

# include "../Libft/Mini_Libft/libft.h"
# include "../Libft/Gnl/get_next_line.h"
# include "../push_swap.h"

int ft_check_duplicated(t_stack *a, int nbr);
int	ft_strchr(char *s, char c);
void	Commands_cmp(t_stack **a, t_stack **b, char *cmd);

#endif