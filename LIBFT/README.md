# 💻 42 - LIBFT

## Funções Utilitárias em C

Este repositório contém uma lista de funções utilitárias em C. 
Cada função tem um propósito específico, relacionadas ao manuseio de strings, memória, conversões de caracteres e impressão. Elas são frequentemente usadas como base para implementar outras funcionalidades mais complexas.
A seguir, uma breve descrição de cada função.

---

### Funções de Manipulação de Caracteres

####  - Isalpha

`int	ft_isalpha (int c);`

Verifica se o caractere `c` é uma letra do alfabeto (tanto maiúscula quanto minúscula).
Retorna 1 se for, e 0 caso contrário.

#### - Isdigit

`int	ft_isdigit (int c);`

Verifica se o caractere `c` é um dígito (de '0' a '9').
Retorna 1 se for, e 0 caso contrário.

#### - Isalnum

`int	ft_isalnum (int c);`

Verifica se o caractere `c` é um caractere alfanumérico (letra ou número).
Retorna 1 se for, e 0 caso contrário.

#### - Isascii

`int	ft_isascii (int c);`

Verifica se o caractere `c` está dentro da tabela ASCII (de 0 a 127).
Retorna 1 se for, e 0 caso contrário.

#### -  Isprint

`int	ft_isprint (int c);`

Verifica se o caractere `c` é um caractere imprimível (excluindo caracteres de controle).
Retorna 1 se for, e 0 caso contrário.

#### - Toupper

`int	ft_toupper (int c);`

Converte o caractere `c` para maiúscula, se possível. Se `c` não for uma letra minúscula, retorna o próprio caractere.

#### - Tolower

`int	ft_tolower (int c);`

Converte o caractere `c` para minúscula, se possível. Se `c` não for uma letra maiúscula, retorna o próprio caractere.

---

### Funções de Manipulação de Strings

#### - Strlen

`size_t	ft_strlen (const char *s);`

Retorna o comprimento de uma string `s` (excluindo o caractere nulo `\0`).

#### - Strchr

`char	*ft_strchr (const char *s, int c);`

Encontra a primeira ocorrência do caractere `c` na string `s`.
Retorna um ponteiro para o caractere encontrado ou `NULL` caso não seja encontrado.

#### - Strrchr

`char	*ft_strrchr (const char *s, int c);`

Encontra a última ocorrência do caractere `c` na string `s`.
Retorna um ponteiro para o caractere encontrado ou `NULL` caso não seja encontrado.

#### - Strncmp

`int	ft_strncmp (const char *s1, const char *s2, size_t n);`

Compara as primeiras `n` letras das strings `s1` e `s2`.
Retorna 0 se forem iguais, um valor negativo se `s1` for menor que `s2`, ou um valor positivo caso contrário.

#### - Strnstr

`char	*ft_strnstr (const char *big, const char *little, size_t len);`

Procura a string `little` dentro da string `big`, considerando apenas os primeiros `len` caracteres. Retorna um ponteiro para a primeira ocorrência ou `NULL` se não encontrar.

#### - Strdup

`char	*ft_strdup (const char *s);`

Cria uma cópia dinâmica da string `s` e retorna o ponteiro para a nova string.

#### - Substr

`char *ft_substr (char const *s, unsigned int start, size_t len);`

Extrai uma substring de `s`, começando no índice `start` e com comprimento de `len`.
Retorna a substring ou `NULL` se não for possível.

#### - Strjoin

`char *ft_strjoin(char const *s1, char const *s2);`

Concatena as strings `s1` e `s2` em uma nova string.
Retorna a string resultante.

#### - Strtrim

`char	*ft_strtrim (char const *s1, char const *set);`

Remove os caracteres do conjunto `set` no início e no fim da string `s1`.
Retorna a string resultante.

#### - Split

`char	**ft_split (char const *s, char c);`

Divide a string `s` em substrings, usando o caractere `c` como delimitador.
Retorna um array de strings.

#### - Itoa

`char	*ft_itoa (int n);`

Converte o número inteiro `n` para uma string representando esse número.

#### - Strmapi

`char	*ft_strmapi (char const *s, char (*f)(unsigned int, char));`

Aplica a função `f` a cada caractere da string `s` e retorna uma nova string com os resultados.

#### - Striteri

`void	ft_striteri (char *s, void (*f)(unsigned int, char*));`

Aplica a função `f` a cada caractere da string `s`, passando também o índice de cada caractere.

---

## Funções de Manipulação de Memória

#### Memset

`void	*ft_memset (void *s, int c, size_t n);`

Preenche os primeiros `n` bytes da memória apontada por `s` com o valor `c`.

#### - Bzero

`void	ft_bzero (void *s, size_t n);`

Define os primeiros `n` bytes da memória apontada por `s` como zero (`\0`).

#### - Memcpy

`void	*ft_memcpy (void *dest, const void *src, size_t n);`

Copia `n` bytes da memória de `src` para `dest`. O comportamento é indefinido se `src` e `dest` se sobrepuserem.

#### - Memmove

`void	*ft_memmove (void *dest, const void *src, size_t n);`

Move `n` bytes da memória de `src` para `dest`, permitindo que as regiões de memória se sobreponham.

#### - Strlcpy

`size_t	ft_strlcpy (char *dst, const char *src, size_t dsize);`

Copia até `dsize` caracteres de `src` para `dst` e adiciona um caractere nulo ao final.
Retorna o comprimento de `src`.

#### - Strlcat

`size_t	ft_strlcat (char *dst, const char *src, size_t dsize);`

Concatena até `dsize` caracteres de `src` no final de `dst` e adiciona um caractere nulo ao final. Retorna o comprimento total da string concatenada.

#### - Memchr

`void	*ft_memchr (const void *s, int c, size_t n);`

Localiza o primeiro byte da memória `s` que contém o valor `c` (no intervalo dos primeiros `n` bytes).
Retorna um ponteiro para o byte encontrado ou `NULL` caso contrário.

#### - Memcmp

`int	ft_memcmp (const void *s1, const void *s2, size_t n);`

Compara os primeiros `n` bytes de `s1` e `s2`. Retorna 0 se forem iguais, um valor negativo se `s1` for menor que `s2`, ou um valor positivo caso contrário.

---

## Funções de Impressão

#### - Putchar_fd

`void	ft_putchar_fd (char c, int fd);`

Escreve o caractere `c` no arquivo descrito pelo descritor de arquivo `fd`.

#### - Putstr_fd

`void	ft_putstr_fd (char *s, int fd);`

Escreve a string `s` no arquivo descrito pelo descritor de arquivo `fd`.

#### - Putendl_fd

`void	ft_putendl_fd (char *s, int fd);`

Escreve a string `s` seguida por uma nova linha no arquivo descrito pelo descritor de arquivo `fd`.

#### - Putnbr

`void	ft_putnbr_fd (int n, int fd);`

Escreve o número inteiro `n` no arquivo descrito pelo descritor de arquivo `fd`.

---

## Funções de Alocação Dinâmica

#### - Calloc

`void	*ft_calloc (size_t nmemb, size_t size);`

Aloca memória para um array de `nmemb` elementos de `size` bytes cada e inicializa toda a memória com zero. Retorna um ponteiro para a memória alocada.

#### - Atoi

`int	ft_atoi (const char *nptr);`

Converte a string `nptr` para um número inteiro.

---

## Compilação

Para compilar essas funções, você pode usar o seguinte comando:

```bash
make
gcc libft.a *.c
```
