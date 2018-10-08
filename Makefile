# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/07 10:18:16 by zmiantud          #+#    #+#              #
#    Updated: 2018/09/27 13:01:32 by zmiantud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS :=	./srcs/main.c
SRCS += ./srcs/put_map.c
SRCS += ./srcs/functions0.c
SRCS += ./srcs/functions0_1.c
SRCS += ./srcs/functions1.c
SRCS += ./srcs/functions2.c
SRCS += ./srcs/functions3.c
SRCS += ./srcs/functions4.c
SRCS += ./srcs/mand_part_check.c
SRCS += ./srcs/start.c
SRCS += ./srcs/end.c
SRCS += ./srcs/room.c
SRCS += ./srcs/link.c
SRCS += ./srcs/algo.c
SRCS += ./srcs/stack.c
SRCS += ./srcs/ft_free.c
SRCS += ./srcs/free_functions.c
SRCS += ./srcs/send_ants.c
SRCS += ./srcs/ft_putmatrix.c

CC = gcc

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@echo "\033[34mCreating $(NAME) ...\033[0m"
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ) ./libft/libft.a
	@echo "\033[32m$(NAME) created succesfully\033[0m"

clean:
	@echo "\033[33mRemoving .o files of $(NAME) ...\033[0m"
	@make clean -C ./libft
	@rm -f $(OBJ)
	@echo "\033[31m.o files removed\033[0m"

fclean: clean
	@echo "\033[33mRemoving $(NAME) ...\033[0m"
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) removed successfully\033[0m"

run1: 
	make clean

run2: 
	make

run3:
	./lem-in

run: run1 run2 run3

re: fclean all
