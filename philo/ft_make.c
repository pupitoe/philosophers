/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:56:55 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/13 15:25:41 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_make_brain(t_philo *philo)
{
	t_philo_brain	*philo_content;

	philo_content = malloc((philo->philos) * sizeof(t_philo_brain));
	if (philo_content == NULL)
		return (MALLOC_FAIL);
	memset(philo_content, 0, (philo->philos) * sizeof(t_philo_brain));
	philo->brain = philo_content;
	return (SUCCESS);
}

static int	ft_make_thread(t_philo *philo)
{
	pthread_t		*philo_th;

	philo_th = malloc((philo->philos) * sizeof(pthread_t));
	if (philo_th == NULL)
		return (MALLOC_FAIL);
	philo->thread = philo_th;
	return (SUCCESS);
}

int	ft_make_philo(t_philo *philo)
{
	if (ft_make_thread(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_make_brain(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_make_mutex(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	return (SUCCESS);
}
