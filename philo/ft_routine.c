/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:16:55 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/17 23:55:58 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		ft_take_fork(t_arg_routine arg)
{
	//pthread_mutex_lock(&mu);
	pthread_mutex_lock(arg.brain->mutex_right);
	printf("philo %d take fork right\n", arg.pos);
	pthread_mutex_lock(arg.brain->mutex_left);
	printf("philo %d take fork left\n", arg.pos);
	*(arg.brain->fork_left) = 0;
	*(arg.brain->fork_right) = 1;
	sleep(1);	
	*(arg.brain->fork_left) = 0;
	*(arg.brain->fork_right) = 0;
	pthread_mutex_unlock(arg.brain->mutex_left);
	printf("philo %d drop fork left\n", arg.pos);
	pthread_mutex_unlock(arg.brain->mutex_right);
	printf("philo %d drop fork right\n", arg.pos);
	//pthread_mutex_unlock(&mu);
	return (PHILO_DETH);
}

void	*ft_routine(void *arg_v)
{
	t_arg_routine	arg;
	int				buffer;

	arg = *(t_arg_routine *)arg_v;
	buffer = 0;
	while (buffer != PHILO_DETH && buffer != ROUND_REST)
	{
		buffer = ft_take_fork(arg);
	}
	return (arg_v);
}
