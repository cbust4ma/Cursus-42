/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:39:24 by cbustama          #+#    #+#             */
/*   Updated: 2022/05/27 19:12:51 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	split_philo(t_only_philo *philo)
{
	int	group;

	group = 0;
	if (philo->id % 2 == 0)
		group = 1;
	else if (philo->id % 2 != 0)
		group = 2;
	return (group);
}

int	philo_eat(t_only_philo *philo)
{
	if (philo->common->check_dead == 1)
		return (1);
	while (philo->philo_fork[philo->id - 1].forks == 0)
	{
		usleep (500);
		if (check_dead(philo) == 1)
			return (1);
	}
	if (take_fork(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->common->print);
	if (philo->common->check_dead == 0)
		printf("%ld %d I'm eating\n", (ft_get_time() - philo->init), philo->id);
	pthread_mutex_unlock(&philo->common->print);
	if (_wait(philo->common->eat, philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->common->dead);
	philo->philo_fork[philo->id - 1].eat = ft_get_time()
		+ philo->common->life;
	pthread_mutex_unlock(&philo->common->dead);
	if (check_dead(philo) == 1)
		return (1);
	return (0);
}

int	philo_think(t_only_philo *philo)
{
	if (philo->common->check_dead == 1)
		return (1);
	pthread_mutex_lock(&philo->common->print);
	if (philo->common->check_dead == 0)
		printf("%ld %d I'm think\n", ft_get_time() - philo->init, philo->id);
	pthread_mutex_unlock(&philo->common->print);
	if (philo->common->check_dead == 1)
		return (1);
	return (0);
}

int	philo_sleep(t_only_philo *philo)
{
	if (philo->common->check_dead == 1)
	{
		usleep(50);
		return (1);
	}
	pthread_mutex_lock(&philo->common->print);
	usleep(50);
	if (philo->common->check_dead == 0)
		printf("%ld %d I'm sleep\n", ft_get_time() - philo->init, philo->id);
	pthread_mutex_unlock(&philo->common->print);
	if (_wait(philo->common->sleep, philo) == 1)
		return (1);
	usleep(50);
	if (philo->common->check_dead == 1)
		return (1);
	check_dead(philo);
	return (0);
}
