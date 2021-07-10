#include "../../push_swap.h"

unsigned int	node_count(t_stack *head)
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
	t_stack			*temp;
	int				i;
	unsigned int	n_count;

	n_count = node_count(*head);
	i = 0;
	temp = *head;
	while (temp && i <= n_count / 2)
	{
		temp->index = i++;
		temp = temp->next;
	}
	i -= 1 + !(n_count % 2);
	while (temp)
	{
		temp->index = -1 * i--;
		temp = temp->next;
	}
}

void	find_last(t_stack **head, t_stack **last)
{
	*last = *head;
	while ((*last)->next)
		(*last) = (*last)->next;
}