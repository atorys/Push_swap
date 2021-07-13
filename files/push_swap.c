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
}
