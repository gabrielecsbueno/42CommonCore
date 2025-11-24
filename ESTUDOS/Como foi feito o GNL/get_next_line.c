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
		return (NULL);
	}
	//se resto for NULL, quer dizer que ele nao tem nada
	if (!resto)
	{
		//inicializar resto como string vazia
		resto = ft_strdup("");
		if (!resto)
			return (NULL);
	}
	//alocar buffer, com tamanho BUFFER_SIZE + 1 para o '\0'
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	//se a alocacao falhar, liberar resto (se tiver algo) e retornar NULL
	if (!buffer)
	{
		ft_free_resto(&resto);
		return (NULL);
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
				//se der tudo certo, ele retona a linha
				return (line);
			}
			//se o resto esta vazio, ele libera o resto
			ft_free_resto(&resto);
			return (NULL);
		}
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
			return (NULL);
		}
		//e volta para o loop ate encontrar o '\n' em qq ponto da str resto
	}
	//libera o buffer poque nao vou usar mais
	free(buffer);
	//procura onde esta o \n na str
	index = ft_strindex(resto, '\n');
	//precisa passar para a linha tudo antes de \n, contando com o proprio \n
	//index + 1 porque ele comeca no 0 e quer incluir o \n tbm
	line = ft_substr(resto, 0, index + 1);
	//sempre verificar se a sbustr falhou
	if (!line)
	{
		//bom, se falhou, ela tem que liberar o resto, setar como NULL e sair
		ft_free_resto(&resto);
		return (NULL);
	}
	//agora se deu certo e a line ja tem ate \n
	//precisa colocar o resto que sobrou no resto
	//coloca no temporaio primeiro
	temp = resto;
	resto = ft_substr(temp, index + 1, ft_strlen(resto) - index - 1);
	//da free no resto para garantir que nao vai dar memory leak
	free(temp);
	//se a substr falhou
	if (!resto)
	{
		//libera a linha seta o resto como NULL e sai
		free(line);
		resto = NULL;
		return (NULL);
	}
	//e retorna a linha
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