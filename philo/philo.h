/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:27:32 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/08 00:01:44 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define PARS_SUCCES 0
# define PARS_FAIL -1
# include <stdio.h>
# include <string.h>

typedef struct s_philo
{
	int	philos;
	int	death;
	int	eat;
	int	sleep;
	int	count_int;
}				t_philo;

void	ft_print_exemple(void);
int		ft_parser(int argc, char **argv, t_philo *philo);

#endif
