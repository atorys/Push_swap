#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int 			val;
	struct t_stack	*next;
}				t_stack;

#endif
