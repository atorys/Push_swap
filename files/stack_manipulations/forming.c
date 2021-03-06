#include "includes/push_swap.h"
#include "../../libft/libft.h"

/**
 * create new node with type t_stack
 * @param digit: input value
 * @node {value : index | next}
 * @return created node
 */
static t_stack	*create_elem(int digit)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->index = digit;
	new->steps = 9999999;
	new->pos = -1;
	new->total_moves = 9999999;
	new->next = NULL;
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
	}
}

void 	form_stack(t_stack **head, int argc, char *argv[])
{
	int		i;
	int		j;
	char	**digit;
	t_stack	*node;

	i = 0;
	while (argc-- > 1)
	{
		j = -1;
		digit = ft_split(argv[++i], ' ');
		if (!digit || !digit[0])
			error_case(MALLOCERROR, -1);
		while (digit[++j])
		{
			node = create_elem((int)ft_atoi(digit[j]));
			if (!node)
				error_case(MALLOCERROR, -1);
			add_back(head, node);
			free(digit[j]);
		}
		free(digit);
	}
}

void	position_in_sorted_list(t_stack **head, int argc)
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
			if (temp->index > max && temp->pos == -1)
				max = temp->index;
			temp = temp->next;
		}
		temp = *head;
		while (temp->index != max)
			temp = temp->next;
		temp->pos = i;
	}
	indexing(head);
}

/**
 * preparation for sorting
 * @return t_info type
 */
t_info	*init_process(int argc, char *argv[])
{
	t_info	*process;

	process = NULL;
	process = malloc(sizeof(t_info));
	if (!process)
		return (NULL);
	process->operations = NULL;
	process->last_op = NULL;
	process->head_a = NULL;
	process->head_b = NULL;
	form_stack(&(process->head_a), argc, argv);
	if (argc == 2)
		argc = count_digits(argv[1], ' ') + 1;
	position_in_sorted_list(&(process->head_a), argc);
	return (process);
}
