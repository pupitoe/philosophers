/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:15:31 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/19 23:30:04 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death_philo(t_philo *philo)
{
	int	buffer;

	buffer = PHILO_LIFE;
	pthread_mutex_lock(&philo->mutex_dead);
	if (philo->philo_has_dead)
		buffer = PHILO_DETH;
	printf("philo dead : %d\n", philo->philo_has_dead);
	pthread_mutex_unlock(&philo->mutex_dead);
	return (buffer);
}

int	ft_print_info(t_arg_routine arg, char *prompt)
{
	struct timeval	tv;
	size_t			buffer;

	if (ft_death_philo(arg.philo) == PHILO_DETH)	
		return (PHILO_DETH);
	gettimeofday(&tv, NULL);
	buffer = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("%zu %d %s\n", buffer, arg.pos, prompt);
	return (0);
}
