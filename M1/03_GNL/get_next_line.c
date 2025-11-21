/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:16 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/21 21:07:04 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //DEBUG

static void	ft_free_resto(char **resto);

char	*get_next_line(int fd)
{
	static char	*resto = NULL;
	int			bytes_read;
	char		*buffer;
	int			index;
	char		*temp;
	char		*line;

	//verificacoes iniciais
	// SE FD INVALIDO OU BUFFER_SIZE <= 0
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		//se resto tiver algo, liberar ele antes de retornar NULL
		ft_free_resto(&resto);
		//se ele nao tiver nada, retornar NULL direto
		return (NULL);
	}
	//printf("DEBUG 01: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
	//alocar buffer, com tamanho BUFFER_SIZE + 1 para o '\0'
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	//se a alocacao falhar, liberar resto (se tiver algo) e retornar NULL
	if (!buffer)
	{
		//se resto tiver algo, liberar ele antes de retornar NULL
		ft_free_resto(&resto);
		//se ele nao tiver nada, retornar NULL direto
		return (NULL);
	}
	//se resto for NULL, quer dizer que ele nao tem nada
	if (!resto)
	{
		//inicializar resto como string vazia
		resto = ft_strdup("");
		//se a alocacao falhar, liberar buffer e retornar NULL
		//printf("DEBUG 02: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
		if (!resto)
		{
			free(buffer);
			//printf("DEBUG 03: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
			return (NULL);
		}
	}
	//ler do fd enquanto nao encontrar '\n' em resto
	while (ft_strindex(resto, '\n') == -1)
	{
		//ler do fd e coloca no buffer
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		//se der erro na leitura, ele libera o buffer
		if (bytes_read < 0)
		{
			//ele faz free do buffer e do resto antes de sair
			free(buffer);
			ft_free_resto(&resto);
			//printf("DEBUG 04: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
			//precisa setar o resto como NULL para evitar dar merda na proxima chamada
			return (NULL);
		}
		//agora se retorna 0, quer dizer que charou no final do arquivo (EOF)
		if (bytes_read == 0)
		{
			//entao ele faz free do buffer
			free(buffer);
			//se o resto tiver algo, e seu primeiro char nao for '\0' (no fim da str)
			//quer dizer que ainda tem algo para retornar
			if (resto && resto[0] != '\0')
			{
				//ele duplica o resto para a linha que vai retorno
				line = ft_strdup(resto);
				//precisa liberar o reto e setar ele como NULL
				ft_free_resto(&resto);
				//se o strdup falhar, ele retorna NULL
				if (!line)
					return (NULL);
				//printf("DEBUG 05: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
				//se der tudo certo, ele retona a linha
				return (line);
			}
			//agora se ele esta alicado mais nao tem nada, ele libera o resto
			ft_free_resto(&resto);
			//printf("DEBUG 06: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
			return (NULL);
		}
		//fecha a str com o '\0'
		buffer[bytes_read] = '\0';
		//concatena o que ja tinha no resto com o que acabou de ler no buffer
		temp = resto;
		//agora o resto recebe a nova str concatenada junto com o buffer
		resto = ft_strjoin(temp, buffer);
		//libera o temp para evitar memory leak
		free(temp);
		//se a strjoin falhar, ele libera o buffer e sai com NULL
		if (!resto)
		{
			free(buffer);
			//printf("DEBUG 07: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
			return (NULL);
		}
		//e volta para o loop ate encontrar o '\n' em qq ponto da str resto
	}
	//libera o buffer poque nao vou usar mais
	free(buffer);
	//agora que ja saiu do loop
	//se o resto for NULL, ele sai com NULL
	//printf("DEBUG 08: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
	if (!resto)
	{
		//printf("DEBUG 09: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
		return (NULL);
	}
	//se nao
	//ele procura onde esta o \n na str
	index = ft_strindex(resto, '\n');
	// ------
	if(index == -1)
	{
		//quer dizer que nao tem \n na str
		//entao ele duplica todo o resto para a linha
		line = ft_strdup(resto);
		//libera o resto e seta como NULL
		ft_free_resto(&resto);
		//se o strdup falhar, retorna NULL
		//printf("DEBUG 10: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
		if (!line)
			return (NULL);
		//se der tudo certo, retorna a linha
		return (line);
	}
	// ------

	//precisa passar para a linha tudo antes de \n, contando com o proprio \n
	//index + 1 porque ele comeca no 0 e quer incluir o \n tbm
	line = ft_substr(resto, 0, index + 1);
	//sempre verificar se a sbustr falhou
	//printf("DEBUG 11: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
	if (!line)
	{
		//bom, se falhou, ela tem que liberar o resto, setar como NULL e sair
		ft_free_resto(&resto);
		return (NULL);
	}
	//printf("DEBUG 11.5: line address: %p, length: %zu\n", (void*)line, ft_strlen(line));
	//agora se deu certo e a line ja tem ate \n
	//precisa colocar o resto que sobrou no resto
	//coloca no temporaio primeiro
	temp = ft_substr(resto, index + 1, ft_strlen(resto) - index - 1);
	//printf("DEBUG 11.6: temp address: %p, length: %zu\n", (void*)temp, ft_strlen(temp));
	//da free no resto para garantir que nao vai dar memory leak
	ft_free_resto(&resto);
	//se a substr falhou
	//printf("DEBUG 12: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
	if (!temp)
	{
		//libera a linha seta o resto como NULL e sai
		free(line);
		resto = NULL;
		//printf("DEBUG 13: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
		return (NULL);
	}
	// se nao passa tudo que sobrou para o resto
	resto = temp;
	//e retorna a linha
	//printf("DEBUG 14: resto address: %p, length: %zu\n", (void*)resto, ft_strlen(resto));
	return (line);
}

static void	ft_free_resto(char **resto)
{
	if (resto && *resto)
	{
		free(*resto);
		*resto = NULL;
	}
}