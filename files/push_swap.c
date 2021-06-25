#include <stdio.h>
#include "../push_swap.h"
//#include "../libft/libft.h"

int main(int argc, char *argv[])
{
	t_stack	*a1 = NULL;
	t_stack *a;

	if (argc < 2 || !valid_args(argc, argv))
		exit(0);
	if (valid_args(argc, argv) == -1)
		error_case("\033[0;33mError: invalid arguments\033[0m", -1);
	form_stack(&a1, argc, argv);
	a = a1;
	while (a)
	{
		if (a->prev)
			printf("[ prev -> %5d  |  ", a->prev->value);
		else
			printf("[ prev -> %5s  |  ", "NULL");
		printf("curr -> %5d  |  ", a->value);
		if (a->next)
			printf("next -> %5d ]\n", a->next->value);
		else
			printf("next -> %5s ]\n", "NULL");
		a = a->next;
	}
	printf("\n swap a :\n");
	swap_s(&a1);
	a = a1;
	while (a)
	{
		if (a->prev)
			printf("[ prev -> %5d  |  ", a->prev->value);
		else
			printf("[ prev -> %5s  |  ", "NULL");
		printf("curr -> %5d  |  ", a->value);
		if (a->next)
			printf("next -> %5d ]\n", a->next->value);
		else
			printf("next -> %5s ]\n", "NULL");
		a = a->next;
	}
	rotate_s(&a1);
	printf("\n rotate a :\n");
	a = a1;
	while (a)
	{
		if (a->prev)
			printf("[ prev -> %5d  |  ", a->prev->value);
		else
			printf("[ prev -> %5s  |  ", "NULL");
		printf("curr -> %5d  |  ", a->value);
		if (a->next)
			printf("next -> %5d ]\n", a->next->value);
		else
			printf("next -> %5s ]\n", "NULL");
		a = a->next;
	}
	reverse_rotate_s(&a1);
	printf("\n reverse rotate a :\n");
	a = a1;
	while (a)
	{
		if (a->prev)
			printf("[ prev -> %5d  |  ", a->prev->value);
		else
			printf("[ prev -> %5s  |  ", "NULL");
		printf("curr -> %5d  |  ", a->value);
		if (a->next)
			printf("next -> %5d ]\n", a->next->value);
		else
			printf("next -> %5s ]\n", "NULL");
		a = a->next;
	}
}
