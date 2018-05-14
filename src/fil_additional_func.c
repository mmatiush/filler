#include "libft.h"
#include "filler.h"

void fil_print_board(t_fil_struct *fil)
{
	int i = 0;
	while (fil->board[i])
		ft_printf("%s\n", fil->board[i++]);
}

void fil_print_piece(t_fil_struct *fil)
{
	int i = 0;
	while (fil->piece[i])
		ft_printf("%s\n", fil->piece[i++]);
}

void	fil_print_coords_list(t_coords_node *coords)
{
	while (coords)
	{
		ft_printf("[y - %d][x - %d]\n", coords->y, coords->x);
		coords = coords->next;
	}
	ft_printf("\n");
}

void	delete_coords_struct(t_coords_node **coords)
{
	if (!(*coords))
		return ;
	delete_coords_struct(&(*coords)->next);
	free(*coords);
	*coords = NULL;
}

void	delete_fil_struct(t_fil_struct *fil)
{
	delete_coords_struct(&fil->p_coords);
	delete_coords_struct(&fil->valid_coords);
	ft_free_str_arr(&fil->board);
	ft_free_str_arr(&fil->piece);
	fil->b_x = 0;
	fil->b_y = 0;
	fil->p_x = 0;
	fil->p_y = 0;
	fil->p_x_shift = 0;
	fil->p_y_shift = 0;
}

void	null_fil_struct(t_fil_struct *fil)
{
		fil->valid_coords = NULL;
		fil->p_coords = NULL;
		fil->board = NULL;
		fil->piece = NULL;
}
