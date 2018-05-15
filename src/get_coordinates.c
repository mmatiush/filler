#include "libft.h"
#include "filler.h"

int		check_if_coord_valid(t_fil_struct *fil, int j, int i)
{
	int				my_point_flag;
	t_coords_node	*p_coords;

	my_point_flag = 0;
	p_coords = fil->p_coords;
	while (p_coords)
	{
		if (fil->board[p_coords->y + i][p_coords->x + j] == fil->c_my)
		{
			my_point_flag++;
			if (my_point_flag > 1)
				return (0);
		}
		else if (fil->board[p_coords->y + i][p_coords->x + j] == fil->c_enemy)
			return (0);
		p_coords = p_coords->next;
	}
	if (my_point_flag == 1)
		return (1);
	else
		return (0);
}

void	add_valid_coord(t_coords_node **coords, int j, int i)
{
	t_coords_node *temp;

	temp = (t_coords_node*)malloc(sizeof(t_coords_node));
	temp->x = j;
	temp->y = i;
	temp->next = *coords;
	*coords = temp;
}

int		get_piece_coordintaes(t_fil_struct *fil, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (fil->piece[i][j] == '*')
				add_valid_coord(&fil->p_coords, j, i);
			j++;
		}
		i++;
	}
	return (1);
}

int		get_valid_placing_coordinates(t_fil_struct *fil)
{
	int i;
	int j;
	int max_x;
	int max_y;
	
	i = 0;
	max_x = fil->b_x - fil->p_x;
	max_y = fil->b_y - fil->p_y;
	while (i < max_y)
	{
		j = 0;
		while (j < max_x)
		{
			if (check_if_coord_valid(fil, j, i))
				add_valid_coord(&fil->valid_coords, j, i);
			j++;
		}
		i++;
	}
	return (1);
}
