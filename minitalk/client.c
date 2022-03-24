/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:48:00 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/14 14:54:51 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	
		while (argv[2][c])
		{
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
