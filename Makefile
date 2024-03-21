SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all: server client

bonus: server client

server: server.o libft ft_printf 
	$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft 

ft_printf:
	make -C ft_printf

clean:
	rm -f $(OBJECTS)
	make -C libft 
	make -C ft_printf clean
	
fclean: clean
	rm -f server client libft/libft.a 
	rm -f ft_printf/ft_printf.a

re: fclean all

.PHONY: all bonus libft ft_printf clean fclean re