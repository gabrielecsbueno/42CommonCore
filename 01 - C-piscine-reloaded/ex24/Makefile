# Nome do executavel final
NAME = libft.a 

# compilador e flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# diretorios
DIR_SRC = srcs
DIR_INC = includes
DIR_OBJ = objs

# Arquivos fonte
SRCS = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

# caminhos dos arquivos e para criacao de arquivos
SRC_PATH = $(addprefix $(DIR_SRC)/, $(SRCS))
OBJ = $(SRCS:.c=.o)
OBJ_PATH = $(addprefix $(DIR_OBJ)/, $(OBJ))

# Regra principal - execucao (make)
all: $(NAME)

# Regra principal - cria a biblioteca
$(NAME): $(OBJ_PATH)
	ar rcs $(NAME) $(OBJ_PATH)

# Compila os arquivos objeto
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -I$(DIR_INC) -c $< -o $@

# Limpeza dos arquivos objetos
clean:
	rm -rf $(DIR_OBJ)

# Limpeza dos arquivos objetos e a biblioteca
fclean: clean
	rm -f $(NAME)

# recompila tudo
re: fclean all

# Declara regras que não são arquivos
.PHONY: all clean fclean re
