#include "libft.h"
#include "filler.h"

/*
** Get a character for each player;
*/

void		get_fil_player_char(t_fil_struct *fil)
{
	char	*buff;
	
	get_next_line(STDIN_FILENO, &buff);
	fil->c_my = (buff[10] == '1') ? 'O' : 'X';
	fil->c_enemy = (fil->c_my == 'X') ? 'O' : 'X';
	free(buff);
}
