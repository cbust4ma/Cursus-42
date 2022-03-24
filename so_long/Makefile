# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 15:17:44 by cbustama          #+#    #+#              #
#    Updated: 2022/03/23 16:05:00 by cbustama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC =  so_long.c\
	   input.c\
	   input_cotinue.c\
	   movements.c\
	   draw.c\
	   error_map.c\
	   continue_map_error.c
	

OBJ = so_long.o\
	  input.o\
	  input_cotinue.o\
	  movements.o\
	  draw.o\
	  error_map.o\
	  continue_map_error.o

SRC_BONUS =  so_long_bonus.c\
	   input_bonus.c\
	   input_cotinue_bonus.c\
	   movements_bonus.c\
	   draw_bonus.c\
	   error_map_bonus.c\
	   continue_map_error_bonus.c\
	   animation_bonus.c\
	   enemy_bonus.c

OBJ_BONUS =  so_long_bonus.o\
	   input_bonus.o\
	   input_cotinue_bonus.o\
	   movements_bonus.o\
	   draw_bonus.o\
	   error_map_bonus.o\
	   continue_map_error_bonus.o\
	   animation_bonus.o\
	   enemy_bonus.o


LIBFT = libft/libft.a

CFLAGS =  -Wall -Wextra -Werror -fsanitize=address -g3


CC = gcc -O3


GREEN = \033[1;32m
WHT = \033[1;37m
EOC = \033[1;0m

$(NAME): $(OBJ)
		@echo "$(WHT)[⚙️  ⚙️  COMPILING SO_LONG...⚙️  ⚙️ ]$(EOC)"
		@date
		@${MAKE} -C mlx 2>.null
		@${MAKE} -C libft
		@$(CC) $(CFLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) $(LIBFT)
		@echo "\n$(GREEN)[✅✅SO_LONG  done...✅✅]$(EOC)"
		@sleep 1
		@echo "\n $(GREEN)[ 🛠️  🛠️  Finish... 🛠️  🛠️ ]$(EOC)"
	
all: $(NAME) $(NAME_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $^ -o $@
	

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
		@echo "$(WHT)[⚙️  ⚙️  COMPILING SO_LONG BONUS ...⚙️  ⚙️ ]$(EOC)"
		@date
		@${MAKE} -C mlx 2>.null
		@${MAKE} -C libft
		@$(CC) $(CFLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)
		@echo "\n$(GREEN)[✅✅SO_LONG  done...✅✅]$(EOC)"
	

clean:
	@echo "$(WHT)[🧹 REMOVING O-FILES...🧹 ]$(EOC)"
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf $(OBJ_BONUS)
	@/bin/rm -rf .null
	@${MAKE} -C mlx clean
	@echo "$(GREEN)[✅✅CLEAN  DONE...✅✅]$(EOC)"
	@sleep 1
	@echo "\n$(GREEN)[ 🛠️  🛠️  Finish...🛠️   🛠️ ]$(EOC)"


fclean: clean
	@echo "$(WHT)[🧹 REMOVING ALL...🧹]$(EOC)"
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(NAME_BONUS)
	@${MAKE} -C libft fclean
	@echo "$(GREEN)[✅✅FCLEAN  DONE...✅✅]$(EOC)"
	@sleep 1
	@echo "\n $(GREEN)[ 🛠️  🛠️  Finish... 🛠️  🛠️ ]$(EOC)"

re: fclean all

.PHONY: all bonus clean fclean re

