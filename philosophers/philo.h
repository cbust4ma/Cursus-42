/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:28:50 by cbustama          #+#    #+#             */
/*   Updated: 2022/05/27 19:10:43 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <stdint.h>
# define RED "\033[31m"
# define RESET "\033[0m"

typedef struct s_philo{
	int				count;
	int				eat;
	int				sleep;
	int				n_eats;
	int				check_dead;
	long			life;
	int				think;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_t		*t;
}t_philo;

typedef struct s_fork{
	int				forks;
	long			eat;
	pthread_mutex_t	m_fork;
}t_fork;

typedef struct s_only_philo
{
	int				_fork;
	long			time_eat;
	long			init;
	int				id;
	int				group;
	int				status;
	int				eating;
	long			time;
	long			last_eat;
	t_philo			*common;
	t_fork			*philo_fork;
}t_only_philo;

int				ft_atoi(const char *str);
long			_wait(long time, t_only_philo *philo);
int				last_time(int t);
long			ft_get_time(void);
t_only_philo	*init_var(t_only_philo *philo, t_philo *common, t_fork *fork);
int				philo_eat(t_only_philo *philo);
int				split_philo(t_only_philo *philo);
int				philo_sleep(t_only_philo *philo);
int				philo_think(t_only_philo *philo);
int				check_dead(t_only_philo *philo);
int				take_fork(t_only_philo *philo);
void			*continue_status_check(t_only_philo *philo);
void			status_check(t_only_philo *philo);
int				_errors(char **argv);
void			out_take(t_only_philo *philo);

#endif
