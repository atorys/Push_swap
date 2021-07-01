#include <stdio.h>
#include "../push_swap.h"
#include "../libft/libft.h"

void visual(t_info *process)
{
	t_stack	*a = NULL;
	t_stack *b = NULL;

	a = process->head_a;
	b = process->head_b;
	printf("\nA: ");
	while (a)
	{
		printf("%-2d| ", a->pos);
		a = a->next;
	}
	printf("\nB: ");
	while (b)
	{
		printf("%-2d| ", b->pos);
		b = b->next;
	}
	printf("\n");
	printf("%s", process->commands);
	//	a = process->head_a;
//	printf("A: ");
//	while (a)
//	{
//		if (a->prev)
//			printf("|%5d <- ", a->prev->value);
//		else
//			printf("|%5s <- ", "NULL");
//		printf("%2d ->", a->value);
//		if (a->next)
//			printf("%5d | \n", a->next->value);
//		else
//			printf("%5s |\n", "NULL");
//		a = a->next;
//	}
}

void pick_up_algorithm(t_info *process)
{
	if (node_count(process->head_a) == 2)
	{
		swap_s(&process->head_a);
		process->commands = ft_strjoin(process->commands, "sa\n");
	}
	if (node_count(process->head_a) == 3)
	{
		if (process->head_a->next->pos > process->head_a->next->next->pos) /** 321 132 231*/
		{
			if (process->head_a->pos > process->head_a->next->next->pos && \
			process->head_a->pos > process->head_a->next->pos)
			{
				rotate_s(&process->head_a);
				process->commands = ft_strjoin(process->commands, "ra\n");
			}
			if (process->head_a->pos < process->head_a->next->pos)
			{
				reverse_rotate_s(&process->head_a);
				process->commands = ft_strjoin(process->commands, "rra\n");
			}
		}
		if (process->head_a->pos > process->head_a->next->pos && \
			!(process->head_a->pos < process->head_a->next->pos && \
			process->head_a->next->pos < process->head_a->next->next->pos)) /** 213 312*/
		{
			if (process->head_a->pos > process->head_a->next->next->pos)
			{
				rotate_s(&process->head_a);
				process->commands = ft_strjoin(process->commands, "ra\n");
			}
			else
			{
				swap_s(&process->head_a);
				process->commands = ft_strjoin(process->commands, "sa\n");
			}
		}
	}
//	else
//		huge_sort(process);
}

int main(int argc, char *argv[])
{
	t_info	*process;

	if (argc < 2 || !valid_args(argc, argv))
		exit(0);
	if (valid_args(argc, argv) == -1)
		error_case(ERROR, -1);
	process = init_process(argc, argv); /** todo: free process*/
	if (!process)
		error_case(ERROR, -1);
	visual(process);
	pick_up_algorithm(process);
	visual(process);
}
