/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:40:13 by cbustama          #+#    #+#             */
/*   Updated: 2021/11/11 20:02:13 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "ft_printf.h"

int	def_arg(char format, va_list arg)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_print_char(va_arg(arg, int));
	if (format == 's')
		count = ft_str(va_arg(arg, char *));
	if (format == 'p')
	{
		count = ft_str("0x") + ft_hexa_x(va_arg(arg, unsigned long int), 'x');
	}
	if (format == 'd' || format == 'i')
		count = ft_numbers(va_arg(arg, int));
	if (format == 'u')
		count = ft_unumbers(va_arg(arg, unsigned int));
	if (format == 'x')
		count = ft_hexa_x(va_arg(arg, unsigned int), 'x');
	if (format == 'X')
		count = ft_hexa_x(va_arg(arg, unsigned int), 'X');
	if (format == '%')
		count = ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start (arg, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_print_char(format[i]);
			count++;
			i++;
		}
		else
		{
			count += def_arg(format[i + 1], arg);
			i += 2;
		}
	}
	va_end(arg);
	return (count);
}
