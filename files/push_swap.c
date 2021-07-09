#include <stdio.h>
#include "../push_swap.h"
#include "../libft/libft.h"

void	visual(t_info *process)
{
	t_stack	*a = NULL;
	t_stack	*b = NULL;

	a = process->head_a;
	b = process->head_b;
	printf("\nA: ");
	while (a)
	{
		if (a->moves == 0)
			printf("\033[0;31m%-2d\033[0m(%d)| ", a->pos, a->steps_a);
		if (a->moves > 0)
			printf("%-2d(%d)| ", a->pos, a->steps_a);
		if (a->moves < 0)
			printf("\033[1;32m%-2d\033[0m(%d)| ", a->pos, a->steps_a);
		a = a->next;
	}
	printf("\nB: ");
	while (b)
	{
		printf("%-2d| ", b->pos);
		b = b->next;
	}
	printf("\n");
//	printf("%s", process->commands);
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

void	pick_up_algorithm(t_info *process)
{
	if (node_count(process->head_a) == 2)
		sort_just_two(process);
	else if (node_count(process->head_a) == 3)
		sort_three(process);
	else if (node_count(process->head_a) == 4)
		sort_four(process, 0);
	else if (node_count(process->head_a) == 5)
		sort_five(process);
//	else
//		huge_sort(process);
}

int	main(int argc, char *argv[])
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

//	while (process->operations)
//	{
//		printf("%s", process->operations->command);
//		process->operations = process->operations->next;
//	}
//	printf("%s", process->commands);
//	visual(process);
}
