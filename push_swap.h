#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int 			value;
	struct s_stack	*next;
}				t_stack;

void	error_case(char *message, int number);
int		valid_args(int argc, char *argv[]);

#endif
