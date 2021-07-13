#include "includes/push_swap.h"

void	circulation(t_stack *moved_elem, t_stack	*head, t_info *process)
{
	if (moved_elem->index > 0)
	{
		if (head == process->head_a)
			rotate_s(&process->head_a, &process, "ra\n");
		else
			rotate_s(&process->head_b, &process, "rb\n");
	}
	else
	{
		if (head == process->head_a)
			reverse_rotate_s(&process->head_a, &process, "rra\n");
		else
			reverse_rotate_s(&process->head_b, &process, "rrb\n");
	}
}

static int	count_steps2(int curr_pos, t_stack *where_to_put, t_stack *b)
{
	unsigned int	count;
	t_stack			*result;

	count = node_count(where_to_put) - 1;
	result = b;
	while (b->next && b->pos > b->next->pos && count--)
		b = b->next;
	if (!b->next && !count)
		return (0);
	if (b->next)
		b = b->next;
	while (b->next && b->pos > b->next->pos && b->pos > curr_pos)
		b = b->next;
	if (b->pos < curr_pos)
		result = b;
	return (result->index);
}

int	count_steps(int curr_pos, t_stack *where_to_put)
{
	t_stack			*b;
	t_stack			*result;

	b = where_to_put;
	if (b->pos > curr_pos)
	{
		while (b->next && b->pos > b->next->pos && b->pos > curr_pos)
			b = b->next;
		if (b->pos < curr_pos)
			return (b->index);
		if (b && b->next && b->pos > curr_pos)
			return (b->next->index);
		result = b;
		if (!b->next && b->pos > curr_pos)
			return (0);
	}
	if (b->pos < curr_pos)
		return (count_steps2(curr_pos, where_to_put, b));
	return (result->index);
}
