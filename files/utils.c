#include "includes/push_swap.h"
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

int	count_digits(char const *s, char c)
{
	int	count;
	int	i;
	int	k;

	count = 0;
	i = 0;
	if (!ft_strchr(s, c))
		return (1);
	while (s[i])
	{
		k = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i + k] != '\0' && s[i + k] != c)
			k++;
		if (k > 0)
			count++;
		i += k;
	}
	return (count);
}
