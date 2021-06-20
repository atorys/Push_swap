#include <stdio.h>
#include "../push_swap.h"
#include "../libft/libft.h"

t_stack	*create_elem(int digit)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new)
		write(2, "Error", 5);
	new->value = digit;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **a, t_stack *new)
{
	t_stack *temp;

	if (*a == NULL)
		*a = new;
	else
	{
		temp = (*a);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	form_stack(t_stack **pointer, int argc, char *argv[])
{
	int 	i;

	i = 0;
	while (argc-- > 1)
		add_back(pointer, create_elem(ft_atoi(argv[++i])));
}

int main(int argc, char *argv[])
{
	t_stack *a;

	if (!valid_args(argc, argv))
		error_case("\033[0;33mError: invalid arguments\033[0m", -1);
	form_stack(&a, argc, argv);
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return 0;
}
