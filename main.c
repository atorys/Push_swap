#include <stdio.h>
#include "push_swap.h"

t_stack	*create_elem(int digit)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new)
		write(2, "Error", 5);
	new->val = digit;
	new->next = NULL;
	return (new);
}

t_stack	*stack_new(int argc, char *argv[])
{
	t_stack *c;


}

int main(int argc, char *argv[])
{
	t_stack *a;

	a = stack_new(argc, argv);
	return 0;
}
