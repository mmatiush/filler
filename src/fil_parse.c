#include "libft.h"
#include "filler.h"

/*
** Read the first line from STDIN and parse board or piece dimensions.
** Skip all not integers, then parse first number using ft_atoi,
** then move the pointer to the end of the parsed aread and run ft_atoi
** once again to parse the second number.
*/

static void	get_fil_object_size(int *x, int *y)
{
	char	*buff;
	char	*buff_ptr;

	get_next_line(STDIN_FILENO, &buff);
	buff_ptr = buff;
	while (!ft_isdigit(*buff))
		buff++;
	*y = ft_atoi(buff);
	while (ft_isdigit(*buff))
		buff++;
	*x = ft_atoi(buff);
	free(buff_ptr);
}


/*
** Parse and drop the line with coloumn numbers.
** Then start parsing the board. The whle loop will break when GNL reaches
** a non numeric value, which will mean that we got to Piece dimensions.
*/

static void	init_fil_board(t_fil_node	*fil)
{
	char	*buff;
	int		i;

	i = 0;
	fil->board = (char**)malloc(sizeof(char*) * (fil->b_y + 1));
	get_next_line(STDIN_FILENO, &buff);
	free(buff);
	while (i < fil->b_y)
	{
		get_next_line(STDIN_FILENO, &buff);
		fil->board[i++] = ft_strdup(buff + 4);
		free(buff);
	}
	fil->board[i] = NULL;
}

static void	init_fil_piece(t_fil_node *fil)
{
	char	*buff;
	int		i;

	i = 0;
	fil->piece = (char**)malloc(sizeof(char*) * (fil->p_y + 1));
	while (i < fil->p_y)
	{
		get_next_line(STDIN_FILENO, &buff);
		fil->piece[i++] = ft_strdup(buff);
		free(buff);
	}
	fil->piece[i] = NULL;
}

void	fill_out_fil(t_fil_node	*fil)
{
	get_fil_object_size(&fil->b_x, &fil->b_y);
	init_fil_board(fil);
	get_fil_object_size(&fil->p_x, &fil->p_y);
	init_fil_piece(fil);
}

/*
** Get a character for each player;
*/

void	get_fil_player_char(t_fil_node	*fil)
{
	char	*buff;
	
	get_next_line(STDIN_FILENO, &buff);
	fil->c_my = (buff[10] == '1') ? 'O' : 'X';
	fil->c_enemy = (fil->c_my == 'X') ? 'O' : 'X';
	free(buff);
}
