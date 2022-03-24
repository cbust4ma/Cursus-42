/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:32:38 by cbustama          #+#    #+#             */
/*   Updated: 2021/11/11 19:54:35 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_numbers(int number)
{
	int		i;
	char	*result;

	result = ft_itoa(number);
	i = 0;
	while (result[i] != '\0')
	{
		ft_print_char(result[i]);
		i++;
	}
	free (result);
	return (i);
}

int	ft_unumbers(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count = ft_print_char ('-');
		n = n * -1;
	}
	if (n < 10)
	{
		count = ft_print_char(n + 48);
		return (count);
	}
	else
		count = ft_unumbers(n / 10);
	count += ft_unumbers (n % 10);
	return (count);
}
