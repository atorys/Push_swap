#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
//# include <unistd.h>

# define ERROR "\033[0;33mError\033[0m\n"
# define MALLOCERROR "\033[0;33mMalloc failed\033[0m\n"

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
	int 			pos;
	int				index;
	int 			steps;
	unsigned int	total_moves;
	unsigned int 	been_moved;
	struct s_stack	*next;
}				t_stack;

typedef struct s_cmd
{
	char			*command;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

/**
 * general structure containing info
 * @fields commands : string
 * @fields head_a : doubly linked list A
 * @fields head_b : doubly linked list B
 */
typedef struct s_info
{
	t_cmd			*operations;
	t_cmd			*last_op;
	struct s_stack	*head_a;
	struct s_stack	*head_b;
//	t_stack			*tail_a;
//	t_stack			*tail_b;
}				t_info;

typedef struct s_algo
{
	unsigned int	max_pos;
	unsigned int 	count_a;
	unsigned int 	count_b;
	t_stack			*next_pos;
}				t_algo;

void	error_case(char *message, int number);
int		valid_args(int argc, char *argv[]);

t_info	*init_process(int argc, char *argv[]);

unsigned int	node_count(t_stack *head);
void			indexing(t_stack **head);
int				count_digits(char const *s, char c);
void			find_last(t_stack **head, t_stack **last);

void			swap_s(t_stack **a, t_info **process, char *operation);
void			rotate_s(t_stack **a, t_info **process, char *operation);
void			reverse_rotate_s(t_stack **a, t_info **process, char *operation);
void			push_s(t_stack **src, t_stack **dest, t_info **process, char *operation);
void			ss(t_stack **a, t_stack **b, t_info **process);
void			rr(t_stack **a, t_stack **b, t_info **process);
void			rrr(t_stack **a, t_stack **b, t_info **process);

void			sort_just_two(t_info *process);
void			sort_three(t_info *process);
void			sort_four(t_info *process, int min);
void			sort_five(t_info *process);
void			huge_sort(t_info *process);


void			visual(t_info *process);

#endif
