#include "../push_swap.h"
#include "../libft/libft.h"

void	error_case(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}

int	valid_args(int argc, char *argv[])
{
	int	flag;
	int	i;
	int	j;

	flag = argc - 2;
	i = 0;
	while (argc-- > 1)
	{
		i++;
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && argv[i][j] == '-')
				continue ;
			else if (!ft_isdigit(argv[i][j]))
				return (-1);
		}
		if (argc > 1 && ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
			flag--;
		j = 0;
		while (++j < i)
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (-1);
	}
	return (flag != 0);
}
