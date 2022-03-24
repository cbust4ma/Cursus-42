/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:46:29 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/11 15:24:54 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	_handler(int sig)
{
	static int	i;
	static int	bit;

	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		if (!i)
			write(1, "\n", 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		write(1, "\x1B[31mError Format...\x1B[31m", 27);
		return (0);
	}
	pid = getpid();
	write(1, "\x1B[32mPID... \x1B[32m", 18);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, _handler);
		signal(SIGUSR2, _handler);
		pause ();
	}
	return (0);
}
