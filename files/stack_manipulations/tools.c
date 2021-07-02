#include "../../push_swap.h"

int	node_count(t_stack *head)
{
	t_stack	*temp;
	int		nodes;

	temp = head;
	nodes = 0;
	while (temp && ++nodes)
		temp = temp->next;
	return (nodes);
}

void	indexing(t_stack **head)
{
	t_stack		*temp;
	int			i;

	i = 0;
	temp = *head;
	while (temp)
	{
		temp->index = i++;
		if (!temp->next && temp->prev)
			temp->index = -1;
		temp = temp->next;
	}
}
