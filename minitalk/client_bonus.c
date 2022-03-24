/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:07:51 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/08 21:07:16 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	_return(int signal)
{
	if (signal == SIGUSR2)
		ft_putstr_fd("\033[0;32mNice Message\033[0;32m\n", 1);
	else
		ft_putstr_fd("\033[0;32mBad Message\033[0;32m\n", 1);


}

int	_send(pid_t pid, char sig)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((sig & (1 << bit)) != 0)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep (100);
		bit++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	c;

	c = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == -1)
			return (0);
		while (argv[2][c])
		{
			signal(SIGUSR1, _return);
			signal(SIGUSR2, _return);
			_send(pid, argv[2][c]);
			c++;
		}
		_send(pid, '\n');
	}
	else
	{
		write (1, "\x1B[31mUse ./client [PID] String\x1B[31m\n", 37);
		return (1);
	}
	return (0);
}
