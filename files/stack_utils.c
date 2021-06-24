#include "../push_swap.h"
#include "../libft/libft.h"

t_stack	*create_elem(int digit)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new) /** todo: protect malloc */
		error_case("\033[0;33mMalloc failed", -1);
	new->value = digit;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_back(t_stack **a, t_stack *new)
{
	t_stack	*temp;

	if (*a == NULL)
		*a = new;
	else
	{
		temp = (*a);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void	form_stack(t_stack **pointer, int argc, char *argv[])
{
	int	i;

	i = 0;
	while (argc-- > 1)
		add_back(pointer, create_elem(ft_atoi(argv[++i])));
}
