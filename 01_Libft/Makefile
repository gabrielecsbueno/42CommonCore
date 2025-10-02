# Nome do executavel
NAME = libft.a

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Arquivos fontes para compilar
SRCS = ft_isalpha.c

# Arquivos objetos
OBJ = $(SRCS:.c=.o)

# Regra principal
all: $(NAME)

# Regra principal - cria biblioteca
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compilar o binario
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.PHONY: all
