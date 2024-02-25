/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:10:53 by tlassere          #+#    #+#             */
/*   Updated: 2024/02/25 15:45:19 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_eat(t_philo *philo, t_arg_routine *arg)
{
	int	result;
	int	i;

	i = 0;
	result = SUCCESS;
	if (philo->count_eat > 0)
	{
		while (i < philo->philos && result == SUCCESS)
		{
			pthread_mutex_lock(arg[i].brain->mutex_time);
			if (arg[i].brain->count_eat < philo->count_eat)
				result = FAIL;
			pthread_mutex_unlock(arg[i].brain->mutex_time);
			i++;
		}
		if (result == SUCCESS)
			ft_philo_death(*arg, 0);
	}
	else
		result = FAIL;
	return (result);
}
