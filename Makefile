# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adel <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 11:00:32 by adel              #+#    #+#              #
#    Updated: 2024/03/19 11:20:05 by adel             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

SRC = client.c

INCLUDE =	-I minitalk

OBJS = $(SRC:.c=.o)

CC = cc
Rm = rm -f
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g $(INCLUDE)


all: $(OBJS) $(NAME)

$(NAME) :	$(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		$(RM) $(OBJS)

fclean :	clean
		$(RM) $(NAME)

re :	fclean $(NAME)

.PHONY: all clean fclean re
