#include "libft.h"
#include "filler.h"

void		execute_piece_coords_moving(t_fil_struct *fil)
{
	t_coords_node *coords;

	if (fil->p_x_shift == 0 && fil->p_y_shift == 0)
		return ;
	coords = fil->p_coords;
	while (coords)
	{
		coords->x = coords->x - fil->p_x_shift;
		coords->y = coords->y - fil->p_y_shift;
		coords = coords->next;
	}
}

void		set_new_piece_max_coords(t_fil_struct *fil, int p_x_max, int p_y_max)
{
	fil->p_x = p_x_max - fil->p_x_shift + 1;
	fil->p_y = p_y_max - fil->p_y_shift + 1;
}

void		move_piece_coords_left_up(t_fil_struct *fil)
{
	t_coords_node	*p_coords;
	int				p_x_max;			
	int				p_y_max;			

	if (!fil->p_coords)
		return ;
	p_coords = fil->p_coords;
	fil->p_x_shift = p_coords->x;
	p_x_max = p_coords->x;
	fil->p_y_shift = p_coords->y;
	p_y_max = p_coords->y;
	while ((p_coords = p_coords->next))
	{
		if (p_coords->x < fil->p_x_shift)
			fil->p_x_shift = p_coords->x;
		if (p_coords->x > p_x_max)
			p_x_max = p_coords->x;
		if (p_coords->y < fil->p_y_shift)
			fil->p_y_shift = p_coords->y;
		if (p_coords->y > p_y_max)
			p_y_max = p_coords->y;
	}
	execute_piece_coords_moving(fil);
	set_new_piece_max_coords(fil, p_x_max, p_y_max);
}
