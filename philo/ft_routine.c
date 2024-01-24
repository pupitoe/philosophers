/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:02:44 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/24 01:54:46 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_change_time(t_arg_routine arg)
{
	pthread_mutex_lock(arg.brain->mutex_time);
	arg.brain->time_left = ft_get_timestamp();
	pthread_mutex_unlock(arg.brain->mutex_time);
}

static int	ft_take_fork(t_arg_routine arg)
{
	pthread_mutex_lock(arg.brain->mutex_right);
	ft_prompt_take_fork(arg);
	if (ft_death_philo(arg.philo) == PHILO_DETH)
		return (pthread_mutex_unlock(arg.brain->mutex_right), PHILO_DETH);
	pthread_mutex_lock(arg.brain->mutex_left);
	if (ft_death_philo(arg.philo) == PHILO_DETH)
		return (pthread_mutex_unlock(arg.brain->mutex_left),
			pthread_mutex_unlock(arg.brain->mutex_right), PHILO_DETH);
	ft_prompt_take_fork(arg);
	ft_prompt_eat(arg);
	usleep(arg.philo->eat * 1000);
	pthread_mutex_unlock(arg.brain->mutex_left);
	pthread_mutex_unlock(arg.brain->mutex_right);
	ft_change_time(arg);
	return (PHILO_LIFE);
}

static int	ft_philo_eat(t_arg_routine arg)
{
	ft_prompt_sleep(arg);
	usleep(arg.philo->sleep * 1000);
	return (PHILO_LIFE);
}

void	*ft_routine(void *arg_v)
{
	t_arg_routine	arg;
	int				buffer;
	int				round;

	arg = *(t_arg_routine *)arg_v;
	buffer = PHILO_LIFE;
	round = 0;
	if (arg.pos % 2)
		usleep(500);
	while (buffer == PHILO_LIFE && arg.philo->count_eat)
	{
		buffer = ft_take_fork(arg);
		if (buffer == PHILO_LIFE && ft_death_philo(arg.philo) == PHILO_LIFE)
			buffer = ft_philo_eat(arg);
		buffer = ft_death_philo(arg.philo);
		if (arg.philo->count_eat != -1 && ++round == arg.philo->count_eat)
		{
			ft_death_philo(arg.philo);
			buffer = ROUND_REST;
		}
		ft_prompt_think(arg);
	}
	return (arg_v);
}
