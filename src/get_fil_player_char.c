/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fil_player_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:43:41 by mmatiush          #+#    #+#             */
/*   Updated: 2018/05/24 14:43:42 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	update_enemy_char_for_indexing(t_fil_struct *fil)
{
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
	update_enemy_char_for_indexing(fil);
}
