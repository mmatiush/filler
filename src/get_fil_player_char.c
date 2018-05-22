#include "libft.h"
#include "filler.h"

/*
** Substitute 'X' with 1, and 'O' with 2 and save them in updatesd variables.
** It will be used for placing indexes.
*/

// void	update_enemy_and_my_char(t_fil_struct *fil)
// {
// 	fil->c_my_updated = (fil->c_my == 'X') ? 1 : 2;
// 	fil->c_enemy_updated = (fil->c_enemy == 'X') ? 1 : 2;
// }

void	update_enemy_and_my_char(t_fil_struct *fil)
{
	fil->c_my_updated = 2;
	fil->c_enemy_updated = 1;
}

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
	update_enemy_and_my_char(fil);
}
