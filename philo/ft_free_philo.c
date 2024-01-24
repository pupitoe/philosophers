/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:26:48 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/24 18:18:31 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_delet_mutex(t_philo *philo)
{
	int	i;
	int	all_mutex;

	i = 0;
	all_mutex = philo->philos * 2;
	while (i < all_mutex)
	{
		pthread_mutex_destroy(philo->mutex + i);
		i++;
	}
}

void	ft_free_philo(t_philo *philos)
{
	if (philos->brain)
		free(philos->brain);
	if (philos->thread)
		free(philos->thread);
	if (philos->mutex)
	{
		pthread_mutex_destroy(&philos->mutex_dead);
		pthread_mutex_destroy(&philos->mutex_talk);
		ft_delet_mutex(philos);
		free(philos->mutex);
	}
}
