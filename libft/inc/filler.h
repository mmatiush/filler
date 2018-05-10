/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:55:44 by mmatiush          #+#    #+#             */
/*   Updated: 2018/05/01 18:50:50 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*
**	List with coordinates of the piece
*/

typedef struct			s_coords
{
	int					x;
	int					y;
	struct	s_coords	*next;
}						t_coords;

typedef struct	s_fil_node
{
	char 		c_my;
	char		c_enemy;
	char		**board;
	int			b_x;
	int			b_y;
	char		**piece;
	int 		p_x;
	int			p_y;
	t_coords	*coords;
}				t_fil_node;


void	get_fil_player_char(t_fil_node	*fil);
void	fill_out_fil(t_fil_node	*fil);

/*
** Additional functions
*/

void	fil_print_board(t_fil_node	*fil);
void	fil_print_piece(t_fil_node	*fil);

#endif
