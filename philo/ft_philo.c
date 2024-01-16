/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:19:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/15 22:19:52 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo(t_philo *philo)
{
	if (ft_make_philo(philo) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	return (0);
}
