/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:20:42 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/18 21:20:46 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print_info(t_arg_routine arg, char *prompt)
{
	struct timeval	tv;
	size_t			buffer;

	gettimeofday(&tv, NULL);
	buffer = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("%zu %d %s\n", buffer, arg.pos, prompt);
	return (0);
}

int	ft_prompt_take_fork(t_arg_routine arg)
{
	ft_print_info(arg, "has taken a fork");
	return (0);
}

int	ft_prompt_eat(t_arg_routine arg)
{
	ft_print_info(arg, "is eating");
	return (0);
}

int	ft_prompt_sleep(t_arg_routine arg)
{
	ft_print_info(arg, "is sleeping");
	return (0);
}

int	ft_prompt_think(t_arg_routine arg)
{
	ft_print_info(arg, "is thinking");
	return (0);
}
