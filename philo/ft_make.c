/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:56:55 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/15 14:49:39 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_make_fork(t_philo_brain *philo_content, t_philo *philo)
{
	int	*forks;
	int	i;

	forks = malloc(philo->philos * sizeof(int));
	if (forks == NULL)
		return (MALLOC_FAIL);
	i = 0;
	memset(forks, 0, philo->philos * sizeof(int));
	while (i < philo->philos)
	{
		if (i == 0)
			philo_content[i].fork_left = forks + philo->philos - 1;
		else
			philo_content[i].fork_left = forks + i - 1;
		philo_content[i].fork_right = forks + i;
		i++;
	}
	philo->forks = forks;
	return (0);
}

int	ft_make_brain(t_philo_brain **philo_content, t_philo *philo)
{
	*philo_content = malloc((philo->philos) * sizeof(t_philo_brain));
	if (*philo_content == NULL)
		return (MALLOC_FAIL);
	if (ft_make_fork(*philo_content, philo) == MALLOC_FAIL)
		return (free(*philo_content), MALLOC_FAIL);
	return (0);
}

int	ft_philo(t_philo *philo)
{
	pthread_t		*philo_th;
	t_philo_brain	*philo_content;

	philo_th = malloc((philo->philos) * sizeof(pthread_t));
	if (philo_th == NULL)
		return (MALLOC_FAIL);
	philo->thread = philo_th;
	if(ft_make_brain(&philo_content, philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	philo->brain = philo_content;
	return (0);
}
