/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:43:42 by cbustama          #+#    #+#             */
/*   Updated: 2021/08/17 19:03:27 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **d, size_t start)
{
	size_t	j;

	if (d)
	{
		j = 0;
		while (j < start)
		{
			if (d[j] != NULL)
				free(d[start]);
			start++;
		}
		free(d);
	}
	return (NULL);
}

size_t	ft_lines(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	if (s[i - 1] == c)
		count--;
	return (count);
}

size_t	ft_wc(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

char	**ft_fill(char **dest, const char *s, char to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s != '\0')
	{
		while (*s == to_find && *s != '\0')
			s++;
		if (*s == '\0')
			continue ;
		dest[i] = malloc(sizeof(char) * ft_wc(s, to_find) + 1);
		if (dest[i] == NULL)
			return (ft_free(dest, i));
		j = 0;
		while (*s != to_find && *s != '\0')
		{
			dest[i][j] = *s;
			j++;
			s++;
		}
		dest[i][j] = '\0';
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	if (ft_strlen(s) > 0)
		dest = malloc(sizeof(char *) * (ft_lines(s, c) + 1));
	else
		dest = malloc(sizeof(char *) * (0 + 1));
	if (dest == NULL)
		return (NULL);
	ft_fill(dest, s, c);
	return (dest);
}
