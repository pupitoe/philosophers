/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:16:55 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/16 22:26:40 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg_v)
{
	t_arg_routine	arg;
	int				buffer;

	arg = *(t_arg_routine *)arg_v;
	buffer = 0;
	while (buffer != PHILO_DETH && buffer != ROUND_REST)
	{
		buffer++;
	}
	return (arg_v);
}
