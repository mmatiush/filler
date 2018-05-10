#include "libft.h"
#include "filler.h"

int		get_piece_coordintaes(char **piece, int x, int y, t_coords *coords)
{
	int i;
	int j;

	i = 0;
	t_coords *temp;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (piece[i][j] == '*')
			{
				coords->next = (t_coords*)malloc(sizeof(t_coords));
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

void	fil_print_piece_coords(t_coords *coords)
{
	while (coords)
	{
		ft_printf("[y - %d][x - %d]\n", coords->y, coords->x);
		coords = coords->next;
	}
}

int		main(void)
{
	t_fil_node	fil;

	fil.coords = (t_coords*)malloc(sizeof(t_coords));
	get_fil_player_char(&fil);
	fill_out_fil(&fil);

	//fil_print_board(&fil);
	fil_print_piece(&fil);
	if (!(get_piece_coordintaes(fil.piece, fil.p_x, fil.p_y, fil.coords)))
		return (0);
	fil_print_piece_coords(fil.coords);
	// ft_printf("c_my = %c\n", fil.c_my);
	// ft_printf("b_x =  %d\n", fil.b_x);
	// ft_printf("b_y =  %d\n", fil.b_y);
	// ft_printf("p_x =  %d\n", fil.p_x);
	// ft_printf("p_y =  %d\n", fil.p_y);
	system ("leaks --quiet mmatiush.filler");
	return (0);
}
