#include "includes/push_swap.h"

static void	get_position_for_sorting(t_algo	*params, t_info *process);
static void	move_around_stacks(t_algo	*params, t_info *process);
static void	push_back_to_a(t_algo	*params, t_info *process);

/**
 * Sorting algorithm:
 * @sort 1] count down needed steps to move each element
 * @sort in its right position;
 * @sort 2] choose the element with minimum required movements;
 * @sort 3] spin around both stacks until element and its position
 * @sort have index = 0, then just push;
 * @sort 4] recalculate step1 and repeat steps2-3 until stack A is empty
 * @param process: stacks A and B, list of movements
 */
void	huge_sort(t_info	*process)
{
	t_algo	params;

	params.next_pos = NULL;
	params.max_pos = node_count(process->head_a) - 1;
	push_s(&process->head_a, &process->head_b, &process, "pb\n");
	while (process->head_a)
	{
		get_position_for_sorting(&params, process);
		move_around_stacks(&params, process);
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
	}
	push_back_to_a(&params, process);
}

static void	get_position_for_sorting(t_algo	*params, t_info *process)
{
	t_stack	*a;

	a = process->head_a;
	params->next_pos = process->head_a;
	while (a)
	{
		a->steps = count_steps(a->pos, process->head_b);
		if ((a->steps < 0 && a->index < 0) || (a->steps > 0 && a->index > 0))
		{
			if (a->steps * (1 - (2 * (a->steps < 0))) > \
			a->index * (1 - (2 * (a->index < 0))))
				a->total_moves = a->steps * (1 - (2 * (a->steps < 0)));
			else
				a->total_moves = a->index * (1 - (2 * (a->index < 0)));
		}
		else
			a->total_moves = a->steps * (1 - (2 * (a->steps < 0))) + \
			a->index * (1 - (2 * (a->index < 0)));
		if (a->total_moves < params->next_pos->total_moves)
			params->next_pos = a;
		a = a->next;
	}
}

static void	move_around_stacks(t_algo	*params, t_info *process)
{
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
		circulation(params->next_pos, process->head_a, process);
	while (params->next_pos->steps != 0)
	{
		if (params->next_pos->steps > 0 && params->next_pos->steps--)
			rotate_s(&process->head_b, &process, "rb\n");
		else if (params->next_pos->steps < 0 && params->next_pos->steps++)
			reverse_rotate_s(&process->head_b, &process, "rrb\n");
	}
}

static void	push_back_to_a(t_algo	*params, t_info *process)
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
		circulation(last, process->head_b, process);
	while (process->head_b)
		push_s(&process->head_b, &process->head_a, &process, "pa\n");
}
