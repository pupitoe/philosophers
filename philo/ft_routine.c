/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:16:55 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/18 22:07:51 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_take_fork(t_arg_routine arg)
{
	pthread_mutex_lock(arg.brain->mutex_right);
	ft_prompt_take_fork(arg);
	pthread_mutex_lock(arg.brain->mutex_left);
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

	(void)ft_take_fork;
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
