/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:34:07 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/12 16:01:56 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_one_philo(t_arg_routine arg)
{
	int	buffer;

	buffer = PHILO_LIFE;
	pthread_mutex_lock(arg.brain->mutex_right);
	ft_prompt_take_fork(arg);
	while (buffer == PHILO_LIFE)
	{
		buffer = ft_death_philo(arg.philo);
		if (usleep(1000) == USLEEP_FAIL)
			buffer = USLEEP_FAIL;
	}
	pthread_mutex_unlock(arg.brain->mutex_right);
	return (buffer);
}

static int	ft_philo_sleep(t_arg_routine arg)
{
	int	status;

	status = PHILO_LIFE;
	ft_prompt_sleep(arg);
	if (usleep(arg.philo->sleep * 1000) == USLEEP_FAIL)
		status = USLEEP_FAIL;
	return (status);
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
	if (arg.pos % 2 && usleep(500) == USLEEP_FAIL)
		buffer = USLEEP_FAIL;
	if (arg.philo->philos == 1 && arg.philo->count_eat)
		buffer = ft_one_philo(arg);
	while (buffer == PHILO_LIFE && arg.philo->philos != 1
		&& arg.philo->count_eat)
	{
		if (ft_death_philo(arg.philo) == PHILO_LIFE)
			buffer = ft_take_fork(arg);
		if (ft_death_philo(arg.philo) == PHILO_LIFE && buffer == PHILO_LIFE)
			buffer = ft_philo_sleep(arg);
		if (buffer == PHILO_LIFE)
			buffer = ft_death_philo(arg.philo);
		if (buffer == PHILO_LIFE)
			ft_prompt_think(arg);
	}
	return (arg_v);
}
