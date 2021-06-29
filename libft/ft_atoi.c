/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 00:26:22 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 18:08:46 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	digit;
	int		flag;

	digit = 0;
	flag = 1;
	while (*str == ' ' || *str == '\v' || *str == '\t' ||\
	 *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		digit = (digit * 10) + (*str - '0');
		str++;
	}
//	if (flag * digit > 2147483647 || flag * digit < -2147483648)
//		return (NULL); /** todo: ?????*/
	return (flag * digit);
}
