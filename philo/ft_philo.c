/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:19:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/25 13:52:57 by tlassere         ###   ########.fr       */
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
			return (i);
		i++;
	}
	return (i);
}

static int	ft_join_thread(t_philo *philo, int philos_creat)
{
	int	i;

	i = 0;
	while (i < philos_creat)
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

static int	ft_good_philos(t_philo *philo, int philos_creat,
		t_arg_routine *rountin)
{
	if (philos_creat == philo->philos)
		return (1);
	if (philos_creat != 0)
		ft_philo_death(*(rountin), 0);
	return (0);
}

int	ft_philo(t_philo *philo)
{
	t_arg_routine	*arg;
	int				philos_creat;

	if (ft_make_philo(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_make_arg(&arg, philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	philos_creat = ft_make_thread(philo, arg);
	if (ft_good_philos(philo, philos_creat, arg))
		ft_check_death(philo, arg);
	if (ft_join_thread(philo, philos_creat) == ERR_JOIN_FAIL)
		return (free(arg), ERR_JOIN_FAIL);
	free(arg);
	return (0);
}
