/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:16:55 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/18 21:19:24 by tlassere         ###   ########.fr       */
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
	usleep(arg.philo->sleep);
	*(arg.brain->fork_left) = 0;
	*(arg.brain->fork_right) = 0;
	pthread_mutex_unlock(arg.brain->mutex_left);
	pthread_mutex_unlock(arg.brain->mutex_right);
	return (PHILO_DETH);
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
		buffer = PHILO_DETH;
		buffer = ft_take_fork(arg);
	}
	return (arg_v);
}
