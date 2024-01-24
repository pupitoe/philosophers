/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:19:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/24 18:39:32 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_make_thread(t_philo *philo, t_arg_routine *arg)
{
	int		i;
	size_t	times_tamp;

	i = 0;
	while (i < philo->philos)
	{
		arg[i].pos = i;
		arg[i].philo = philo;
		arg[i].brain = philo->brain + i;
		i++;
	}
	i = 0;
	times_tamp = ft_get_timestamp();
	while (i < philo->philos)
	{
		arg[i].brain->time_left = times_tamp;
		if (pthread_create((philo->thread + i), NULL,
				&ft_routine, arg + i) != 0)
			return (ERR_THREAD_FAIL);
		i++;
	}
	return (0);
}

static int	ft_join_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philos)
	{
		if (pthread_join(philo->thread[i], NULL) != 0)
			return (ERR_JOIN_FAIL);
		i++;
	}
	return (0);
}

static int	ft_make_arg(t_arg_routine **arg, t_philo *philo)
{
	*arg = malloc(philo->philos * sizeof(t_arg_routine));
	if (*arg == NULL)
		return (MALLOC_FAIL);
	return (0);
}

void	ft_check_death(t_philo *philo, t_arg_routine *arg)
{
	int		i;
	int		buffer;
	size_t	times_tamp;
	size_t	philo_left;

	i = 0;
	buffer = PHILO_LIFE;
	while (buffer != PHILO_DETH && philo->count_eat)
	{
		if (i == 0)
		{
			buffer = ft_death_philo(philo);
			times_tamp = ft_get_timestamp();
		}
		philo_left = philo_time_left(arg[i]);
		if (times_tamp > philo_left
			&& times_tamp - philo_left > (size_t)philo->death)
		{
			ft_philo_death(*(arg + i), 1);
			buffer = PHILO_DETH;
		}
		i = (i + 1) % philo->philos;
		usleep(200);
	}
}

int	ft_philo(t_philo *philo)
{
	t_arg_routine	*arg;

	if (ft_make_philo(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_make_arg(&arg, philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_make_thread(philo, arg) == ERR_THREAD_FAIL)
		return (free(arg), ERR_THREAD_FAIL);
	ft_check_death(philo, arg);
	if (ft_join_thread(philo) == ERR_JOIN_FAIL)
		return (free(arg), ERR_JOIN_FAIL);
	free(arg);
	return (0);
}
