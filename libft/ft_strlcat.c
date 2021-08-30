/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:26:30 by cbustama          #+#    #+#             */
/*   Updated: 2021/08/30 16:58:46 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	i;

	if (dstsize <= ft_strlen (dst))
		return (dstsize + ft_strlen(src));
	a = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && a + 1 < dstsize)
	{
		dst[a] = src[i];
		a++;
		i++;
	}
	dst[a] = '\0';
	return (ft_strlen(dst) + ft_strlen (&src[i]));
}
