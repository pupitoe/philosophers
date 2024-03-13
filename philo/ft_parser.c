/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:24:23 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/13 15:47:17 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	ft_atoi(char *str)
{
	size_t	i;
	int		nbr;

	nbr = 0;
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		nbr = (nbr * 10) + str[i] - '0';
		if (nbr % 10 != str[i] - '0')
			return (-1);
		i++;
	}
	return (nbr);
}

static int	ft_check_str(char *str)
{
	size_t	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (PARS_FAIL);
		i++;
	}
	return (PARS_SUCCES);
}

static int	ft_check_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_check_str(argv[i]) == PARS_FAIL)
			return (PARS_FAIL);
		i++;
	}
	return (PARS_SUCCES);
}

int	ft_parser(int argc, char **argv, t_philo *philo)
{
	if (!(argc >= 5 && argc <= 6))
		return (PARS_FAIL);
	if (ft_check_argv(argv) == PARS_FAIL)
		return (PARS_FAIL);
	philo->philos = ft_atoi(argv[1]);
	philo->death = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
	philo->count_eat = -2;
	if (argc == 6)
		philo->count_eat = ft_atoi(argv[5]);
	if (philo->philos == -1
		|| philo->death <= 0
		|| philo->eat <= 0
		|| philo->sleep <= 0
		|| philo->count_eat == -1)
		return (PARS_FAIL);
	if (philo->philos > 1000)
	{
		printf("The max number of philosophers is 1000\n");
		return (PARS_FAIL);
	}
	return (ft_parser_time(philo));
}
