#include "../../push_swap.h"

int node_count(t_stack *head)
{
	t_stack	*temp;
	int	nodes;

	temp = head;
	nodes = 0;
	while (temp && ++nodes)
		temp = temp->next;
	return (nodes);
}

