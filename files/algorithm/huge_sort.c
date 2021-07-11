#include "../../push_swap.h"

void twisting(t_stack *moving_elem, t_stack	*head, t_info *process)
{
	if (moving_elem->index > 0)
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

static void push_edges_to_b(t_algo	*params, t_info *process)
{
	t_stack	*min;
	t_stack	*max;
	t_stack	*a;

	a = process->head_a;
	while (a)
	{
		if (a->pos == 0)
			min = a;
		if (a->pos == params->max_pos)
			max = a;
		a = a->next;
	}
	if (min->index * (1 - (2 * (min->index < 0))) >= max->index * (1 - (2 * (max->index < 0))) + 1)
	{
		while (max->index != 0)
			twisting(max, process->head_a, process);
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
		while (min->index != 0)
			twisting(min, process->head_a, process);
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
	}
	else
	{
		while (min->index != 0)
			twisting(min, process->head_a, process);
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
		while (max->index != 0)
			twisting(max, process->head_a, process);
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
	}
}

static int count_steps(int curr_pos, t_stack *where_to_put)
{
	t_stack			*b;
	t_stack			*result;

	b = where_to_put;
	if (b->pos > curr_pos) {
		while (b->next && b->pos > b->next->pos && b->pos > curr_pos)
			b = b->next;
		result = b;
	}
	else
	{
		result = b;
		while (b->next && b->pos > b->next->pos)
			b = b->next;
		if (b->next)
			b = b->next;
		while (b->next && b->pos > b->next->pos && b->pos > curr_pos)
			b = b->next;
		if (b->pos < curr_pos)
			result = b;
	}
	return (result->index);
}

static void insert_and_push(t_algo	*params, t_info *process)
{
	t_stack *a;

	while (process->head_a)
	{
		a = process->head_a;
		params->next_pos = process->head_a;
		while (a)
		{
			a->steps = count_steps(a->pos, process->head_b);
			if ((a->steps < 0 && a->index < 0)  || (a->steps > 0 && a->index > 0)) {
				if (a->steps * (1 - (2 * (a->steps < 0))) > a->index * (1 - (2 * (a->index < 0))))
					a->total_moves = a->steps * (1 - (2 * (a->steps < 0)));
				else
					a->total_moves = a->index * (1 - (2 * (a->index < 0)));
			}
			else
				a->total_moves = a->steps * (1 - (2 * (a->steps < 0))) + a->index * (1 - (2 * (a->index < 0)));
			if (a->total_moves < params->next_pos->total_moves)
				params->next_pos = a;
			a = a->next;
		}
		if (params->next_pos->index > 0 && params->next_pos->steps > 0)
		{
			while (params->next_pos->index != 0 && params->next_pos->steps != 0)
			{
				params->next_pos->steps--;
				rr(&process->head_a, &process->head_b, &process);
			}
		}
		else if (params->next_pos->index < 0 && params->next_pos->steps < 0)
		{
			while (params->next_pos->index != 0 && params->next_pos->steps != 0)
			{
				params->next_pos->steps++;
				rrr(&process->head_a, &process->head_b, &process);
			}
		}
		while (params->next_pos->index != 0)
			twisting(params->next_pos, process->head_a, process);
		while (params->next_pos->steps != 0)
		{
			if (params->next_pos->steps > 0 && params->next_pos->steps--)
				rotate_s(&process->head_b, &process, "rb\n");
			else if (params->next_pos->steps < 0 && params->next_pos->steps++)
				reverse_rotate_s(&process->head_b, &process, "rrb\n");
		}
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
	}
}

static void push_back_to_a(t_algo	*params, t_info *process)
{
	t_stack		*last;

	last = process->head_b;
	while (last)
	{
		if (last->pos == params->max_pos)
			break ;
		last = last->next;
	}
	while (last->index != 0)
	{
		if (last->index > 0)
			rotate_s(&process->head_b, &process, "rb\n");
		else
			reverse_rotate_s(&process->head_b, &process, "rrb\n");
	}
	while (process->head_b)
		push_s(&process->head_b, &process->head_a, &process, "pa\n");
}

void	huge_sort(t_info	*process)
{
	t_algo	params;

	params.next_pos = NULL;
	params.max_pos = node_count(process->head_a) - 1;
	params.count_a = node_count(process->head_a);
	params.count_b = 0;

	push_edges_to_b(&params, process);
	insert_and_push(&params, process);
	push_back_to_a(&params, process);
}