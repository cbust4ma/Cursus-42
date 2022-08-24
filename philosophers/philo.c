/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:29:40 by cbustama          #+#    #+#             */
/*   Updated: 2022/05/30 18:14:24 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	continue_create_threads(t_only_philo *fork, t_philo *philo
	, t_fork *philo_fork)
{
	int	i;

	i = 0;
	pthread_mutex_init(&philo->print, NULL);
	pthread_mutex_init(&philo->dead, NULL);
	while (i < philo->count)
	{
		fork = (t_only_philo *)malloc(sizeof(t_only_philo));
		fork = init_var(fork, philo, philo_fork);
		fork->id = i + 1;
		if (pthread_create(&philo->t[i], NULL, (void *)status_check, fork) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < philo->count)
	{
		if (pthread_join(philo->t[i], NULL) != 0)
			return ;
		i++;
	}
}

void	create_threads(int len, t_philo *philo)
{
	int				i;
	t_only_philo	*fork;
	t_fork			*philo_fork;

	i = 0;
	fork = NULL;
	philo->t = malloc(sizeof(pthread_t) * len);
	philo_fork = (t_fork *)malloc(sizeof(t_fork) * len);
	if (!philo->t || !philo_fork)
		return ;
	while (i < len)
	{
		philo_fork[i].forks = 1;
		philo_fork[i].eat = 0;
		pthread_mutex_init(&philo_fork[i].m_fork, NULL);
		i++;
	}
	continue_create_threads(fork, philo, philo_fork);
	free (philo->t);
	free (philo_fork);
}

t_only_philo	*init_var(t_only_philo *philo, t_philo *common, t_fork *fork)
{
	philo->init = ft_get_time();
	philo->time_eat = philo->init;
	philo->common = common;
	philo->philo_fork = fork;
	philo->eating = 0;
	return (philo);
}

int	error_manager(t_philo *philo, int argc)
{
	if (philo->sleep <= 0)
		return (1);
	if (philo->eat <= 0)
		return (1);
	if (philo->count <= 0)
		return (1);
	if (philo->life <= 0)
		return (1);
	if (argc == 6 && philo->n_eats <= 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
		return (printf("Invalid Arguments\n"));
	if (_errors(argv) == 1)
		return (1);
	else
	{
		if (argc == 6)
			philo.n_eats = ft_atoi(argv[5]);
		else
			philo.n_eats = -1;
		philo.sleep = ft_atoi(argv[4]);
		philo.eat = ft_atoi(argv[3]);
		philo.life = ft_atoi(argv[2]);
		philo.count = ft_atoi(argv[1]);
	}
	if (philo.count == 1)
		return (printf("0 1 take a fork\n"R"%ld 1 DIED\n"RE, philo.life + 1));
	if (error_manager(&philo, argc) == 1)
		return (printf("Invalid Arguments\n"));
	create_threads(philo.count, &philo);
	return (0);
}
