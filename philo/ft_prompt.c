/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:20:42 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/20 14:08:15 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_prompt_death(t_arg_routine arg)
{
	ft_print_info(arg, "died", 0);
	return (0);
}

int	ft_prompt_take_fork(t_arg_routine arg)
{
	ft_print_info(arg, "has taken a fork", 1);
	return (0);
}

int	ft_prompt_eat(t_arg_routine arg)
{
	ft_print_info(arg, "is eating", 1);
	return (0);
}

int	ft_prompt_sleep(t_arg_routine arg)
{
	ft_print_info(arg, "is sleeping", 1);
	return (0);
}

int	ft_prompt_think(t_arg_routine arg)
{
	ft_print_info(arg, "is thinking", 1);
	return (0);
}
