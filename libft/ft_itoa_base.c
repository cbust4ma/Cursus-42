/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:27:08 by cbustama          #+#    #+#             */
/*   Updated: 2021/10/25 18:38:46 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static	size_t ft_len_base(unsigned long n, char *base)
{
	size_t			i;
	unsigned long	len_base;

	i = 1;
	len_base = ft_strlen(base);
	while (n >= len_base)
	{
		n = n / len_base;
		i++;
	}
	return (i);
}
char	*base(unsigned long n, char *base)
{
	char	*str;
	int		len_num;
	int		len_base;

	len_num = ft_len_base(n,base);
	len_base = ft_strlen(base);
	str = malloc((len_num + 1) * sizeof(char));
	if (!str)
		return (0);
	while (len_num)
	{
		len_num = len_num -1;
		str[len_num] = base[n % len_base];
		n = n / len_base;
	}
	return (str);
}


*/
#define INT_STR_SIZE (sizeof(int)*CHAR_BIT + 2)
static char	*itoa_base_helper(char	*dest, size_t size, int	x, int	base)
{
	if (size == 0)
		return (NULL);
	int digit =  -(x % base);
	x = x / base;
	if (x)
	{
		dest = itoa_base_helper(dest, size -1, x, base);
		if (dest == NULL) 
			return (NULL);
	}
	*dest = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[digit];
	return (dest + 1);
}

char	*itoa_base(char	*dest, size_t size, int x, int base)
{
	if (base < 2 || base > 36 || size < 2)
		return (NULL);
	char *p = dest;
	if (x < 0)
	{
		*p++ = '-';
		size--;
	}
	else
		x = -x;
	p = itoa_base_helper(p, size-1, x, base);
	if (p == NULL)
		return (NULL);
	*p = '\0';
	return (dest);
}

#define itoa_base(x,base) itoa_base((char [INT_STR_SIZE]){""}, INT_STR_SIZE,(x),(base))



