/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:13 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/13 15:26:09 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 1)
		return (ft_print_exemple(), 0);
	memset(&philo, 0, sizeof(t_philo));
	if (ft_parser(argc, argv, &philo) == PARS_FAIL)
		return (printf("Error parsing !\n"), 0);
	if (philo.philos)
	{
		ft_philo(&philo);
		ft_free_philo(&philo);
	}
	return (SUCCESS);
}
