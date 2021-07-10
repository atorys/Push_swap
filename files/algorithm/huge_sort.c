#include "../../push_swap.h"

//void	check_next(t_algo	*params, t_info *process)
//{
//	int flag;
//
//	flag = 1;
//	while (flag)
//	{
//		flag = 0;
//		if (process->head_a->next->pos == params->next_pos)
//			swap_s(&process->head_a, &process, "sa\n");;
//		if (process->head_a->pos == params->next_pos)
//		{
//			process->head_a->moves = -1;
//			rotate_s(&process->head_a, &process, "ra\n");
//			params->next_pos++;
//			flag++;
////			visual(process);
//		}
//	}
//}
//
//void half_to_b(t_algo	*params, t_info *process)
//{
//	int		i;
//	int 	moves;
//
//	i = node_count(process->head_a);
//	while (i-- > 0)
//	{
//		if (process->head_a->pos <= params->pivot)
//			push_s(&process->head_a, &process->head_b, &process, "pb\n");
//		else
//			rotate_s(&process->head_a, &process, "ra\n");
//	}
////	visual(process);
//	moves = 0;
//	find_last(&process->head_b, &process->tail_b);
//	while (node_count(process->head_b) && ++moves)
//	{
//		i = node_count(process->head_b);
//		params->pivot = i / 2;
//		while (i-- > 0)
//		{
//			if (process->head_b->pos >= params->pivot)
//			{
//				process->head_b->moves += moves;
//				push_s(&process->head_b, &process->head_a, &process, "pa\n");
//			}
//			else
//				rotate_s(&process->head_b, &process, "rb\n");
//		}
////		visual(process);
//	}
////	printf("next->pos %d", params->next_pos);
//}
//
//void main_sort(t_algo	*params, t_info *process)
//{
//	int	depth;
//	int	i;
//	int moves;
//
//	depth = process->head_a->moves;
//	while (depth >= 0)
//	{
//		while (depth == process->head_a->moves)
//			push_s(&process->head_a, &process->head_b, &process, "pb\n");
////		visual(process);
//		moves = 0;
//		while (node_count(process->head_b) && ++moves)
//		{
//			i = node_count(process->head_b);
//			params->pivot = ((i - params->next_pos) / 2) + params->next_pos;
////			printf("pivot = %d\n", params->pivot);
//			while (i-- > 0)
//			{
//				if (process->head_b->pos >= params->pivot)
//				{
//					process->head_b->moves += moves;
//					push_s(&process->head_b, &process->head_a, &process, "pa\n");
//					check_next(params, process);
//				}
//				else
//					rotate_s(&process->head_b, &process, "rb\n");
////				visual(process);
//			}
////			visual(process);
//		}
//		depth = process->head_a->moves;
//	}
//}



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
//	printf("\nmax index -> %d\n", max->index);
//	printf("min index -> %d\n\n", min->index);
	if (min->index * (1 - (2 * (min->index < 0))) >= max->index * (1 - (2 * (max->index < 0))) + 1)
	{
		while (max->index != 0)
		{
			if (max->index > 0)
				rotate_s(&process->head_a, &process, "ra\n");
			else
				reverse_rotate_s(&process->head_a, &process, "rra\n");
		}
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
		while (min->index != 0)
		{
			if (min->index > 0)
				rotate_s(&process->head_a, &process, "ra\n");
			else
				reverse_rotate_s(&process->head_a, &process, "rra\n");
		}
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
//		swap_s(&process->head_b, &process, "sb\n");
	}
	else
	{
		while (min->index != 0)
		{
			if (min->index > 0)
				rotate_s(&process->head_a, &process, "ra\n");
			else
				reverse_rotate_s(&process->head_a, &process, "rra\n");
		}
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
		while (max->index != 0)
		{
			if (max->index > 0)
				rotate_s(&process->head_a, &process, "ra\n");
			else
				reverse_rotate_s(&process->head_a, &process, "rra\n");
		}
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
			a->total_moves = a->steps * (1 - (2 * (a->steps < 0))) + a->index * (1 - (2 * (a->index < 0)));
			if (a->total_moves < params->next_pos->total_moves)
				params->next_pos = a;
			a = a->next;
		}
//		visual(process);
//		printf(" next will be: %d\n", params->next_pos->pos);
//		while (params->next_pos->index != 0 && params->next_pos->steps != 0)
//		{
//			if (params->next_pos->index > 0 && params->next_pos->steps > 0 && params->next_pos->steps--)
//				rr(&process->head_a, &process->head_b, &process);
//			else if (params->next_pos->index < 0 && params->next_pos->steps < 0 && params->next_pos->steps++)
//				rrr(&process->head_a, &process->head_b, &process);
//		}
		while (params->next_pos->index != 0)
		{
			if (params->next_pos->index > 0)
				rotate_s(&process->head_a, &process, "ra\n");
			else
				reverse_rotate_s(&process->head_a, &process, "rra\n");
		}
		while (params->next_pos->steps != 0)
		{
			if (params->next_pos->steps > 0 && params->next_pos->steps--)
				rotate_s(&process->head_b, &process, "rb\n");
			else if (params->next_pos->steps < 0 && params->next_pos->steps++)
				reverse_rotate_s(&process->head_b, &process, "rrb\n");
		}
		push_s(&process->head_a, &process->head_b, &process, "pb\n");
//		visual(process);
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
//	half_to_b(&params, process);
//	check_next(&params, process);
//	printf("next->pos %d", params.next_pos);
//	main_sort(&params, process);

}