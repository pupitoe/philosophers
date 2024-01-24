/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:56:55 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/24 22:15:44 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_make_brain(t_philo *philo)
{
	t_philo_brain	*philo_content;

	philo_content = malloc((philo->philos) * sizeof(t_philo_brain));
	memset(philo_content, 0, (philo->philos) * sizeof(t_philo_brain));
	if (philo_content == NULL)
		return (MALLOC_FAIL);
	philo->brain = philo_content;
	return (0);
}

static int	ft_make_mutex(t_philo *philo)
{
	pthread_mutex_t	*mutexs;
	int				i;

	mutexs = malloc((philo->philos * 2) * sizeof(pthread_mutex_t));
	if (mutexs == NULL)
		return (MALLOC_FAIL);
	i = 0;
	while (i < philo->philos)
	{
		pthread_mutex_init(mutexs + i, NULL);
		pthread_mutex_init(mutexs + philo->philos + i, NULL);
		if (i == 0)
			philo->brain[i].mutex_left = mutexs + philo->philos - 1;
		else
			philo->brain[i].mutex_left = mutexs + i - 1;
		philo->brain[i].mutex_right = mutexs + i;
		philo->brain[i].mutex_time = mutexs + philo->philos + i;
		i++;
	}
	pthread_mutex_init(&philo->mutex_dead, NULL);
	pthread_mutex_init(&philo->mutex_talk, NULL);
	philo->mutex = mutexs;
	return (0);
}

static int	ft_make_thread(t_philo *philo)
{
	pthread_t		*philo_th;

	philo_th = malloc((philo->philos) * sizeof(pthread_t));
	if (philo_th == NULL)
		return (MALLOC_FAIL);
	philo->thread = philo_th;
	return (0);
}

int	ft_make_philo(t_philo *philo)
{
	if (ft_make_thread(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_make_brain(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_make_mutex(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	return (0);
}
