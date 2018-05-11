#include "libft.h"
#include "filler.h"

int		get_piece_coordintaes(char **piece, int x, int y, t_p_coords *coords)
{
	int i;
	int j;

	i = 0;
	t_p_coords *temp;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (piece[i][j] == '*')
			{
				coords->next = (t_p_coords*)malloc(sizeof(t_p_coords));
				temp = coords;
				coords->y = i;
				coords->x = j;
				coords = coords->next;
			}
			j++;
		}
		i++;
	}
	free(temp->next);
	temp->next = NULL;
	return (1);
}