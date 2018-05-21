#include "libft.h"
#include "filler.h"

int		place_index(t_fil_struct *fil, int i, int j, char index)
{
	int flag;

	flag = 0;
	if (j >= 1 && fil->board[i][j - 1] == 0 && (flag = 1))
		fil->board[i][j - 1] = index;
	if (j >= 1 && i >= 1 && fil->board[i - 1][j - 1] == 0 && (flag = 1))
		fil->board[i - 1][j - 1] = index;
	if (i >= 1 && fil->board[i - 1][j] == 0 && (flag = 1))
		fil->board[i - 1][j] = index;
	if (i >= 1 && j < fil->b_x - 1 && fil->board[i - 1][j + 1] == 0 && (flag = 1))
		fil->board[i - 1][j + 1] = index;
	if (j < fil->b_x - 1 && fil->board[i][j + 1] == 0 && (flag = 1))
		fil->board[i][j + 1] = index;
	if (i < fil->b_y - 1 && j < fil->b_x - 1 &&	fil->board[i + 1][j + 1] == 0 && (flag = 1))
		fil->board[i + 1][j + 1] = index;
	if (i < fil->b_y - 1 && fil->board[i + 1][j] == 0 && (flag = 1))
		fil->board[i + 1][j] = index;
	if (j >= 1 && i < fil->b_y - 1 && fil->board[i + 1][j - 1] == 0 && (flag = 1))
		fil->board[i + 1][j - 1] = index;
	return (flag);
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
			if (fil->board[i][j] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Index starts from 4 as 0, 1, 2 are already on the board
** representing 'X', 'O', '.' (see "preapare_broard" func).
*/

void	index_board(t_fil_struct *fil)
{
	int i;
	int j;
	int index;
	int flag;

	index = 4;
	while (check_board_dots(fil) && index <= CHAR_MAX)
	{
		i = 0;
		flag = 0;
		while (i < fil->b_y)
		{
			j = 0;
			while (j < fil->b_x)
			{
				if (fil->board[i][j] == fil->c_enemy || fil->board[i][j] == index - 1)
					flag += place_index(fil, i, j, index);
				j++;
			}
			i++;
		}
		if (flag == 0)
			break ;
		index++;
	}
}

/*
** On the board, substitute all '.' with 0, all 'x' and 'X' with 1, and
** 'o'and 'O' with 2, to prepare it for placing indexes on the board.
** c_my and c_enemy char in fil structure are replaced respectively.
*/

void	edit_enemy_and_my_char(t_fil_struct *fil)
{
	fil->c_my = (fil->c_my == 'X') ? 1 : 2;
	fil->c_enemy = (fil->c_enemy == 'X') ? 1 : 2;

}

void	prepare_board(t_fil_struct *fil)
{
	int i;
	int j;

	i = 0;
	while(i < fil->b_y)
	{
		j = 0;
		while (j < fil->b_x)
		{
			if (fil->board[i][j] ==  '.')
				fil->board[i][j] = 0;
			else if (fil->board[i][j] == 'x' || fil->board[i][j] == 'X')
				fil->board[i][j] = 1;
			else if (fil->board[i][j] == 'o' || fil->board[i][j] == 'O')
				fil->board[i][j] = 2;
			j++;
		}
		i++;
	}
	edit_enemy_and_my_char(fil);
}

void	get_closest_valid_point(t_fil_struct *fil)
{
	char			distance;
	t_coords_node	*valid_coords;

	if (fil->valid_coords == NULL)
		return ;
	valid_coords = fil->valid_coords;
	fil->result.y = valid_coords->y;
	fil->result.x = valid_coords->x;
	distance = fil->board[valid_coords->y][valid_coords->x];
	while ((valid_coords = valid_coords->next))
	{
		if (fil->board[valid_coords->y][valid_coords->x] < distance)
		{
			fil->result.y = valid_coords->y;
			fil->result.x = valid_coords->x;
			distance = fil->board[valid_coords->y][valid_coords->x];
		}
	}
}

int		main(void)
{
	t_fil_struct fil;
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
		print_coords_list(fil.p_coords);
		if (!(get_valid_placing_coordinates(&fil)))
			return (0);
		print_coords_list(fil.valid_coords);
		// print_board(&fil);
		// ft_printf("c_my [%c] ", fil.c_my);
		// ft_printf("c_ enemy [%c]\n", fil.c_enemy);
		prepare_board(&fil);
		// ft_printf("c_my [%i] ", fil.c_my);
		// ft_printf("c_ enemy [%i]\n", fil.c_enemy);
		print_int_board(&fil);
		index_board(&fil);
		print_int_board(&fil);
		// print_int_board(&fil);
		get_closest_valid_point(&fil);
		if (fil.valid_coords)
			ft_printf("%d %d\n", fil.result.y - fil.p_y_shift, fil.result.x - fil.p_x_shift);
		else
		{
			ft_printf("0 0\n");
			delete_fil_struct(&fil);
			return (0);
		}
		delete_fil_struct(&fil);
		//system ("leaks --quiet mmatiush.filler");
	}
	return (0);
}
