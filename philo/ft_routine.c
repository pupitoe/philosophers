/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:02:44 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/21 19:03:57 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_change_time(t_arg_routine arg)
{
	pthread_mutex_lock(arg.brain->mutex_time);
	arg.brain->time_left = ft_get_timestamp();
	pthread_mutex_unlock(arg.brain->mutex_time);
}

void	ft_philo_death(t_arg_routine arg)
{
	ft_prompt_death(arg);
	pthread_mutex_lock(&arg.philo->mutex_dead);
	arg.philo->philo_has_died = 1;
	pthread_mutex_unlock(&arg.philo->mutex_dead);
}


// the expected time is 10 ms per turn or 10000 microseconds 
// here I only put 9900 microseconds because there are 100 microseconds 
// of waiting to have the inforomaton of the death of a philo
int	ft_tea_time(t_arg_routine arg, size_t time)
{
	while (time > 10000)
	{
		usleep(9900);
		if (ft_death_philo(arg.philo) == PHILO_DETH)
			return (PHILO_DETH);
		time -= 10000;
	}
	if (time > 100)
		usleep(time - 100);
	return (ft_death_philo(arg.philo));
}

static int	ft_take_fork(t_arg_routine arg)
{
	int	buffer;

	buffer = PHILO_LIFE;
	pthread_mutex_lock(arg.brain->mutex_right);
	ft_prompt_take_fork(arg);
	pthread_mutex_lock(arg.brain->mutex_left);
	ft_prompt_take_fork(arg);
	*(arg.brain->fork_left) = 1;
	*(arg.brain->fork_right) = 1;
	ft_prompt_eat(arg);
	usleep(arg.philo->eat * 1000);
	//ft_tea_time(arg, srg.philo->eat * 1000);
	*(arg.brain->fork_left) = 0;
	*(arg.brain->fork_right) = 0;
	pthread_mutex_unlock(arg.brain->mutex_left);
	pthread_mutex_unlock(arg.brain->mutex_right);
	ft_change_time(arg);
	return (buffer);
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
	//arg.brain->time_left = ft_get_timestamp();
	while (buffer == PHILO_LIFE)
	{
		round++;
		ft_prompt_think(arg);
		buffer = ft_take_fork(arg);
		if (buffer == PHILO_LIFE)
			buffer = ft_philo_eat(arg);
		buffer = ft_death_philo(arg.philo);
	}
	return (arg_v);
}
