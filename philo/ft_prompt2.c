/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:15:31 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/20 14:06:30 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death_philo(t_philo *philo)
{
	int	buffer;

	buffer = PHILO_LIFE;
	pthread_mutex_lock(&philo->mutex_dead);
	usleep(100);
	if (philo->philo_has_dead)
		buffer = PHILO_DETH;
	//printf("philo dead : %d\n", philo->philo_has_dead);
	pthread_mutex_unlock(&philo->mutex_dead);
	return (buffer);
}

int	ft_print_info(t_arg_routine arg, char *prompt, int checker)
{
	struct timeval	tv;
	size_t			buffer;

	if (checker && ft_death_philo(arg.philo) == PHILO_DETH)	
		return (PHILO_DETH);
	gettimeofday(&tv, NULL);
	buffer = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("%zu %d %s\n", buffer, arg.pos, prompt);
	return (0);
}
