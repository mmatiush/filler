#include "libft.h"
#include "filler.h"

// void	place_index(t_fil_struct *fil, char **board, int i, int j, char index)
// {
// 	if (j >= 1 && board[i][j - 1] == '.')
// 		board[i][j - 1] = index;
// 	if (j >= 1 && i >= 1 && board[i - 1][j - 1] == '.')
// 		board[i - 1][j - 1] = index;
// 	if (i >= 1 && board[i - 1][j] == '.')
// 		board[i - 1][j] = index;
// 	if (i >= 1 && j < fil->b_x - 1 && board[i - 1][j + 1] == '.')
// 		board[i - 1][j + 1] = index;
// 	if (j < fil->b_x - 1 && board[i][j + 1] == '.')
// 		board[i][j + 1] = index;
// 	if (i < fil->b_y - 1 && j < fil->b_x - 1 && board[i + 1][j + 1] == '.')
// 		board[i + 1][j + 1] = index;
// 	if (i < fil->b_y - 1 && board[i + 1][j] == '.')
// 		board[i + 1][j] = index;
// 	if (j >= 1 && i < fil->b_y - 1 && board[i + 1][j - 1] == '.')
// 		board[i + 1][j - 1] = index;
// }

// int		check_board_dots(t_fil_struct *fil)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < fil->b_y)
// 	{
// 		j = 0;
// 		while (j < fil->b_x)
// 		{
// 			if (fil->board[i][j] == '.')
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// void		check_idex(t_fil_struct *fil, int i, int j, int index)
// {
// 	int falg;

// 	flag = 0;
// 	if (index == 'O' || index == 'o' || index == 'X' || index == 'x' || index == '.')
// 	{
// 		flag = 1;
// 		index++;
// 	}
// 	if (flag == 1 && fil->board[i][j] == index - 2)
// 		place_index(fil, fil->board, i, j, index);
// 	else if (flag == 0 && fil->board[i][j] == index - 1)
// 		place_index(fil, fil->board, i, j, index);
// 	else if (fil->board[i][j] == fil->c_enemy || fil->board[i][j] == fil->c_enemy + 32)
// 		place_index(fil, fil->board, i, j, index);
// }

// void	search_closest_valid_point(t_fil_struct *fil)
// {
// 	int i;
// 	int j;
// 	int index;

// 	index = 0;
// 	while (check_board_dots(fil) && index <= 255)
// 	{
// 		print_board(fil);
// 		i = 0;
// 		while (i < fil->b_y)
// 		{
// 			j = 0;
// 			while (j < fil->b_x)
// 			{
// 				check_idex(fil, i, j, index);
// 				j++;
// 			}
// 			i++;
// 		}
// 		index++;
// 	}
// }

int		main(void)
{
	t_fil_struct	fil;
	int i = 0;
	char c = 0;
	while (i <= 256)
	{
		ft_printf("%d [%d]\n", i++, c++);
	}
	null_fil_struct(&fil);
	get_fil_player_char(&fil);
	while (1)
	{
		if (!(fill_out_fil_struct(&fil)))
			return (0);
		if (!(get_piece_coordintaes(&fil, fil.p_x, fil.p_y)))
			return (0);
		// print_coords_list(fil.p_coords);
		move_piece_coords_left_up(&fil);
		// print_coords_list(fil.p_coords);
		if (!(get_valid_placing_coordinates(&fil)))
			return (0);
		print_board(&fil);
		print_int_board(&fil);
		// search_closest_valid_point(&fil);
		// if (fil.valid_coords)
		// 	ft_printf("%d %d\n", fil.valid_coords->y - fil.p_y_shift, fil.valid_coords->x - fil.p_x_shift);
		// else
		// {
		// 	ft_printf("0 0\n");
		// 	delete_fil_struct(&fil);
		// 	return (0);
		delete_fil_struct(&fil);
	}
	//system ("leaks --quiet mmatiush.filler");
	return (0);
}
