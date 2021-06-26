#include "../push_swap.h"
#include "../libft/libft.h"

t_stack	*create_elem(int digit)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = digit;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_back(t_stack **head, t_stack *new)
{
	t_stack	*temp;

	if (*head == NULL)
		*head = new;
	else
	{
		temp = (*head);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void 	form_stack(t_stack **head, int argc, char *argv[])
{
	int		i;
	t_stack *node;

	i = 0;
	while (argc-- > 1)
	{
		node = create_elem((int)ft_atoi(argv[++i]));
		if (!node)
			; /** todo: make free*/
		add_back(head, node);
	}
}

int node_count(t_stack *head)
{
	t_stack	*temp;
	int	nodes;

	temp = head;
	nodes = 0;
	while (temp)
	{
		temp = temp->next;
		nodes++;
	}
	return (nodes);
}