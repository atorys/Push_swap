#include "includes/push_swap.h"
#include "../../includes/get_next_line.h"
#include "../../libft/libft.h"

static int sorted(t_stack *a)
{
	unsigned int count;

	count = node_count(a) - 1;
	while (a && a->next)
	{
		if (a->pos < a->next->pos)
			count--;
		a = a->next;
	}
	return (count == 0);
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

static void run_cmd(t_info	*process, char *cmd)
{
	if (!ft_strncmp(cmd, "sa", 2))
		swap_s(&process->head_a, &process, NULL);
	else if (!ft_strncmp(cmd, "sb", 2))
		swap_s(&process->head_b, &process, NULL);
	else if (!ft_strncmp(cmd, "ss", 2))
		ss(&process->head_a, &process->head_b, &process);
	else if (!ft_strncmp(cmd, "pa", 2))
		push_s(&process->head_b, &process->head_a, &process, NULL);
	else if (!ft_strncmp(cmd, "pb", 2))
		push_s(&process->head_a, &process->head_b, &process, NULL);
	else if (!ft_strncmp(cmd, "ra", 2))
		rotate_s(&process->head_a, &process, NULL);
	else if (!ft_strncmp(cmd, "rb", 2))
		rotate_s(&process->head_b, &process, NULL);
	else if (!ft_strncmp(cmd, "rr", 2))
	{
		rotate_s(&process->head_a, &process, NULL);
		rotate_s(&process->head_b, &process, NULL);
	}
//		rr(&process->head_b, &process->head_b, &process);
	else if (!ft_strncmp(cmd, "rra", 3))
		reverse_rotate_s(&process->head_a, &process, NULL);
	else if (!ft_strncmp(cmd, "rrb", 3))
		reverse_rotate_s(&process->head_b, &process, NULL);
	else if (!ft_strncmp(cmd, "rrr", 3))
	{
		reverse_rotate_s(&process->head_a, &process, NULL);
		reverse_rotate_s(&process->head_b, &process, NULL);
	}
//		rrr(&process->head_a, &process->head_b, &process);
	else
		error_case("wtf", -2);
//	visual(process);
}
static void get_commands(t_info	*process)
{
	char *line;

	while (get_next_line(0, &line))
	{
		run_cmd(process, line);
		free(line);
	}
	free(line);
}

int	main(int argc, char *argv[])
{
	t_info	*process;

	if (argc < 2 || !valid_args(argc, argv))
		exit(0);
	if (valid_args(argc, argv) == -1)
		error_case(ERROR, -1);
	process = NULL;
	process = malloc(sizeof(t_info));
	if (!process)
		error_case(MALLOCERROR, -1);
	process->operations = NULL;
	process->last_op = NULL;
	process->head_a = NULL;
	process->head_b = NULL;
	form_stack(&(process->head_a), argc, argv);
	if (argc == 2)
		argc = count_digits(argv[1], ' ') + 1;
	position_in_sorted_list(&(process->head_a), argc);
	get_commands(process);
	if (sorted(process->head_a) && !process->head_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
