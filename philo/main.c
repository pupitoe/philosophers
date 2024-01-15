/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:13 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/15 14:45:18 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(void)
{
	int i = 69;
	(void)i;
	return ;
}

void	ft_sleep(void)
{
	int i = 69;
	(void)i;
	return ;
}

void	ft_think(void)
{
	int i = 69;
	(void)i;
	return ;
}

void *ft_routine(void *uwu)
{
	ft_eat();
	ft_think();
	ft_sleep();
	
	(void)uwu;
	return (NULL);
}

void *foo1(void *data)
{
	int i = 0;

	while (i < 5)
	{
		printf("no sleep\n");
		sleep(1);
		printf("sleep\n");
		i++;
	}
	printf("finish sleep\n");
	return (data);
}

void *foo2(void *data)
{
	while (1)
	{
		usleep(5000);
		printf("do have\n");
	}
	printf("finish");
	return (data);
}


void *foo3(void *data)
{
	static int a = 0;
	pthread_mutex_t *mutex = data;
	pthread_mutex_lock(mutex);
	a++;	
	printf("a : %d\n", a);
	printf("uwu\n");
	sleep(2);
	pthread_mutex_unlock(mutex);
	return (data);
}

int	main(int argc, char **argv)
{

	//pthread_t th1;
	//pthread_t th2;
	//pthread_t th3;
	
	//pthread_mutex_t mutex;
	//pthread_mutex_init(&mutex, NULL);
	//pthread_mutex_t mutex2;
	//pthread_mutex_init(&mutex2, NULL);



	//pthread_create(&th1, NULL, &foo3, &mutex);
	//usleep(10);
	//pthread_create(&th2, NULL, &foo3, &mutex2);
	//pthread_create(&th3, NULL, &foo3, &mutex);
	//pthread_detach(th2);
	//pthread_detach(th1);

	//pthread_join(th1, NULL);
	//pthread_join(th2, NULL);
	//pthread_join(th3, NULL);
	//printf("thread end\n");
	//pthread_mutex_destroy(&mutex);
	//pthread_mutex_destroy(&mutex2);
	t_philo	philo;

	if (argc == 1)
		return (ft_print_exemple(), 0);
	memset(&philo, 0, sizeof(t_philo));
	if (ft_parser(argc, argv, &philo) == PARS_FAIL)
		return (printf("Error parsing !\n"), 0);
	ft_philo(&philo);
	ft_free_philo(&philo);
	return (0);
}
