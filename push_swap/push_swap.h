#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "./Libft/Mini_Libft/libft.h"

typedef struct s_stack{
    int index;
    int value;
    int cost_to_push;
    int is_in_top;
    struct s_stack *next;
    struct s_stack *prev;
    struct s_stack *targ;
} t_stack;

//------------Stack_Utils--------------------------
t_stack *new_node(int value);
t_stack *find_last_node(t_stack *head);
t_stack *higgest_node(t_stack *head);
t_stack *smallest_node(t_stack *head);
void    append_node(t_stack **head, t_stack *node);
int     stack_len(t_stack *head);
//-------------------------------------------------

//------------Stack_actions------------------------
void    stack_sa(t_stack **a, int is_checker);
void    stack_sb(t_stack **b, int is_checker);
void    stack_ss(t_stack **a, t_stack **b, int is_checker);
void    stack_pa(t_stack **a, t_stack **b, int is_checker);
void    stack_pb(t_stack **b, t_stack **a, int is_checker);
void    stack_ra(t_stack **a, int is_checker);
void    stack_rb(t_stack **b, int is_checker);
void    stack_rr(t_stack **a, t_stack **b, int is_checker);
void    stack_rra(t_stack **a, int is_checker);
void    stack_rrb(t_stack **b, int is_checker);
void    stack_rrr(t_stack **a, t_stack **b, int is_checker);
void    stack_swap(t_stack **head);
void    stack_push(t_stack **dest, t_stack **src);
void    stack_rotate(t_stack **stack);
void    stack_reverse_rotate(t_stack **stack);
//------------------------------------------------

//------------Stack_Sort--------------------------
int     is_sorted(t_stack *a);
void    stack_sort(t_stack **a, t_stack **b);
void    tiny_sort(t_stack **head);
void    Sort_five(t_stack **a, t_stack **b);
t_stack *get_cheapest(t_stack *b);
void    Finish_sort(t_stack **a);
void    Finalize_ratation(t_stack **head, t_stack *node, char stack_name);

void    set_node_target(t_stack *a, t_stack *b);
void    set_node_position(t_stack *stack);
void    set_node_cost(t_stack *a, t_stack *b);
void    initialize(t_stack *a, t_stack *b);
void    stack_init(char **argv, t_stack **a, int argc);
//------------------------------------------------

//------------Error_Handling----------------------
void	Free_on_error(t_stack **a, char **argv, bool is_arc2);
void    Free_stack(t_stack **head);
void    Free_argv(char **argv);
int     ft_check_duplicated(t_stack *a, int nbr);
int     ft_isdigit(char *str);
//------------------------------------------------

#endif