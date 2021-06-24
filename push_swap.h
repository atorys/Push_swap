#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int 			value;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

void	error_case(char *message, int number);
int		valid_args(int argc, char *argv[]);

t_stack	*create_elem(int digit);
void	add_back(t_stack **a, t_stack *new);
void	form_stack(t_stack **pointer, int argc, char *argv[]);

#endif
