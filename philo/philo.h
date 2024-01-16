/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:27:32 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/15 22:16:54 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define PARS_SUCCES 0
# define PARS_FAIL -1
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# define MALLOC_FAIL -12

typedef struct s_philo_brain
{
	int				*fork_left;
	int				*fork_right;
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	size_t			time_left;
}				t_philo_brain;

typedef struct s_philo
{
	int				philos;
	int				death;
	int				eat;
	int				sleep;
	int				count_int;
	pthread_t		*thread;
	t_philo_brain	*brain;
	int				*forks;
	pthread_mutex_t	*mutex;
}				t_philo;

void	ft_print_exemple(void);
int		ft_parser(int argc, char **argv, t_philo *philo);
int		ft_philo(t_philo *philo);
void	ft_free_philo(t_philo *philos);
int		ft_make_philo(t_philo *philo);

#endif