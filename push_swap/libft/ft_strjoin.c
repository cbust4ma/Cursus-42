/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:23:28 by cbustama          #+#    #+#             */
/*   Updated: 2021/08/30 16:58:34 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		l;
	int		l2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen(s1) + 1;
	l2 = ft_strlen(s2) + l;
	result = (char *)malloc(l2 * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, l);
	ft_strlcat(result, s2, l2);
	return (result);
}
