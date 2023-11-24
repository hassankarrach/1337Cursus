#include <stdio.h>
#include <stdlib.h>

typedef struct s_list{
    int content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(int content)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if(!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return (node);
}

void print_nodes(t_list *lst)
{
    while(lst)
    {
        printf("%d -> ", lst->content);
        lst = lst->next;
    }
    printf("\n");
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
   if(lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int nodes_count(t_list *head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}
t_list *ft_lstlast(t_list *lst)
{
    while(lst->next)
        lst = lst->next;
    return(lst);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    if(!*lst)
    {
        *lst = new;
        return;
    }
    t_list *lastNode = ft_lstlast(*lst);
    lastNode->next = new;
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if( !lst || !del)
		return;
	del(lst->content);
	free(lst);
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *currNode;
    t_list *nextNode;

    currNode = *lst;
    while(currNode)
    {
        nextNode = currNode->next;
        del(currNode->content);
        free(currNode);
        currNode = currNode-> next;
    }
    *lst = NULL;
}
void f(void *lst)
{
    t_list *d = (t_list *)lst;
    (d->content)++;
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    while(lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}

int main()
{
    t_list *node3, *node2, *node1, *node4, *node5;
    node3 = ft_lstnew(3);
    node2 = ft_lstnew(2);
    node1 = ft_lstnew(1);
    node4 = ft_lstnew(4);
    node5 = ft_lstnew(5);
    

    // ft_lstadd_front(&node5, node1);
    // ft_lstadd_front(&node5, node1);
    // ft_lstadd_front(&node5, node1);
    // ft_lstadd_front(&node5, node1);

    ft_lstadd_back(&node1, node2);
    ft_lstadd_back(&node1, node3);
    ft_lstadd_back(&node1, node4);
    ft_lstadd_front(&node1, node5);
    // ft_lstdelone(node5);
    
    ft_lstiter(node1, f);

    // Print the modified list
    printf("Nodes Are : \n");
    print_nodes(node1);
    printf("Nodes count : %d\n", nodes_count(node1));
}