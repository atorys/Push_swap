#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define ERROR "Error\n"
# define MALLOCERROR "\033[0;33mMalloc failed\033[0m\n"

/**
 * prototype for node of linked list
 * @fields pos : position in sorted array
 * @fields index : index in current array
 * @fields steps : index in other array
 * @fields total mpves : needed to move element in right order in
 * @fields next : pointer to next node
 * @prototype value | [index] | next
 */
typedef struct s_stack
{
	int				pos;
	int				index;
	int				steps;
	unsigned int	total_moves;
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
 * @fields head_a : linked list A
 * @fields head_b : linked list B
 */
typedef struct s_info
{
	t_cmd			*operations;
	t_cmd			*last_op;
	struct s_stack	*head_a;
	struct s_stack	*head_b;
}				t_info;

typedef struct s_algo
{
	unsigned int	max_pos;
	t_stack			*next_pos;
}				t_algo;

void			error_case(char *message, int number);
int				valid_args(int argc, char *argv[]);

t_info			*init_process(int argc, char *argv[]);
void			form_stack(t_stack **head, int argc, char *argv[]);
void			position_in_sorted_list(t_stack **head, int argc);
void			add_cmd(t_info **process, char *operation);

unsigned int	node_count(t_stack *head);
void			indexing(t_stack **head);
int				count_digits(char const *s, char c);
void			circulation(t_stack *moved_elem, t_stack *head, \
				t_info *process);
int				count_steps(int curr_pos, t_stack *where_to_put);

void			swap_s(t_stack **a, t_info **process, char *operation);
void			rotate_s(t_stack **a, t_info **process, char *operation);

void			reverse_rotate_s(t_stack **a, t_info **process, \
				char *operation);

void			push_s(t_stack **src, t_stack **dest, \
				t_info **process, char *operation);

void			ss(t_stack **a, t_stack **b, t_info **process);
void			rr(t_stack **a, t_stack **b, t_info **process);
void			rrr(t_stack **a, t_stack **b, t_info **process);

void			sort_just_two(t_info *process);
void			sort_three(t_info *process);
void			sort_four(t_info *process, int min);
void			sort_five(t_info *process);
void			huge_sort(t_info *process);

#endif
