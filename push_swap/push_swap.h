/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:11:45 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/16 09:24:10 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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

//------------Stack_Utils--------------------------
t_stack				*new_node(int value);
t_stack				*find_last_node(t_stack *head);
t_stack				*higgest_node(t_stack *head);
t_stack				*smallest_node(t_stack *head);
void				set_bigger_in_top(t_stack **b);
void				append_node(t_stack **head, t_stack *node);
int					stack_len(t_stack *head);
int					the_bigger(int index1, int index2);
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

//------------Stack_Sort--------------------------
int					is_sorted(t_stack *a);
void				stack_sort(t_stack **a, t_stack **b);
void				tiny_sort(t_stack **head);
void				sort_five(t_stack **a, t_stack **b);
t_stack				*get_cheapest(t_stack *b);
void				finish_sort(t_stack **a);
void				finalize_ratation(t_stack **head, t_stack *node,
						char stack_name);

void				set_node_target(t_stack *a, t_stack *b);
void				set_node_position(t_stack *stack);
void				set_node_cost(t_stack *a, t_stack *b);
void				set_node_cost_helper(t_stack *a, int a_len, int b_len);
void				initialize(t_stack *a, t_stack *b);
//------------------------------------------------

//------------Error_Handling----------------------
void				free_stack(t_stack **head);
void				free_argv(char **argv);
void				handle_error(t_stack **a);
void				handle_error_with_free(char **tmp, t_stack **a);
int					ft_check_duplicated(t_stack *a, int nbr);
int					ft_isdigit(char *str);
void				only_error_print(void);
//------------------------------------------------

//------------Libft_Files--------------------------
long				ft_atol(const char *str);
char				**ft_split(char const *s, char c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
//-------------------------------------------------
//------------GNL_SRCS-----------------------------
char				*ft_strjoin(char *s1, char *s2);
int					ft_strchr(char *s, char c);
char				*get_next_line(int fd);
//-------------------------------------------------
//------------BONUS_FILES--------------------------
void				commands_cmp(t_stack **a, t_stack **b, char *cmd);
void				handle_error_parsing(t_stack **a, t_stack **b);
//-------------------------------------------------

#endif