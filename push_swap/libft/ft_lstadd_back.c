/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:00:01 by cbustama          #+#    #+#             */
/*   Updated: 2021/08/23 18:37:55 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dest;

	dest = *lst;
	if (!(*lst))
		*lst = new;
	while (dest != NULL)
	{
		if (dest->next == NULL)
		{
			dest->next = new;
			return ;
		}
		dest = dest->next;
	}
}
