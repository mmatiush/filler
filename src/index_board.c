/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:43:48 by mmatiush          #+#    #+#             */
/*   Updated: 2018/05/24 14:43:49 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int			place_index(t_fil_struct *fil, int i, int j, char index)
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

static int	check_board_dots(t_fil_struct *fil)
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


static void	prepare_board(t_fil_struct *fil)
{
	int i;
	int j;

	i = 0;
	while(i < fil->b_y)
	{
		j = 0;
		while (j < fil->b_x)
		{
			if (fil->board[i][j] ==  '.' || fil->board[i][j] == fil->c_my || fil->board[i][j] == fil->c_my + 32)
				fil->board[i][j] = 0;
			else if (fil->board[i][j] == fil->c_enemy || fil->board[i][j] == fil->c_enemy + 32)
				fil->board[i][j] = 1;
			j++;
		}
		i++;
	}
}

/*
** Index starts from 1 as 0, 1 are already on the board
** representing '.' and c_enemy (see preapare_broard() func).
*/

void	index_board(t_fil_struct *fil)
{
	int i;
	int j;
	int index;
	int flag;

	prepare_board(fil);
	index = 1;
	while (check_board_dots(fil) && ++index <= CHAR_MAX)
	{
		i = -1;
		flag = 0;
		while (++i < fil->b_y)
		{
			j = -1;
			while (++j < fil->b_x)
			{
				if (fil->board[i][j] == fil->c_enemy_updated ||\
					fil->board[i][j] == index - 1)
					flag += place_index(fil, i, j, index);
			}
		}
		if (flag == 0)
			break ;
	}
}
