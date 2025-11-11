# Nomeando - Nome do executavel
NAME = libftprintf.a

# Nomeando - Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Nomeando - Arquivos fontes para compilar
SRCS = ft_printf.c ft_print.c

# Nomeando - Arquivos objetos
OBJ = $(SRCS:.c=.o)

# Compilar os .c em .o
%.o: %.c includes.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

# Regra principal
all: $(NAME)

# Regra principal - cria biblioteca
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# remove os objetos
clean:
	rm -f $(OBJ)

# remove os ojbetos e a biblioteca
fclean:
	rm -f $(NAME) $(OBJ)

# recompila tudo de novo
re: fclean all

.PHONY: all clean fclean re
