#include "../push_swap.h"
#include "../libft/libft.h"

/**
 * print error comment and exit
 * @param message : string with comment
 * @param number : user defined code for exit();
 */
void	error_case(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}

void	free_struct(t_stack **node)
{
	t_stack	*temp;
	t_stack	*being_freed;

	if ((*node)->prev)
		while ((*node)->prev)
			*node = (*node)->prev;
	temp = *node;
	while (temp)
	{
		being_freed = temp;
		free(being_freed);
		temp = temp->next;
	}
	*node = NULL;
}
