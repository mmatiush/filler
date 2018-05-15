#include "libft.h"
#include "filler.h"

void	fil_put_index(t_fil_node *fil, char **board, int i, int j, char index)
{
	if (j >= 1 && board[i][j - 1] == '.')
		board[i][j - 1] = index;
	if (j >= 1 && i >= 1 && board[i - 1][j - 1] == '.')
		board[i - 1][j - 1] = index;
	if (i >= 1 && board[i - 1][j] == '.')
		board[i - 1][j] = index;
	if (i >= 1 && j < fil->b_x - 1 && board[i - 1][j + 1] == '.')
		board[i - 1][j + 1] = index;
	if (j < fil->b_x - 1 && board[i][j + 1] == '.')
		board[i][j + 1] = index;
	if (i < fil->b_y - 1 && j < fil->b_x - 1 && board[i + 1][j + 1] == '.')
		board[i + 1][j + 1] = index;
	if (i < fil->b_y - 1 && board[i + 1][j] == '.')
		board[i + 1][j] = index;
	if (j >= 1 && i < fil->b_y - 1 && board[i + 1][j - 1] == '.')
		board[i + 1][j - 1] = index;	
}

void	fil_index_board(t_fil_node	*fil)
{
	int i;
	int j;
	int index;

	index = 1;
	while (check_board_dots(fil))
	{
		fil_print_board(fil);
		i = 0;
		while (i < fil->b_y)
		{
			j = 0;
			while (j < fil->b_x)
			{
				if (fil->board[i][j] == fil->c_enemy || fil->board[i][j] == index + '0' - 1)
					fil_put_index(fil, fil->board, i, j, index + '0');
				//ft_printf("[ j - %d ]\n", j);
				j++;
			}
		//	ft_printf("[ i - %d ]\n", i);
			i++;
		}
		index++;
	}
}

int		check_board_dots(t_fil_node	*fil)
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

int		main(void)
{
	t_fil_node	fil;
	get_fil_player_char(&fil);
	fill_out_fil(&fil);

	fil_index_board(&fil);
	fil_print_board(&fil);
	//fil_print_piece(&fil);
	// ft_printf("c_my = %c\n", fil.c_my);
	// ft_printf("b_x =  %d\n", fil.b_x);
	// ft_printf("b_y =  %d\n", fil.b_y);
	// ft_printf("p_x =  %d\n", fil.p_x);
	// ft_printf("p_y =  %d\n", fil.p_y);
	// system ("leaks --quiet mmatiush.filler");
	return (0);
}
