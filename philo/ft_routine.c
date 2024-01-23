/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:02:44 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/23 21:19:39 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_change_time(t_arg_routine arg)
{
	pthread_mutex_lock(arg.brain->mutex_time);
	arg.brain->time_left = ft_get_timestamp();
	pthread_mutex_unlock(arg.brain->mutex_time);
}

void	ft_philo_death(t_arg_routine arg, int print)
{
	if (print)
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
	size_t	buffer_time;

	buffer = PHILO_LIFE;
	pthread_mutex_lock(arg.brain->mutex_right);
	ft_prompt_take_fork(arg);
	//if (ft_death_philo(arg.philo) == PHILO_DETH)
	//	return (pthread_mutex_unlock(arg.brain->mutex_right), PHILO_LIFE);
	pthread_mutex_lock(arg.brain->mutex_left);
	//if (ft_death_philo(arg.philo) == PHILO_DETH)
	//	return (pthread_mutex_unlock(arg.brain->mutex_left), pthread_mutex_unlock(arg.brain->mutex_right), PHILO_LIFE);
	//buffer_time = ft_get_timestamp() - philo_time_left(arg) + arg.philo->eat;
	//if (buffer_time > (size_t)arg.philo->death)
	//{
	//	printf("zu : %zu\n", buffer_time);
	//	//buffer_time = buffer_time - arg.philo->death;
	//	//if (buffer_time > (size_t)arg.philo->death)
	//		buffer_time = 0;
	//	buffer = PHILO_DETH;
	//}
	//else 
		buffer_time = arg.philo->eat;
	ft_prompt_take_fork(arg);
	*(arg.brain->fork_left) = 1;
	*(arg.brain->fork_right) = 1;
	ft_prompt_eat(arg);
	usleep(buffer_time * 1000);
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
	if (arg.pos % 2)
		usleep(600);
	ft_print_info(arg, "was life");
	while (buffer == PHILO_LIFE && arg.philo->count_eat)
	{
		buffer = ft_take_fork(arg);
		if (buffer == PHILO_LIFE)
			buffer = ft_philo_eat(arg);
		if (buffer == PHILO_DETH)
			ft_philo_death(arg, 1);
		else
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
