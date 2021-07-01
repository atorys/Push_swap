/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:07:31 by atory             #+#    #+#             */
/*   Updated: 2021/04/29 17:29:07 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strcount(char const *s, char c)
{
	unsigned int	count;
	int				i;
	int				k;

	count = 0;
	i = 0;
	if (!ft_strchr(s, c))
		return (1);
	while (s[i])
	{
		k = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i + k] != '\0' && s[i + k] != c)
			k++;
		if (k > 0)
			count++;
		i += k;
	}
	return (count);
}

static char	*ft_free(char **array)
{
	while (*array)
	{
		free(*array);
		array++;
	}
	free(array);
	return (NULL);
}

static char	*writeln(char **array, char const *s, size_t k, unsigned int j)
{
	char	*line;

	line = ft_substr(s, j, k);
	if (!line)
		return (ft_free(array));
	return (line);
}

static char	**ft_writearray(char const *s, char c, char **array)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	while (s[j] != '\0' && i < ft_strcount(s, c))
	{
		k = 0;
		while (s[j] != '\0' && s[j] == c)
			j++;
		while (s[j + k] != '\0' && s[j + k] != c)
			k++;
		array[i] = writeln(array, s, (size_t)k, j);
		if (!array[i])
			return (NULL);
		i++;
		j += k;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char			**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (ft_strcount(s, c) + 1));
	if (!array)
		return (NULL);
	return (ft_writearray(s, c, array));
}
