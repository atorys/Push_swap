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
		temp->steps_a = i++;
		if (!temp->next)
			temp->steps_a = -1;
		temp = temp->next;
	}
}

void	find_last(t_stack **head, t_stack **last)
{
	*last = *head;
	while ((*last)->next)
		(*last) = (*last)->next;
}