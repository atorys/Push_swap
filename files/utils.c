#include "../push_swap.h"
#include "../libft/libft.h"

/**
 * print error comment and exit
 * @param message : string with comment
 * @param number : user defined code for exit();
 */
void	error_case(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}

/**
 * check input arguments : doubles & invalid symbols & sorted
 * @param argc : count of values
 * @param argv : pointer
 * @return 1 : OK
 * @return 0 : already sorted values
 * @return -1 : doubles or invalid symbols
 */
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
			if (ft_atoi(argv[j]) == ft_atoi(argv[i])) /** todo: int max min*/
				return (-1);
	}
	return (flag != 0);
}
