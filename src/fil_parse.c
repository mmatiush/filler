#include "libft.h"
#include "filler.h"

/*
** Read the first line from STDIN and parse board or piece dimensionsint.
** Skip all not integers, then parse first number using ft_atoi,
** then move the pointer to the end of the parsed aread and run ft_atoi
** once again to parse the second number.
*/

static void	get_fil_object_size(int *x, int *y)
{
	char	*buff;
	char	*buff_ptr;

	buff = NULL;
	get_next_line(STDIN_FILENO, &buff);
	buff_ptr = buff;
	if (buff_ptr)
	{
		while (!ft_isdigit(*buff))
			buff++;
		*y = ft_atoi(buff);
		while (ft_isdigit(*buff))
			buff++;
		*x = ft_atoi(buff);
		free(buff_ptr);
	}
}


/*
** Parse and drop the line with coloumn numbers.
** Then start parsing the board. The whle loop will break when GNL reaches
** a non numeric value, which will mean that we got to Piece dimensions.
*/

static int	init_fil_board(t_fil_struct *fil)
{
	char	*buff;
	int		i;

	buff = NULL;
	i = 0;
	if (!(fil->board = (char**)malloc(sizeof(char*) * (fil->b_y + 1))))
		return (0);
	get_next_line(STDIN_FILENO, &buff);
	if (buff)
	{
		free(buff);
	}
	while (i < fil->b_y)
	{
		get_next_line(STDIN_FILENO, &buff);
		if (buff)
		{
			if (!(fil->board[i++] = ft_strdup(buff + 4)))
				return (0);
			free(buff);
		}
	}
	fil->board[i] = NULL;
	return (1);

}

static int	init_fil_piece(t_fil_struct *fil)
{
	char	*buff;
	int		i;

	buff = NULL;
	i = 0;
	if (!(fil->piece = (char**)malloc(sizeof(char*) * (fil->p_y + 1))))
		return (0);
	while (i < fil->p_y)
	{
		get_next_line(STDIN_FILENO, &buff);
		if (buff)
		{
			if (!(fil->piece[i++] = ft_strdup(buff)))
				return (0);
			free(buff);
		}
	}
	fil->piece[i] = NULL;
	return (1);
}

int			fill_out_fil_struct(t_fil_struct *fil)
{
	get_fil_object_size(&fil->b_x, &fil->b_y);
	if (!(init_fil_board(fil)))
		return (0);
	get_fil_object_size(&fil->p_x, &fil->p_y);
	if (!(init_fil_piece(fil)))
		return (0);
	return (1);
}
