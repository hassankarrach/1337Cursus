#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_stack{
    int index;
    int value;
    int cost_to_push;
    int is_in_top;
    struct s_stack *next;
    struct s_stack *prev;
    struct s_stack *targ;
} t_stack;

//Args_check
int     args_check(char **list);
//Stack_Utils
t_stack *new_node(int value);
t_stack *find_last_node(t_stack *head);
t_stack *higgest_node(t_stack *head);
t_stack *smallest_node(t_stack *head);
void    append_node(t_stack **head, t_stack *node);
int     stack_len(t_stack *head);
//Stack_actions
void    stack_sa(t_stack **a);
void    stack_sb(t_stack **b);
void    stack_ss(t_stack **a, t_stack **b);
void    stack_pa(t_stack **a, t_stack **b);
void    stack_pb(t_stack **b, t_stack **a);
void    stack_ra(t_stack **a);
void    stack_rb(t_stack **b);
void    stack_rr(t_stack **a, t_stack **b);
void    stack_rra(t_stack **a);
void    stack_rrb(t_stack **b);
void    stack_rrr(t_stack **a, t_stack **b);
//Stack_Sort
int     is_sorted(t_stack *a);
void    stack_sort(t_stack **a, t_stack **b);
void    tiny_sort(t_stack **head);

#endif