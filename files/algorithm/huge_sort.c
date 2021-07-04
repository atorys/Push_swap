#include "../../push_swap.h"

void	check_next(t_algo	*params, t_info *process)
{
	int flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		if (process->head_a->next->pos == params->next_pos)
			swap_s(&process->head_a, &process, "sa\n");;
		if (process->head_a->pos == params->next_pos)
		{
			process->head_a->moves = -1;
			rotate_s(&process->head_a, &process, "ra\n");
			params->next_pos++;
			flag++;
//			visual(process);
		}
	}
}

void half_to_b(t_algo	*params, t_info *process)
{
	int		i;
	int 	moves;

	i = node_count(process->head_a);
	while (i-- > 0)
	{
		if (process->head_a->pos <= params->pivot)
			push_s(&process->head_a, &process->head_b, &process, "pb\n");
		else
			rotate_s(&process->head_a, &process, "ra\n");
	}
//	visual(process);
	moves = 0;
	while (node_count(process->head_b) && ++moves)
	{
		i = node_count(process->head_b);
		params->pivot = i / 2;
		while (i-- > 0)
		{
			if (process->head_b->pos >= params->pivot)
			{
				process->head_b->moves += moves;
				push_s(&process->head_b, &process->head_a, &process, "pa\n");
			}
			else
				rotate_s(&process->head_b, &process, "rb\n");
		}
//		visual(process);
	}
//	printf("next->pos %d", params->next_pos);
}

void main_sort(t_algo	*params, t_info *process)
{
	int	depth;
	int	i;
	int moves;

	depth = process->head_a->moves;
	while (depth >= 0)
	{
		while (depth == process->head_a->moves)
			push_s(&process->head_a, &process->head_b, &process, "pb\n");
//		visual(process);
		moves = 0;
		while (node_count(process->head_b) && ++moves)
		{
			i = node_count(process->head_b);
			params->pivot = ((i - params->next_pos) / 2) + params->next_pos;
//			printf("pivot = %d\n", params->pivot);
			while (i-- > 0)
			{
				if (process->head_b->pos >= params->pivot)
				{
					process->head_b->moves += moves;
					push_s(&process->head_b, &process->head_a, &process, "pa\n");
					check_next(params, process);
				}
				else
					rotate_s(&process->head_b, &process, "rb\n");
//				visual(process);
			}
//			visual(process);
		}
		depth = process->head_a->moves;
	}
}

void	huge_sort(t_info	*process)
{
	t_algo	params;

	params.next_pos = 0;
	params.max_pos = node_count(process->head_a) - 1;
	params.pivot = params.max_pos / 2;
	params.moves = 0;
	half_to_b(&params, process);
	check_next(&params, process);
//	printf("next->pos %d", params.next_pos);
	main_sort(&params, process);

}