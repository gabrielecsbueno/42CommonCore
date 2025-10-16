# Nome do executavel
NAME = libft.a

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Arquivos fontes para compilar
SRCS = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c

# Arquivos objetos
OBJ = $(SRCS:.c=.o)

# Regra principal
all: $(NAME)

# Regra principal - cria biblioteca
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compilar os .c em .o
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# remove os objetos
clean:
	rm -f $(OBJ)

# remove os ojbetos e a biblioteca
fclean:
	rm -f $(NAME) $(OBJ)

# recompila tudo de novo
re: fclean all

.PHONY: all clean fclean re
