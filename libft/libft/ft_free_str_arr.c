/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:14:31 by mmatiush          #+#    #+#             */
/*   Updated: 2018/05/10 18:14:33 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_str_arr(char ***str)
{
	int	i;

	i = 0;
	if (!*str)
		return ;
	while ((*str)[i])
	{
		free((*str)[i]);
		(*str)[i++] = NULL;
	}
	free(*str);
	*str = NULL;
}
