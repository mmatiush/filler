#include "libft.h"
#include "filler.h"

int	check_if_coord_valid(t_fil_node *fil, int j, int i)
{
	int my_point_flag;
	t_p_coords *p_coords;

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

void	add_valid_coord(t_fil_node* fil, int j, int i)
{
	t_p_coords *temp;

	temp = (t_p_coords*)malloc(sizeof(t_p_coords));
	temp->x = j;
	temp->y = i;
	temp->next = fil->valid_coords;
	fil->valid_coords = temp;
}

void	get_valid_placing_coordinates(t_fil_node *fil)
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
				add_valid_coord(fil, i, j);
			j++;
		}
		i++;
	}
}

void	delete_coords_struct(t_p_coords *coords)
{
	if (!coords)
		return ;
	delete_coords_struct(coords->next);
	free(coords);
	coords = NULL;
}

void	free_str_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	delete_fil_struct(t_fil_node *fil)
{
	delete_coords_struct(fil->p_coords);
	fil->p_coords = NULL;
	delete_coords_struct(fil->valid_coords);
	fil->valid_coords = NULL;
	free_str_arr(fil->board);
	fil->board = NULL;
	free_str_arr(fil->piece);
	fil->piece = NULL;
	fil->c_my = '\0';
	fil->c_enemy = '\0';
	fil->b_x = 0;
	fil->b_y = 0;
	fil->p_x = 0;
	fil->p_y = 0;
}

int		main(void)
{
	t_fil_node	fil;

	fil.p_coords = (t_p_coords*)malloc(sizeof(t_p_coords));
	fil.valid_coords = NULL;
	get_fil_player_char(&fil);
	fill_out_fil(&fil);

	// fil_print_board(&fil);
	// fil_print_piece(&fil);
	if (!(get_piece_coordintaes(fil.piece, fil.p_x, fil.p_y, fil.p_coords)))
		return (0);
	get_valid_placing_coordinates(&fil);
	//ft_printf("%d, %d", fil.valid_coords->y, fil.valid_coords->x);
	delete_fil_struct(&fil);
	//fil_print_piece_coords(fil.valid_coords);
	//ft_printf("c_my = %c\n", fil.c_my);
	// ft_printf("b_x =  %d\n", fil.b_x);
	// ft_printf("b_y =  %d\n", fil.b_y);
	// ft_printf("p_x =  %d\n", fil.p_x);
	// ft_printf("p_y =  %d\n", fil.p_y);
	return (0);
}
