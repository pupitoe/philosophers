/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:19:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/17 23:45:31 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_make_thread(t_philo *philo, t_arg_routine *arg)
{
	int	i;

	i = 0;
	while (i < philo->philos)
	{
		if (i % 2)
		{
			arg[i].pos = i;
			arg[i].philo = philo;
			arg[i].brain = philo->brain + i;
			if (pthread_create((philo->thread + i), NULL,
					&ft_routine, arg + i) != 0)
				return (ERR_THREAD_FAIL);
		}
		i++;
	}
	i = 0;
	while (i < philo->philos)
	{
		if (!(i % 2))
		{
			arg[i].pos = i;
			arg[i].philo = philo;
			arg[i].brain = philo->brain + i;
			if (pthread_create((philo->thread + i), NULL,
					&ft_routine, arg + i) != 0)
				return (ERR_THREAD_FAIL);
		}
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
		if (i % 2)
		{
			if (pthread_join(philo->thread[i], NULL) != 0)
				return (ERR_JOIN_FAIL);
			printf("End of philo\n");
		}
		i++;
	}
	i = 0;
	while (i < philo->philos)
	{
		if (!(i % 2))
		{
			if (pthread_join(philo->thread[i], NULL) != 0)
				return (ERR_JOIN_FAIL);
			printf("End of philo\n");
		}
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

int	ft_philo(t_philo *philo)
{
	t_arg_routine	*arg;

	if (ft_make_philo(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_make_arg(&arg, philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_make_thread(philo, arg) == ERR_THREAD_FAIL)
		return (free(arg), ERR_THREAD_FAIL);
	if (ft_join_thread(philo) == ERR_JOIN_FAIL)
		return (free(arg), ERR_JOIN_FAIL);
	free(arg);
	return (0);
}
