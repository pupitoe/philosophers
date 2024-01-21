/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:19:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/21 19:57:25 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_make_thread_content(t_philo *philo, t_arg_routine *arg, int i)
{
	arg[i].pos = i;
	arg[i].philo = philo;
	arg[i].brain = philo->brain + i;
	arg[i].brain->time_left = ft_get_timestamp();
	if (pthread_create((philo->thread + i), NULL,
			&ft_routine, arg + i) != 0)
		return (ERR_THREAD_FAIL);
	return (0);
}

static int	ft_make_thread(t_philo *philo, t_arg_routine *arg)
{
	int	i;

	i = 0;
	while (i < philo->philos)
	{
		//printf("th push %d\n", i);
		if (ft_make_thread_content(philo, arg, i) != 0)
			return (ERR_THREAD_FAIL);
		if (i + 2 < philo->philos)
		{
			if (ft_make_thread_content(philo, arg, i + 2) != 0)
				return (ERR_THREAD_FAIL);
			//printf("th push %d\n", i + 2);
		}
		//usleep(50);
		i = i + 1 + (i % 2) * 2;
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
		//printf("End of philo\n");
		if (i + 2 < philo->philos)
		{
			if (pthread_join(philo->thread[i + 2], NULL) != 0)
				return (ERR_JOIN_FAIL);
			//printf("End of philo\n");
		}
		i = i + 1 + (i % 2) * 2;
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

size_t	philo_time_left(t_arg_routine arg)
{
	size_t	buffer;

	pthread_mutex_lock(arg.brain->mutex_time);
	buffer = arg.brain->time_left;
	pthread_mutex_unlock(arg.brain->mutex_time);
	return (buffer);
}

void	ft_check_death(t_philo *philo, t_arg_routine *arg)
{
	int	i;
	int	buffer;
	size_t	time_temps;
	size_t	philo_left;

	i = 0;
	buffer = PHILO_LIFE;
	while (buffer != PHILO_DETH)
	{
		if (i == 0)
		{
			buffer = ft_death_philo(philo);
			time_temps = ft_get_timestamp();
			//printf("auwu\n");
		}
		if (buffer == PHILO_DETH)
			exit(12);
		//if (arg[i].brain->time_left < time_temps && arg[i].brain->time_left - time_temps <= (size_t)philo->death)
		philo_left = philo_time_left(arg[i]);
		if (time_temps > philo_left && time_temps - philo_left > (size_t)philo->death)
		{
			ft_philo_death(*(arg + i));
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
	ft_check_death(philo, arg); // <- datarace + fonctoionne pas bien ou le rest jsp;
	if (ft_join_thread(philo) == ERR_JOIN_FAIL)
		return (free(arg), ERR_JOIN_FAIL);
	free(arg);
	return (0);
}
