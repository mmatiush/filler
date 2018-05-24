/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmatiush.filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:43:48 by mmatiush          #+#    #+#             */
/*   Updated: 2018/05/24 14:43:49 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

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
		if (fil->board[valid_coords->y][valid_coords->x] <= distance)
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
		move_piece_coords_left_up(&fil);
		if (!(get_valid_placing_coordinates(&fil)))
			return (0);
		index_board(&fil);
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
	}
	return (0);
}
