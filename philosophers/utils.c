/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:05:44 by cbustama          #+#    #+#             */
/*   Updated: 2022/05/27 19:11:57 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;
	int		i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if ((res * sign < -2147483648) || (res * sign > 2147483647))
			return ((res * sign < -2147483648) - 1);
		i++;
	}
	return (res * sign);
}

long	ft_get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

long	_wait(long time, t_only_philo *philo)
{
	long			start;
	struct timeval	tv;
	long			my_time;

	gettimeofday(&tv, NULL);
	start = gettimeofday(&tv, NULL);
	my_time = ft_get_time();
	while (1)
	{
		if (check_dead(philo))
			return (1);
		if ((ft_get_time() - my_time) >= time)
			break ;
		usleep(50);
	}
	return (0);
}

int	_errors(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		if (argv[j][i] < '0' || argv[j][i] > '9')
		{
			printf (RED"Parameter Invalids %c\n", argv[j][i]);
			printf (RED"Parameter Invalids\n"RESET);
			return (1);
		}
		j++;
	}	
	return (0);
}

void	out_take(t_only_philo *philo)
{
	pthread_mutex_unlock(&philo->philo_fork[philo->id
		% philo->common->count].m_fork);
	philo->philo_fork[philo->id % philo->common->count].forks = 1;
	pthread_mutex_unlock(&philo->philo_fork[philo->id - 1].m_fork);
	philo->philo_fork[philo->id - 1].forks = 1;
}
