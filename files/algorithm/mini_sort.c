#include <stdio.h>
#include "../../push_swap.h"
#include "../../libft/libft.h"

void huge_sort(t_info	*process);

void	sort_just_two(t_info *process)
{
	swap_s(&process->head_a, &process, "sa\n");
}

void	sort_three(t_info *process)
{
	t_stack	*node;

	node = process->head_a;
	if (process->head_a->next->pos > process->head_a->next->next->pos) /** 321 132 231*/
	{
		if (process->head_a->pos > process->head_a->next->next->pos && \
			process->head_a->pos > process->head_a->next->pos)
			rotate_s(&process->head_a, &process, "ra\n");
		if (process->head_a->pos < process->head_a->next->pos)
			reverse_rotate_s(&process->head_a, &process, "rra\n");
	}
	if (process->head_a->pos > process->head_a->next->pos && \
			!(process->head_a->pos < process->head_a->next->pos && \
			process->head_a->next->pos < process->head_a->next->next->pos)) /** 213 312*/
	{
		if (process->head_a->pos > process->head_a->next->next->pos)
			rotate_s(&process->head_a, &process, "ra\n");
		else
			swap_s(&process->head_a, &process, "sa\n");
	}
}