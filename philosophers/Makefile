# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 19:30:17 by cbustama          #+#    #+#              #
#    Updated: 2022/05/30 17:51:25 by cbustama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c\
	  utils.c\
	  operations.c\
	  routine.c\
	  forks.c\

OBJ = $(SRC:.c=.o)

CC = gcc -MD -pthread -ggdb3 

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

.c.o: $(SRC)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME):$(OBJ)

	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	
all: $(NAME)
clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f *.d

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
