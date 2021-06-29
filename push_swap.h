#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
//# include <unistd.h>

# define ERROR "\033[0;33mError\033[0m\n"

/**
 * prototype for node of doubly linked list
 * @fields value : integer
 * @fields index : index in sorted array
 * @fields next : pointer to next node
 * @fields prev : pointer to previous node
 * @prototype prev | value | [index] | next
 */
typedef struct s_stack
{
	int				value;
	int 			index;
	int 			pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

/**
 * general structure containing info
 * @fields commands : string
 * @fields head_a : doubly linked list A
 * @fields head_b : doubly linked list B
 */
typedef struct s_info
{
	char			*commands;
	struct s_stack	*head_a;
	struct s_stack	*head_b;
}				t_info;

void	error_case(char *message, int number);
int		valid_args(int argc, char *argv[]);

t_info	*init_process(int argc, char *argv[]);
void	huge_sort(t_info	*process);

int 	node_count(t_stack *head);

void	swap_s(t_stack **a);
void	rotate_s(t_stack **a);
void	reverse_rotate_s(t_stack **a);
void	push_s(t_stack **src, t_stack **dest);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
