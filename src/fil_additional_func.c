#include "libft.h"
#include "filler.h"

void fil_print_board(t_fil_node	*fil)
{
	int i = 0;
	while (fil->board[i])
		ft_printf("%s\n", fil->board[i++]);
}

void fil_print_piece(t_fil_node	*fil)
{
	int i = 0;
	while (fil->piece[i])
		ft_printf("%s\n", fil->piece[i++]);
}

void	fil_print_piece_coords(t_p_coords *coords)
{
	while (coords)
	{
		ft_printf("[y - %d][x - %d]\n", coords->y, coords->x);
		coords = coords->next;
	}
	ft_printf("\n");
}