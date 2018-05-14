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

typedef struct				s_coords_node
{
	int						x;
	int						y;
	struct	s_coords_node	*next;
}							t_coords_node;

typedef struct		s_fil_struct
{
	char 			c_my;
	char			c_enemy;
	char			**board;
	int				b_x;
	int				b_y;
	char			**piece;
	int 			p_x;
	int				p_y;
	t_coords_node	*p_coords;
	t_coords_node	*valid_coords;
}					t_fil_struct;

/*
** Parsing and writing board and piece to the struct.
*/

void	get_fil_player_char(t_fil_struct *fil);
int		fill_out_fil_struct(t_fil_struct *fil);

/*
** Checking all valid possible coordinates for return. 
*/

int		get_piece_coordintaes(t_fil_struct *fil, int x, int y);

/*
** Additional functions
*/

void	fil_print_board(t_fil_struct *fil);
void	fil_print_piece(t_fil_struct *fil);
void	fil_print_coords_list(t_coords_node *coords);
void	delete_coords_struct(t_coords_node **coords);
void	delete_fil_struct(t_fil_struct *fil);

#endif
