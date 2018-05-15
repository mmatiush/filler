#include "libft.h"
#include "filler.h"

int		fil_put_index(t_fil_struct *fil, char **board, int i, int j, char index)
{
	if (j >= 1 && board[i][j - 1] == '.')
		board[i][j - 1] = index++;
	if (j >= 1 && i >= 1 && board[i - 1][j - 1] == '.')
		board[i - 1][j - 1] = index++;
	if (i >= 1 && board[i - 1][j] == '.')
		board[i - 1][j] = index++;
	if (i >= 1 && j < fil->b_x - 1 && board[i - 1][j + 1] == '.')
		board[i - 1][j + 1] = index++;
	if (j < fil->b_x - 1 && board[i][j + 1] == '.')
		board[i][j + 1] = index++;
	if (i < fil->b_y - 1 && j < fil->b_x - 1 && board[i + 1][j + 1] == '.')
		board[i + 1][j + 1] = index++;
	if (i < fil->b_y - 1 && board[i + 1][j] == '.')
		board[i + 1][j] = index++;
	if (j >= 1 && i < fil->b_y - 1 && board[i + 1][j - 1] == '.')
		board[i + 1][j - 1] = index++;
}

int		check_board_dots(t_fil_struct *fil)
{
	int i;
	int j;

	i = 0;
	while (i < fil->b_y)
	{
		j = 0;
		while (j < fil->b_x)
		{
			if (fil->board[i][j] == '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	fil_index_board(t_fil_struct *fil)
{
	int i;
	int j;
	int index1;
	int index2;
	int temp;
	int flag;

	index1 = '*';
	index2 = '#';
	while (check_board_dots(fil))
	{
		flag = 0;
		i = 0;
		while (i < fil->b_y)
		{
			j = 0;
			while (j < fil->b_x)
			{
				if (fil->board[i][j] == fil->c_enemy || fil->board[i][j] == index1)
				{
					flag = fil_put_index(fil, fil->board, i, j, index2);
					flag = 1;
				}
				j++;
			}
			i++;
		}
		if (flag == 0)
			return ;
		temp = index1;
		index1 = index2;
		index2 = temp;
	}
}

// int		check_enemy_by_coords(t_fil_struct *fil, int i, int j, int r, char **board)
// {
// 	if (j >= r && fil->board[i][j - r] == fil->c_enemy)
// 		return (1);
// 	if (j >= r && i >= r && fil->board[i - r][j - r] == fil->c_enemy)
// 		return (1);
// 	if (i >= r && fil->board[i - r][j] == fil->c_enemy)
// 		return (1);
// 	if (i >= r && j < fil->b_x - r && fil->board[i - r][j + r] == fil->c_enemy)
// 		return (1);
// 	if (j < fil->b_x - r && fil->board[i][j + r] == fil->c_enemy)
// 		return (1);
// 	if (i < fil->b_y - r && j < fil->b_x - r && fil->board[i + r][j + r] == fil->c_enemy)
// 		return (1);
// 	if (i < fil->b_y - r && fil->board[i + r][j] == fil->c_enemy)
// 		return (1);
// 	if (j > r && i < fil->b_y - r && fil->board[i + r][j - r] == fil->c_enemy)
// 		return (1);
// }

// int		check_enemy_by_coords(t_fil_struct *fil, int i, int j, int r, char **board)
// {
// 	int left = j - r;
// 	int top = i - r;
// 	int right = r + j;
// 	int bottom = r + i;

// 	int k = 0;
// 	while (left + k <= right)
// 	{
// 		if ()
// 		k++;
// 	}

// }

// void	find_closest_enemy_point(t_fil_struct *fil)
// {
// 	t_coords_node *coords;
// 	int radius;

// 	radius = 1;
// 	if (fil->valid_coords)
// 	{
// 		while (radius < fil->b_x - fil->p_x || radius < fil->b_y - fil->p_y)
// 		{
// 			coords = fil->valid_coords;
// 			while (coords)
// 			{
// 				if (check_enemy_by_coords(fil, coords->x, coords->y, radius, fil->board))
// 				{
// 					return ;
// 				}
// 				coords = coords->next;
// 			}
// 			radius++;					 
// 		}
// 	}
// }

int		main(void)
{
	t_fil_struct	fil;

	null_fil_struct(&fil);
	get_fil_player_char(&fil);
	while (1)
	{
		if (!(fill_out_fil_struct(&fil)))
			return (0);
		if (!(get_piece_coordintaes(&fil, fil.p_x, fil.p_y)))
			return (0);
		if (!(get_valid_placing_coordinates(&fil)))
			return (0);
		ft_printf("MY - %c\n", fil.c_my);
		ft_printf("ENEMY - %c\n", fil.c_enemy);
		ft_printf("VALID_COORDS\n");
		fil_print_coords_list(fil.valid_coords);
		ft_printf("PIECE_COORDS\n");
		fil_print_coords_list(fil.p_coords);
		// if (fil.valid_coords)
		// 	ft_printf("%d %d\n", fil.valid_coords->x, fil.valid_coords->y);
		// else
		// {
		// 	ft_printf("0 0\n");
		// 	delete_fil_struct(&fil);
		// 	return (0);
		// }
		delete_fil_struct(&fil);
	}
	//system ("leaks --quiet mmatiush.filler");
	return (0);
}
