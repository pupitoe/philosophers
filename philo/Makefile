# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 15:58:16 by tlassere          #+#    #+#              #
#    Updated: 2024/03/12 15:58:16 by tlassere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = 	main.c ft_exemple.c ft_parser.c ft_make.c ft_philo.c ft_routine.c \
			ft_free_philo.c	ft_prompt.c ft_prompt2.c ft_death.c	ft_philo_eat.c \
			ft_philo_take_fork.c ft_parser_time.c ft_make_mutex.c

OBJS = $(SOURCES:.c=.o)
HEADER = philo.h

NAME = philo

CFLAGS = -Wall -Wextra -Werror -g3 -pthread #-fsanitize=thread
CC = cc

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
