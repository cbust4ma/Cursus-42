/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:16:23 by cbustama          #+#    #+#             */
/*   Updated: 2021/11/11 20:03:12 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_hexa_x(unsigned long int value, char hex)
{
	char			*base;
	static int		count;

	count = 0;
	if (hex == 'x')
		base = "0123456789abcdef";
	if (hex == 'X')
		base = "0123456789ABCDEF";
	if (value > 15)
	{
		ft_hexa_x(value / 16, hex);
	}
	count++;
	ft_print_char(base[value % 16]);
	return (count);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}
