/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:45:11 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/05 14:05:46 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks_left(t_only_philo *philo)
{
	pthread_mutex_unlock(&philo->philo_fork[philo->id - 1].m_fork);
	philo->philo_fork[philo->id - 1].forks = 0;
	pthread_mutex_lock(&philo->common->print);
	if (philo->common->check_dead == 0)
		printf("%ld %d has taken a fork\n",
			ft_get_time() - philo->init, philo->id);
	pthread_mutex_unlock(&philo->common->print);
	if (check_dead(philo) == 1)
		return (1);
	return (0);
}

int	forks_right(t_only_philo *philo)
{
	philo->r_fork = take_fork_s(philo);
	pthread_mutex_lock(&philo->philo_fork[philo->r_fork].m_fork);
	philo->philo_fork[philo->r_fork].forks = 0;
	pthread_mutex_lock(&philo->common->print);
	if (philo->common->check_dead == 0)
		printf("%ld %d has taken a fork\n",
			ft_get_time() - philo->init, philo->id);
	pthread_mutex_unlock(&philo->common->print);
	if (check_dead(philo) == 1)
		return (1);
	return (0);
}
