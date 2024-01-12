/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:27:23 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/12 21:37:00 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(void)
{
	int i = 69;
	(void)i;
	return ;
}

void	ft_sleep(void)
{
	int i = 69;
	(void)i;
	return ;
}

void	ft_think(void)
{
	int i = 69;
	(void)i;
	return ;
}

void *ft_routine(void *uwu)
{
	ft_eat();
	ft_think();
	ft_sleep();
	
	(void)uwu;
	return (NULL);
}

int	ft_philo(t_philo *philo)
{
	pthread_t *philos;

	philos = malloc(philo->philos * sizeof(pthread_t));
	if (philos == NULL)
		return (MALLOC_FAIL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 1)
		return (ft_print_exemple(), 0);
	memset(&philo, 0, sizeof(t_philo));
	if (ft_parser(argc, argv, &philo) == PARS_FAIL)
		return (printf("Error parsing !\n"), 0);
	return (0);
}
