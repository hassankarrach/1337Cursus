#include "checker.h"
static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2
		&& *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}
static void	Handle_error(t_stack **a, t_stack **b)
{
	Free_stack(a);
	Free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
void	Commands_cmp(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		stack_pa(a, b, 1);
	else if (!ft_strcmp(cmd, "pb\n"))
		stack_pb(b, a, 1);
	else if (!ft_strcmp(cmd, "sa\n"))
		stack_sa(a, 1);
	else if (!ft_strcmp(cmd, "sb\n"))
		stack_sb(b, 1);
	else if (!ft_strcmp(cmd, "ss\n"))
		stack_ss(a, b, 1);
	else if (!ft_strcmp(cmd, "ra\n"))
		stack_ra(a, 1);
	else if (!ft_strcmp(cmd, "rb\n"))
		stack_rb(b, 1);
	else if (!ft_strcmp(cmd, "rr\n"))
		stack_rr(a, b, 1);
	else if (!ft_strcmp(cmd, "rra\n"))
		stack_rra(a, 1);
	else if (!ft_strcmp(cmd, "rrb\n"))
		stack_rrb(b, 1);
	else if (!ft_strcmp(cmd, "rrr\n"))
		stack_rrr(a, b, 1);
	else
		Handle_error(a, b);
}
