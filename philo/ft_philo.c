/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:19:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/13 15:27:22 by tlassere         ###   ########.fr       */
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
		arg[i].brain->count_eat = 0;
		arg[i].arg = arg;
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
	int	status;

	i = 0;
	status = SUCCESS;
	while (i < philos_creat)
	{
		if (pthread_join(philo->thread[i], NULL) != 0)
			status = ERR_JOIN_FAIL;
		i++;
	}
	return (status);
}

static int	ft_make_arg(t_arg_routine **arg, t_philo *philo)
{
	*arg = malloc(philo->philos * sizeof(t_arg_routine));
	if (*arg == NULL)
		return (MALLOC_FAIL);
	return (SUCCESS);
}

static int	ft_good_philos(t_philo *philo, int philos_creat,
		t_arg_routine *rountin)
{
	int	status;

	status = SUCCESS;
	if (philos_creat != philo->philos)
	{
		status = FAIL;
		ft_philo_death(*(rountin), 0);
	}
	return (status);
}

int	ft_philo(t_philo *philo)
{
	int				status;
	int				philos_creat;
	t_arg_routine	*arg;

	status = MALLOC_FAIL;
	if (ft_make_philo(philo) == SUCCESS && ft_make_arg(&arg, philo) == SUCCESS)
	{
		status = SUCCESS;
		philos_creat = ft_make_thread(philo, arg);
		if (ft_good_philos(philo, philos_creat, arg) == SUCCESS)
			ft_check_death(philo, arg);
		if (ft_join_thread(philo, philos_creat) == ERR_JOIN_FAIL)
			status = ERR_JOIN_FAIL;
		free(arg);
	}
	return (status);
}
