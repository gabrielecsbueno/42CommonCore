# Nome do executavel final
NAME = ft_display_file 

# compilador e flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Arquivos fonte
SRCS = ft_display_file.c

# Arquivos objeto
OBJ = $(SRCS:.c=.o)

# Regra principal - execucao (make)
all: $(NAME)

# Compila o binario
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Limpeza dos arquivos objetos
clean:
	rm -f $(OBJ)

# Limpeza dos arquivos objetos e a biblioteca
fclean: clean
	rm -f $(NAME)

# Declara regras que não são arquivos
.PHONY: all clean fclean
