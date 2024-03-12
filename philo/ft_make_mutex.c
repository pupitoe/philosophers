/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:51:34 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/12 21:58:23 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_set_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philos)
	{
		if (i == 0)
			philo->brain[i].mutex_left = philo->mutex + philo->philos - 1;
		else
			philo->brain[i].mutex_left = philo->mutex + i - 1;
		philo->brain[i].mutex_right = philo->mutex + i;
		philo->brain[i].mutex_time = philo->mutex + philo->philos + i;
		i++;
	}
}

static void	ft_make_mutex_loop_del(pthread_mutex_t *mutexs, int at)
{
	int	i;

	i = at;
	while (i)
	{
		i--;
		pthread_mutex_destroy(mutexs + i);
	}
}

static int	ft_make_mutex_loop(pthread_mutex_t *mutexs, int at)
{
	int	status;
	int	i;

	status = SUCCESS;
	i = 0;
	while (i < at && status == SUCCESS)
	{
		if (pthread_mutex_init(mutexs + i, NULL) != 0)
			status = FAIL;
		else
			i++;
	}
	if (status == FAIL)
		ft_make_mutex_loop_del(mutexs, i);
	return (status);
}

static int	ft_make_mutexs_static(t_philo *philo)
{
	int	status;

	status = SUCCESS;
	if (pthread_mutex_init(&philo->mutex_dead, NULL) != 0)
		status = FAIL;
	if (pthread_mutex_init(&philo->mutex_talk, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->mutex_dead);
		status = FAIL;
	}
	if (status == FAIL)
	{
		ft_make_mutex_loop_del(philo->mutex, philo->philos);
		ft_make_mutex_loop_del(philo->mutex + philo->philos, philo->philos);
	}
	return (status);
}

int	ft_make_mutex(t_philo *philo)
{
	int				status;
	pthread_mutex_t	*mutexs;

	status = MALLOC_FAIL;
	mutexs = malloc((philo->philos * 2) * sizeof(pthread_mutex_t));
	if (mutexs)
	{
		if (ft_make_mutex_loop(mutexs, philo->philos) == SUCCESS)
		{
			if (!(ft_make_mutex_loop(mutexs + philo->philos, philo->philos)))
			{
				if (ft_make_mutexs_static(philo) == SUCCESS)
				{
					philo->mutex = mutexs;
					ft_set_mutex(philo);
					status = SUCCESS;
				}
			}
			else
				ft_make_mutex_loop_del(mutexs, philo->philos);
		}
		if (status != SUCCESS)
			free(mutexs);
	}
	return (status);
}
