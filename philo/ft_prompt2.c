/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:15:31 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/21 19:08:14 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_death_philo(t_philo *philo)
{
	int	buffer;

	buffer = PHILO_LIFE;
	pthread_mutex_lock(&philo->mutex_dead);
	//usleep(100);
	if (philo->philo_has_died)
		buffer = PHILO_DETH;
	pthread_mutex_unlock(&philo->mutex_dead);
	return (buffer);
}

int	ft_print_info(t_arg_routine arg, char *prompt)
{
	if (ft_death_philo(arg.philo) == PHILO_DETH)
		return (PHILO_DETH);
	printf("%zu %d %s\n", ft_get_timestamp(), arg.pos + 1, prompt);
	return (0);
}
