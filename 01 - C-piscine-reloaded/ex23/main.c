#include "ft_point.h"
#include <stdio.h>
void	set_point(t_point *point) 
//aqui estou nomeando a struct definida no .h como t_point para point
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point point; //aqui nomeando a typedef struct chamada t_point para point
	set_point(&point); //aqui modifica os valores do ponint
	printf("O valor de x = %d e valor de y = %d", point.x, point.y);
	return (0);
}