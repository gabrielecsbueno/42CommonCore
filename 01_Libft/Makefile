# Nome do executavel
NAME = teste

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Arquivos fontes para compilar
SRCS = main.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c

# Arquivos de cabecalho
HEADER = libft.h

# Arquivos objetos
OBJ = $(SRCS:.c=.o)

# Regra principal
all: $(NAME)

# Regra principal - cria biblioteca
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	rm -f $(OBJ)

# remove os ojbetos e a biblioteca
fclean:
	rm -f $(NAME)

# recompila tudo de novo
re: fclean all

.PHONY: all clean fclean re
