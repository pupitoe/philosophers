/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:52:06 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/24 01:56:41 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_print_info(t_arg_routine arg, char *prompt)
{
	if (ft_death_philo(arg.philo) == PHILO_DETH)
		return (PHILO_DETH);
	printf("%zu %d %s\n", ft_get_timestamp(), arg.pos + 1, prompt);
	return (0);
}
