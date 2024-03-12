/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_take_fork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:56:18 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/12 15:56:55 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_take_fork_lock(t_arg_routine arg)
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
}

static void	ft_take_fork_unlock(t_arg_routine arg)
{
	if (arg.pos % 2)
		pthread_mutex_unlock(arg.brain->mutex_right);
	else
		pthread_mutex_unlock(arg.brain->mutex_left);
	if (arg.pos % 2)
		pthread_mutex_unlock(arg.brain->mutex_left);
	else
		pthread_mutex_unlock(arg.brain->mutex_right);
}

int	ft_take_fork(t_arg_routine arg)
{
	int	status;

	status = PHILO_LIFE;
	ft_take_fork_lock(arg);
	if (ft_death_philo(arg.philo) == PHILO_LIFE)
	{
		ft_prompt_take_fork(arg);
		ft_prompt_eat(arg);
		if (usleep(arg.philo->eat * 1000) == USLEEP_FAIL)
			status = USLEEP_FAIL;
	}
	ft_take_fork_unlock(arg);
	ft_change_time(arg);
	return (status);
}
