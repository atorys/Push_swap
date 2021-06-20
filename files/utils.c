#include "../push_swap.h"
#include "../libft/libft.h"

void	error_case(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}

int valid_args(int argc, char *argv[])
{
	int flag;
	int digit;
	int	i;

	flag = 0;
	i = 0;
	while (argc-- > 1)
	{
		digit = ft_atoi(argv[++i]);
	}
	return (0);
}
