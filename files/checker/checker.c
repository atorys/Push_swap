#include "includes/push_swap.h"
#include "../../includes/get_next_line.h"
#include "../../libft/libft.h"

static int	sorted(t_stack *a)
{
	unsigned int	count;

	count = node_count(a) - 1;
	while (a && a->next)
	{
		if (a->pos < a->next->pos)
			count--;
		a = a->next;
	}
	return (count == 0);
}

static void	run_cmd(t_info	*process, char *cmd)
{
	if (!ft_strncmp(cmd, "sa", ft_strlen(cmd)))
		swap_s(&process->head_a, &process, NULL);
	else if (!ft_strncmp(cmd, "sb", ft_strlen(cmd)))
		swap_s(&process->head_b, &process, NULL);
	else if (!ft_strncmp(cmd, "ss", ft_strlen(cmd)))
		ss(&process->head_a, &process->head_b, &process);
	else if (!ft_strncmp(cmd, "pa", ft_strlen(cmd)))
		push_s(&process->head_b, &process->head_a, &process, NULL);
	else if (!ft_strncmp(cmd, "pb", ft_strlen(cmd)))
		push_s(&process->head_a, &process->head_b, &process, NULL);
	else if (!ft_strncmp(cmd, "ra", ft_strlen(cmd)))
		rotate_s(&process->head_a, &process, NULL);
	else if (!ft_strncmp(cmd, "rb", ft_strlen(cmd)))
		rotate_s(&process->head_b, &process, NULL);
	else if (!ft_strncmp(cmd, "rr", ft_strlen(cmd)))
		rr(&process->head_a, &process->head_b, &process);
	else if (!ft_strncmp(cmd, "rra", ft_strlen(cmd)))
		reverse_rotate_s(&process->head_a, &process, NULL);
	else if (!ft_strncmp(cmd, "rrb", ft_strlen(cmd)))
		reverse_rotate_s(&process->head_b, &process, NULL);
	else if (!ft_strncmp(cmd, "rrr", ft_strlen(cmd)))
		rrr(&process->head_a, &process->head_b, &process);
	else
		error_case(ERROR, -2);
}

static void	get_commands(t_info	*process)
{
	char	*line;

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

	if (argc < 2)
		exit(0);
	if (valid_args(argc, argv) == -1)
		error_case(ERROR, -1);
	process = NULL;
	process = init_process(argc, argv);
	if (!process)
		error_case(MALLOCERROR, -1);
	get_commands(process);
	if (sorted(process->head_a) && !process->head_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
