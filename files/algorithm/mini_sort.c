#include "includes/push_swap.h"

void	sort_just_two(t_info *process)
{
	swap_s(&process->head_a, &process, "sa\n");
}

void	sort_three(t_info *process)
{
	t_stack	*node;

	node = process->head_a;
	if (node->next->pos > node->next->next->pos)
	{
		if (node->pos > node->next->next->pos && node->pos > node->next->pos)
			rotate_s(&process->head_a, &process, "ra\n");
		node = process->head_a;
		if (node->pos < node->next->pos)
			reverse_rotate_s(&process->head_a, &process, "rra\n");
	}
	node = process->head_a;
	if (node->pos > node->next->pos && !(node->pos < node->next->pos && \
			node->next->pos < node->next->next->pos))
	{
		if (node->pos > node->next->next->pos)
			rotate_s(&process->head_a, &process, "ra\n");
		else
			swap_s(&process->head_a, &process, "sa\n");
	}
}

void	sort_four(t_info *process, int min)
{
	t_stack	*node;

	node = process->head_a;
	while (node->pos != min)
		node = node->next;
	while (node->index != 0)
	{
		if (node->index > 0)
			rotate_s(&process->head_a, &process, "ra\n");
		else
			reverse_rotate_s(&process->head_a, &process, "rra\n");
	}
	push_s(&process->head_a, &process->head_b, &process, "pb\n");
	sort_three(process);
	push_s(&process->head_b, &process->head_a, &process, "pa\n");
}

void	sort_five(t_info *process)
{
	t_stack	*node;

	node = process->head_a;
	while (node->pos != 0)
		node = node->next;
	while (node->index != 0)
	{
		if (node->index > 0)
			rotate_s(&process->head_a, &process, "ra\n");
		else
			reverse_rotate_s(&process->head_a, &process, "rra\n");
	}
	push_s(&process->head_a, &process->head_b, &process, "pb\n");
	sort_four(process, 1);
	push_s(&process->head_b, &process->head_a, &process, "pa\n");
}
