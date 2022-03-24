/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:55:39 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/08 21:06:02 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	_handler(int sig, siginfo_t *info, void *s)
{
	static int	i;
	static int	bit;

	(void)info;
	(void)s;
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
	kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	act;

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
	act.sa_sigaction = _handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
