/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:33:56 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/25 20:34:02 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	philo_time_left(t_arg_routine arg)
{
	size_t	buffer;

	pthread_mutex_lock(arg.brain->mutex_time);
	buffer = arg.brain->time_left;
	pthread_mutex_unlock(arg.brain->mutex_time);
	return (buffer);
}

void	ft_philo_death(t_arg_routine arg, int print)
{
	if (print)
		ft_prompt_death(arg);
	pthread_mutex_lock(&arg.philo->mutex_dead);
	arg.philo->philo_has_died = 1;
	pthread_mutex_unlock(&arg.philo->mutex_dead);
}

int	ft_death_philo(t_philo *philo)
{
	int	buffer;

	buffer = PHILO_LIFE;
	pthread_mutex_lock(&philo->mutex_dead);
	if (philo->philo_has_died)
		buffer = PHILO_DETH;
	pthread_mutex_unlock(&philo->mutex_dead);
	return (buffer);
}

void	ft_change_time(t_arg_routine arg)
{
	pthread_mutex_lock(arg.brain->mutex_time);
	arg.brain->time_left = ft_get_timestamp();
	pthread_mutex_unlock(arg.brain->mutex_time);
}

void	ft_check_death(t_philo *philo, t_arg_routine *arg)
{
	int		i;
	int		buffer;
	size_t	times_tamp;
	size_t	philo_left;

	i = 0;
	buffer = PHILO_LIFE;
	while (buffer != PHILO_DETH && philo->count_eat)
	{
		if (i == 0)
		{
			buffer = ft_death_philo(philo);
			times_tamp = ft_get_timestamp();
		}
		philo_left = philo_time_left(arg[i]);
		if (times_tamp > philo_left
			&& times_tamp - philo_left > (size_t)philo->death)
		{
			ft_philo_death(*(arg + i), 1);
			buffer = PHILO_DETH;
		}
		i = (i + 1) % philo->philos;
		usleep(200);
	}
}
