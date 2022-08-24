/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:39:24 by cbustama          #+#    #+#             */
/*   Updated: 2022/05/30 17:38:30 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	split_philo(t_only_philo *philo)
{
	int	group;

	group = 0;
	if (philo->common->count == philo->id
		&& philo->common->count % 2 != 0)
			group = 3;
	else if (philo->id % 2 == 0)
			group = 1;
	else if (philo->id % 2 != 0)
		group = 2;
	return (group);
}

int	philo_eat(t_only_philo *philo)
{
	if (check_dead(philo) == 1)
		return (1);
	take_fork(philo);
	pthread_mutex_lock(&philo->common->print);
	if (philo->common->check_dead == 0)
	{
		philo->philo_fork[philo->id - 1].eat = ft_get_time()
			+ philo->common->life;
		printf("%ld %d is eating\n", (ft_get_time() - philo->init), philo->id);
	}
	pthread_mutex_unlock(&philo->common->print);
	if (_wait(philo->common->eat, philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->common->dead);
	pthread_mutex_unlock(&philo->common->dead);
	return (0);
}

int	philo_think(t_only_philo *philo)
{
	if (check_dead (philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->common->print);
	if (philo->common->check_dead == 0)
		printf("%ld %d is thinking\n", ft_get_time() - philo->init, philo->id);
	pthread_mutex_unlock(&philo->common->print);
	if (check_dead (philo) == 1)
		return (1);
	return (0);
}

int	philo_sleep(t_only_philo *philo)
{
	if (check_dead(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->common->print);
	if (philo->common->check_dead == 0)
		printf("%ld %d is sleeping\n", ft_get_time() - philo->init, philo->id);
	pthread_mutex_unlock(&philo->common->print);
	if (_wait(philo->common->sleep, philo) == 1)
		return (1);
	if (philo->common->check_dead == 1)
		return (1);
	return (0);
}
