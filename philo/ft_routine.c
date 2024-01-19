/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:16:55 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/19 17:38:55 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_change_time(t_arg_routine arg, size_t *buffer_time)
{
	arg.brain->time_left -= ft_get_timestamp() - *buffer_time;
	*buffer_time = ft_get_timestamp();
}

static int	ft_take_fork(t_arg_routine arg)
{
	size_t	buffer_time;

	buffer_time = ft_get_timestamp();
	pthread_mutex_lock(arg.brain->mutex_right);
	ft_change_time(arg, &buffer_time);
	ft_prompt_take_fork(arg);
	pthread_mutex_lock(arg.brain->mutex_left);
	ft_change_time(arg, &buffer_time);
	ft_prompt_take_fork(arg);
	*(arg.brain->fork_left) = 0;
	*(arg.brain->fork_right) = 1;
	ft_prompt_eat(arg);
	arg.brain->time_left = arg.philo->death;
	usleep(arg.philo->eat * 1000);
	*(arg.brain->fork_left) = 0;
	*(arg.brain->fork_right) = 0;
	pthread_mutex_unlock(arg.brain->mutex_left);
	pthread_mutex_unlock(arg.brain->mutex_right);
	return (PHILO_LIFE);
}

static int	ft_philo_eat(t_arg_routine arg)
{
	ft_prompt_sleep(arg);
	usleep(arg.philo->sleep * 1000);
	arg.brain->time_left -= arg.philo->sleep;
	return (PHILO_LIFE);
}

void	*ft_routine(void *arg_v)
{
	t_arg_routine	arg;
	int				buffer;

	arg = *(t_arg_routine *)arg_v;
	buffer = 0;
	while (buffer != PHILO_DETH && buffer != ROUND_REST)
	{
		ft_prompt_think(arg);
		buffer = ft_take_fork(arg);
		if (buffer == PHILO_LIFE)
			buffer = ft_philo_eat(arg);
		buffer = PHILO_DETH;
	}
	return (arg_v);
}
