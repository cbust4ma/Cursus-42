/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:54:22 by cbustama          #+#    #+#             */
/*   Updated: 2021/08/05 19:34:52 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	return (ft_memcpy(s2, s1, ft_strlen(s1) + 1));
}
