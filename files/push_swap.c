#include "includes/push_swap.h"
#include "../libft/libft.h"


void	pick_up_algorithm(t_info *process)
{
	unsigned int	count;

	count = node_count(process->head_a);
	if (count == 2)
		sort_just_two(process);
	else if (count == 3)
		sort_three(process);
	else if (count == 4)
		sort_four(process, 0);
	else if (count == 5)
		sort_five(process);
	else
		huge_sort(process);
}

void	visual(t_info *process)
{
	t_stack	*a = NULL;
	t_stack	*b = NULL;

//	a = process->head_a;
//	b = process->head_b;
//	printf("\nA: ");
//	while (a)
//	{
//		printf("%-2d-> ", a->pos);
//		if (a->next)
//			printf("%-2d| ", a->next->pos);
//		else
//			printf("%s| ", "NULL");
//		a = a->next;
//	}
//	printf("\nB: ");
//	while (b)
//	{
//		printf("%-2d-> ", b->pos);
//		if (b->next)
//			printf("%-2d| ", b->next->pos);
//		else
//			printf("%s| ", "NULL");
//		b = b->next;
//	}
//	printf("\n");
	a = process->head_a;
	b = process->head_b;
	printf("\nA: ");
	while (a)
	{
		printf("%d) \033[1;32m%-2d \033[0m", a->index, a->pos);
//		printf(" (tb: %d, tt: %d, b: %d)      ", a->steps, a->total_moves, a->been_moved);
		a = a->next;
	}
	printf("\nB: ");
	while (b)
	{
		printf("%d) \033[1;32m%-2d \033[0m", b->index, b->pos);
//		printf(" (tb: %d, tt: %d)      ", b->steps, b->total_moves);
		b = b->next;
	}
	printf("\n");

}

int	main(int argc, char *argv[])
{
	t_info	*process;

	if (argc < 2 || !valid_args(argc, argv))
		exit(0);
	if (valid_args(argc, argv) == -1)
		error_case(ERROR, -1);
	process = init_process(argc, argv);
	if (!process)
		error_case(MALLOCERROR, -1);
	pick_up_algorithm(process);
	while (process->operations)
	{
		write(1, process->operations->command, \
		ft_strlen(process->operations->command));
		process->operations = process->operations->next;
	}
//	visual(process);
}
