/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:32:16 by cbustama          #+#    #+#             */
/*   Updated: 2022/05/30 18:18:55 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_only_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->common->dead);
	if (philo->common->check_dead == 1)
	{
		pthread_mutex_unlock(&philo->common->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->common->dead);
	time = ft_get_time();
	if (time > philo->philo_fork[philo->id - 1].eat)
	{
		pthread_mutex_lock(&philo->common->dead);
		pthread_mutex_lock(&philo->common->print);
		usleep(150);
		if (philo->common->check_dead == 0)
			printf(RED"%ld %d died.\n"RESET, \
				(ft_get_time() - philo->init), philo->id);
		philo->common->check_dead = 1;
		pthread_mutex_unlock(&philo->common->print);
		pthread_mutex_unlock(&philo->common->dead);
		return (1);
	}
	return (0);
}

int	take_fork(t_only_philo *philo)
{
	while (philo->philo_fork[philo->id - 1].forks == 0)
	{
		if (check_dead(philo) == 1)
			return (1);
		usleep (100);
	}
	forks_left(philo);
	forks_right(philo);
	return (0);
}

void	*continue_status_check(t_only_philo *philo)
{
	if (philo->group == 3 && philo->common->check_dead == 0)
	{
		philo->group = 1;
		if (philo_think(philo) == 1)
			return (NULL);
	}
	if (philo->group == 1 && philo->common->check_dead == 0)
	{
		if (philo->common->check_dead == 1)
			return (NULL);
		philo->group = 2;
		if ((philo_eat(philo) == 1))
		{
			out_take(philo);
			return (NULL);
		}
		out_take(philo);
		philo->eating++;
		if (philo->common->n_eats != -1
			&& philo->eating == philo->common->n_eats)
			return (NULL);
	}
	return (philo);
}

void	status_check(t_only_philo *philo)
{
	philo->philo_fork[philo->id - 1].eat = philo->time_eat
		+ philo->common->life;
	philo->group = split_philo(philo);
	philo->common->check_dead = 0;
	while (check_dead(philo) == 0)
	{
		if (continue_status_check(philo) == NULL)
			break ;
		if (philo->group == 2 && philo->common->check_dead == 0)
		{
			philo->group = 3;
			if (philo_sleep(philo) == 1)
				break ;
		}
		if (check_dead(philo) == 1)
			break ;
	}
	free (philo);
}

int	take_fork_s(t_only_philo *philo)
{
	int	right_fork;

	if (philo->common->check_dead == 1)
		return (1);
	if (philo->id == 1)
	{
		right_fork = philo->common->count - 1;
		return (right_fork);
	}
	else
	{
		right_fork = philo->id - 2;
		return (right_fork);
	}
}
