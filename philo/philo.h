/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:27:32 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/21 14:46:50 by tlassere         ###   ########.fr       */
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
# define ERR_THREAD_FAIL -1
# define ERR_JOIN_FAIL -1
# define PHILO_DETH 69
# define PHILO_LIFE 24
# define ROUND_REST 42

typedef struct s_philo_brain
{
	int				*fork_left;
	int				*fork_right;
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	pthread_mutex_t	*mutex_time;
	size_t			time_left;
	int				count_eat;
}				t_philo_brain;

typedef struct s_philo
{
	int				philos;
	int				death;
	int				eat;
	int				sleep;
	int				count_eat;	
	int				philo_has_died;
	pthread_mutex_t	mutex_dead;
	pthread_t		*thread;
	t_philo_brain	*brain;
	int				*forks;
	pthread_mutex_t	*mutex;
}				t_philo;

typedef struct s_arg_routine
{
	int				pos;
	t_philo_brain	*brain;
	t_philo			*philo;
}				t_arg_routine;

void	ft_free_philo(t_philo *philos);
void	ft_print_exemple(void);
void	*ft_routine(void *arg);

int		ft_parser(int argc, char **argv, t_philo *philo);
int		ft_philo(t_philo *philo);
int		ft_make_philo(t_philo *philo);
int		ft_print_info(t_arg_routine arg, char *prompt);
int		ft_prompt_take_fork(t_arg_routine arg);
int		ft_prompt_eat(t_arg_routine arg);
int		ft_prompt_sleep(t_arg_routine arg);
int		ft_prompt_think(t_arg_routine arg);
int		ft_prompt_death(t_arg_routine arg);
size_t	ft_get_timestamp(void);

// to find out if someone has died
int		ft_death_philo(t_philo *philo);

// to set the death
void	ft_philo_death(t_arg_routine arg);

#endif