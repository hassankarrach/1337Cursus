/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:03:37 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/11 14:03:38 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../Libft/Mini_Libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4

typedef struct s_stack
{
	int				index;
	int				value;
	int				cost_to_push;
	int				is_in_top;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*targ;
}					t_stack;

//------------GNL-----------------------
char				*get_next_line(int fd);
char				*read_line(int fd, char *str);
char				*get_the_rest(char *str);
char				*get_the_line(char *str);
int					ft_strchr(char *s, char c);
char				*ft_strjoin(char *s1, char *s2);
//--------------------------------------
//------------Stack_Utils--------------------------
t_stack				*new_node(int value);
t_stack				*find_last_node(t_stack *head);
void				append_node(t_stack **head, t_stack *node);
int					is_sorted(t_stack *a);
int					stack_len(t_stack *head);
//-------------------------------------------------
//------------Stack_actions------------------------
void				stack_sa(t_stack **a, int is_checker);
void				stack_sb(t_stack **b, int is_checker);
void				stack_ss(t_stack **a, t_stack **b, int is_checker);
void				stack_pa(t_stack **a, t_stack **b, int is_checker);
void				stack_pb(t_stack **b, t_stack **a, int is_checker);
void				stack_ra(t_stack **a, int is_checker);
void				stack_rb(t_stack **b, int is_checker);
void				stack_rr(t_stack **a, t_stack **b, int is_checker);
void				stack_rra(t_stack **a, int is_checker);
void				stack_rrb(t_stack **b, int is_checker);
void				stack_rrr(t_stack **a, t_stack **b, int is_checker);
void				stack_swap(t_stack **head);
void				stack_push(t_stack **dest, t_stack **src);
void				stack_rotate(t_stack **stack);
void				stack_reverse_rotate(t_stack **stack);
//------------------------------------------------
//------------Error_Handling----------------------
void				free_on_error(t_stack **a, char **argv, bool is_arc2);
void				free_stack(t_stack **head);
void				free_argv(char **argv);
void				commands_cmp(t_stack **a, t_stack **b, char *cmd);
int					ft_check_duplicated(t_stack *a, int nbr);
int					ft_isdigit(char *str);
//------------------------------------------------

#endif