#include "includes/push_swap.h"
#include "../libft/libft.h"

static int	check(int argc, char *argv[], int pairs, int start);

/**
 * check input arguments : invalid symbols
 * @param argc : count of values
 * @param argv : pointer
 * @return 1 : OK
 * @return -1 : invalid symbols
 * @return 0 : doubles/bigger or smaller than int
 */
int	valid_args(int argc, char *argv[])
{
	char	**arg;
	int		i;
	int		digits;

	i = -1;
	digits = count_digits(argv[1], ' ');
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		if (!*arg || !arg[0])
			return (0);
		digits = check(digits + 1, arg, digits - 1, -1);
		while (arg[++i])
			free(arg[i]);
		free(arg);
	}
	else
		digits = check(argc, argv, argc - 2, 0);
	return (digits);
}

static int	check(int argc, char *argv[], int pairs, int start)
{
	int		i;
	int		j;

	i = start;
	while (argc-- > 1)
	{
		i++;
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (-1);
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				continue ;
			else if (!ft_isdigit(argv[i][j]))
				return (-1);
		}
		if (argc > 1 && ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
			pairs--;
		j = start;
		while (++j < i)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
	}
	return (pairs != 0);
}
