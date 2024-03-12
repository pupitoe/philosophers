/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:34:07 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/12 15:38:51 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_take_fork(t_arg_routine arg)
{
	if (arg.pos % 2)
		pthread_mutex_lock(arg.brain->mutex_right);
	else
		pthread_mutex_lock(arg.brain->mutex_left);
	ft_prompt_take_fork(arg);
	if (arg.pos % 2)
		pthread_mutex_lock(arg.brain->mutex_left);
	else
		pthread_mutex_lock(arg.brain->mutex_right);
	if (ft_death_philo(arg.philo) == PHILO_LIFE)
	{
		ft_prompt_take_fork(arg);
		ft_prompt_eat(arg);
		usleep(arg.philo->eat * 1000);
	}
	if (arg.pos % 2)
		pthread_mutex_unlock(arg.brain->mutex_right);
	else
		pthread_mutex_unlock(arg.brain->mutex_left);
	if (arg.pos % 2)
		pthread_mutex_unlock(arg.brain->mutex_left);
	else
		pthread_mutex_unlock(arg.brain->mutex_right);
	ft_change_time(arg);
	return (PHILO_LIFE);
}

static int	ft_one_philo(t_arg_routine arg)
{
	int	buffer;

	buffer = PHILO_LIFE;
	pthread_mutex_lock(arg.brain->mutex_right);
	ft_prompt_take_fork(arg);
	while (buffer == PHILO_LIFE)
	{
		buffer = ft_death_philo(arg.philo);
		usleep(1000);
	}
	pthread_mutex_unlock(arg.brain->mutex_right);
	return (buffer);
}

static int	ft_philo_sleep(t_arg_routine arg)
{
	ft_prompt_sleep(arg);
	usleep(arg.philo->sleep * 1000);
	return (PHILO_LIFE);
}

void	ft_philo_count_eat(t_arg_routine arg)
{
	pthread_mutex_lock(arg.brain->mutex_time);
	if (arg.philo->count_eat != -1)
		arg.brain->count_eat += 1;
	pthread_mutex_unlock(arg.brain->mutex_time);
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
	if (arg.philo->philos == 1 && arg.philo->count_eat)
		buffer = ft_one_philo(arg);
	while (buffer == PHILO_LIFE && arg.philo->philos != 1
		&& arg.philo->count_eat)
	{
		if (ft_death_philo(arg.philo) == PHILO_LIFE)
			ft_take_fork(arg);
		if (ft_death_philo(arg.philo) == PHILO_LIFE)
			ft_philo_sleep(arg);
		buffer = ft_death_philo(arg.philo);
		if (buffer == PHILO_LIFE)
			ft_prompt_think(arg);
	}
	return (arg_v);
}
