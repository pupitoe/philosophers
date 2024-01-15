/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exemple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:00:16 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/15 14:44:06 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_exemple(void)
{
	printf("Arguments can range from 4 to 5 (the last is obtional) :\n");
	printf("The first argument: the number of philosophers.\n");
	printf("The second argument: the number of ");
	printf("milliseconds he manages to survive.\n");
	printf("The third: the time they take to eat in ");
	printf("milliseconds (they like spaghetti and the taste of forks).\n");
	printf("The fourth: the time they take to sleep in milliseconds.\n");
	printf("The fifth (obtional): the number of times philosofers ");
	printf("can eat before the program stops.\n");
}
