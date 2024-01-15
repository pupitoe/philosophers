/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:26:48 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/15 14:47:53 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philo(t_philo *philos)
{
	if (philos->brain)
		free(philos->brain);
	if (philos->thread)
		free(philos->thread);
	if (philos->forks)
		free(philos->forks);
}
