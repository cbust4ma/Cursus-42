/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:48:30 by cbustama          #+#    #+#             */
/*   Updated: 2021/11/10 17:32:24 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_numbers(int number);
int		ft_str(char *str);
int		ft_unumbers(unsigned int n);
int		ft_hexa_x(unsigned long int value, char hex);

#endif
