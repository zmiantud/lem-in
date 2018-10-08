# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 16:43:05 by zmiantud          #+#    #+#              #
#    Updated: 2018/08/31 09:41:58 by zmiantud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = $(wildcard *.c)
SOURCE = $(wildcard *.o)
INCLUDES = libft.h

$(NAME):
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(SOURCES)
	ar rc $(NAME) *.o
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(SOURCE)

fclean: clean
	rm -f $(NAME)


re: fclean all
