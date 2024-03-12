/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:10:51 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/12 17:20:53 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parser_time(t_philo *philo)
{
	int	status;

	status = PARS_SUCCES;
	if (philo->eat > USLEEP_MAX_TIME
		|| philo->sleep > USLEEP_MAX_TIME
		|| philo->death > USLEEP_MAX_TIME)
		status = PARS_FAIL;
	return (status);
}
