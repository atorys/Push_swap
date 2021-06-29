#include "../../push_swap.h"
#include "../../libft/libft.h"

/**
 * create new node with type t_stack
 * @param digit: input value
 * @node {prev | value : index | next}
 * @return created node
 */
static t_stack	*create_elem(int digit)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = digit;
	new->index = -1;
	new->keep = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * add new node to the last element of stack
 * @param head: stack
 * @param new: node
 */
static void	add_back(t_stack **head, t_stack *new)
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

static void 	form_stack(t_stack **head, int argc, char *argv[])
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

static void indexing(t_stack **head, int argc)
{
	t_stack		*temp;
	long long	max;
	int			i;

	i = argc - 1;
	while (--i >= 0)
	{
		max = -2147483649;
		temp = *head;
		while (temp)
		{
			if (temp->value > max && temp->index == -1)
				max = temp->value;
			temp = temp->next;
		}
		temp = *head;
		while (temp->value != max)
			temp = temp->next;
		temp->index = i;
	}
}

t_info *init_process(int argc, char *argv[])
{
	t_info	*process;

	process = NULL;
	process = malloc(sizeof(t_info));
	if (!process)
		return (NULL);
	process->commands = ft_strdup("");
	if (!process->commands)
		return (NULL);
	process->head_a = NULL;
	process->head_b = NULL;
	form_stack(&(process->head_a), argc, argv); /** todo: node wasn't allocated*/
	indexing(&(process->head_a), argc);
	return (process);
}
