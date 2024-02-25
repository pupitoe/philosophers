/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:20:42 by tlassere          #+#    #+#             */
/*   Updated: 2024/02/25 14:45:35 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_prompt_death(t_arg_routine arg)
{
	pthread_mutex_lock(&arg.philo->mutex_talk);
	ft_print_info(arg, "died");
	pthread_mutex_unlock(&arg.philo->mutex_talk);
	return (0);
}

int	ft_prompt_take_fork(t_arg_routine arg)
{
	pthread_mutex_lock(&arg.philo->mutex_talk);
	ft_print_info(arg, "has taken a fork");
	pthread_mutex_unlock(&arg.philo->mutex_talk);
	return (0);
}

int	ft_prompt_eat(t_arg_routine arg)
{
	pthread_mutex_lock(&arg.philo->mutex_talk);
	ft_print_info(arg, "is eating");
	pthread_mutex_unlock(&arg.philo->mutex_talk);
	return (0);
}

int	ft_prompt_sleep(t_arg_routine arg)
{
	pthread_mutex_lock(&arg.philo->mutex_talk);
	ft_print_info(arg, "is sleeping");
	pthread_mutex_unlock(&arg.philo->mutex_talk);
	return (0);
}

int	ft_prompt_think(t_arg_routine arg)
{
	pthread_mutex_lock(&arg.philo->mutex_talk);
	ft_print_info(arg, "is thinking");
	pthread_mutex_unlock(&arg.philo->mutex_talk);
	return (0);
}
