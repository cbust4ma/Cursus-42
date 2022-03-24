# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbustama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 19:51:37 by cbustama          #+#    #+#              #
#    Updated: 2021/11/11 19:48:01 by cbustama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC=$(wildcard ./*.c)

OBJ=$(patsubst ./%.c, ./%.o, $(SRC))

LIBFT=../../libft

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

$(NAME): $(OBJ)
		@make -C $(LIBFT)
		@cp ../libft/libft.a ./$(NAME)
		@ar -rcs $(NAME) $(OBJ)
		@mkdir obj
		@mv $(OBJ) ./obj
		@rm -f $(OBJ)
		@rm -Rf obj

all: $(NAME)

clean:
		@$(RM) $(OBJ)
		@make clean -C $(LIBFT)

fclean: clean
		@${RM} libftprintf.a
		@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re .c .o
