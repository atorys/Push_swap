#include <stdio.h>
#include "../push_swap.h"
#include "../libft/libft.h"

void pick_up_algorithm(t_info *process)
{
	if (node_count(process->head_a) == 2)
	{
		swap_s(&process->head_a);
		process->commands = ft_strjoin(process->commands, "sa\n");
	}
	if (node_count(process->head_a) == 3)
	{
		if (process->head_a->next->value > process->head_a->next->next->value) /** 321 132 231*/
		{
			if (process->head_a->value > process->head_a->next->next->value && \
			process->head_a->value > process->head_a->next->value)
			{
				rotate_s(&process->head_a);
				process->commands = ft_strjoin(process->commands, "ra\n");
			}
			if (process->head_a->value < process->head_a->next->value)
			{
				reverse_rotate_s(&process->head_a);
				process->commands = ft_strjoin(process->commands, "rra\n");
			}
		}
		if (process->head_a->value > process->head_a->next->value && \
			!(process->head_a->value < process->head_a->next->value && \
			process->head_a->next->value < process->head_a->next->next->value)) /** 213 312*/
		{
			if (process->head_a->value > process->head_a->next->next->value)
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
	t_stack	*a = NULL;
	t_stack *b = NULL;
	t_info	*process;

	if (argc < 2 || !valid_args(argc, argv))
		exit(0);
	if (valid_args(argc, argv) == -1)
		error_case(ERROR, -1);
	process = init_process(argc, argv); /** todo: free process*/
	if (!process)
		error_case(ERROR, -1);
//	a = process->head_a;
//	b = process->head_b;
//	printf("\nA: ");
//	while (a)
//	{
//		printf("%-2d| ", a->value);
//		a = a->next;
//	}
//	printf("\nB: ");
//	while (b)
//	{
//		printf("%-2d| ", b->value);
//		b = b->next;
//	}
//	printf("\n");
	pick_up_algorithm(process);
	printf("%s", process->commands);
//
//	a = process->head_a;
//	b = process->head_b;
//	printf("\nA: ");
//	while (a)
//	{
//		printf("%-2d| ", a->value);
//		a = a->next;
//	}
//	printf("\nB: ");
//	while (b)
//	{
//		printf("%-2d| ", b->value);
//		b = b->next;
//	}
//	printf("\n");

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
//	printf("\n B: \n");
//	for (int i = 0; i < 3; i++) {
//		push_s(&a1, &b); /** push B */
//		a = a1;
//		b1 = b;
//		printf("\n push b :\n A:\n");
//		while (a) {
//			if (a->prev)
//				printf("|%5d <- ", a->prev->value);
//			else
//				printf("|%5s <- ", "NULL");
//			printf("%2d ->", a->value);
//			if (a->next)
//				printf("%5d |\n", a->next->value);
//			else
//				printf("%5s |\n", "NULL");
//			a = a->next;
//		}
//		printf("\n B: \n");
//		while (b1) {
//			if (b1->prev)
//				printf("|%5d <- ", b1->prev->value);
//			else
//				printf("|%5s <- ", "NULL");
//			printf("%2d ->", b1->value);
//			if (b1->next)
//				printf("%5d |\n", b1->next->value);
//			else
//				printf("%5s |\n", "NULL");
//			b1 = b1->next;
//		}
//	}
//	for (int i = 0; i < 4; i++) {
//		push_s(&b, &a1); /** push B */
//		a = a1;
//		b1 = b;
//		printf("\n push a :\n A:\n");
//		while (a) {
//			if (a->prev)
//				printf("|%5d <- ", a->prev->value);
//			else
//				printf("|%5s <- ", "NULL");
//			printf("%2d ->", a->value);
//			if (a->next)
//				printf("%5d |\n", a->next->value);
//			else
//				printf("%5s |\n", "NULL");
//			a = a->next;
//		}
//		printf("\n B: \n");
//		while (b1) {
//			if (b1->prev)
//				printf("|%5d <- ", b1->prev->value);
//			else
//				printf("|%5s <- ", "NULL");
//			printf("%2d ->", b1->value);
//			if (b1->next)
//				printf("%5d |\n", b1->next->value);
//			else
//				printf("%5s |\n", "NULL");
//			b1 = b1->next;
//		}
//	}

//	while (a)
//	{
//		if (a->prev)
//			printf("[ prev -> %5d  |  ", a->prev->value);
//		else
//			printf("[ prev -> %5s  |  ", "NULL");
//		printf("curr -> %5d  |  ", a->value);
//		if (a->next)
//			printf("next -> %5d ]\n", a->next->value);
//		else
//			printf("next -> %5s ]\n", "NULL");
//		a = a->next;
//	}
//	printf("\n swap a :\n");
//	swap_s(&process->head_a);
//	a = process->head_a;
//	while (a)
//	{
//		if (a->prev)
//			printf("|%5d <- ", a->prev->value);
//		else
//			printf("|%5s <- ", "NULL");
//		printf("%2d ->", a->value);
//		if (a->next)
//			printf("%5d |\n", a->next->value);
//		else
//			printf("%5s |\n", "NULL");
//		a = a->next;
//	}
//	rotate_s(&a1);
//	printf("\n rotate a :\n");
//	a = a1;
//	while (a)
//	{
//		if (a->prev)
//			printf("|%5d <- ", a->prev->value);
//		else
//			printf("|%5s <- ", "NULL");
//		printf("%2d ->", a->value);
//		if (a->next)
//			printf("%5d |\n", a->next->value);
//		else
//			printf("%5s |\n", "NULL");
//		a = a->next;
//	}
//	reverse_rotate_s(&a1);
//	printf("\n reverse rotate a :\n");
//	a = a1;
//	while (a)
//	{
//		if (a->prev)
//			printf("[ prev -> %5d  |  ", a->prev->value);
//		else
//			printf("[ prev -> %5s  |  ", "NULL");
//		printf("curr -> %5d  |  ", a->value);
//		if (a->next)
//			printf("next -> %5d ]\n", a->next->value);
//		else
//			printf("next -> %5s ]\n", "NULL");
//		a = a->next;
//	}
}
