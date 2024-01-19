/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:20:42 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/19 16:13:47 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_prompt_death(t_arg_routine arg)
{
	ft_print_info(arg, "died");
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
