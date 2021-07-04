/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:59:44 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 18:10:49 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	char			*temp;
	unsigned int	i;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	temp = (char *)s1;
	i = 0;
	result = malloc(sizeof(int) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (*s1)
		result[i++] = (char)*s1++;
	while (*s2)
		result[i++] = (char)*s2++;
	result[i] = '\0';
	free(temp);
	return (result);
}
