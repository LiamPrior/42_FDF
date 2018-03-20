/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:36:36 by lprior            #+#    #+#             */
/*   Updated: 2018/03/19 18:00:48 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_plc	*find_struct(t_plc *head, int x_cord, int y_cord)
// {
// 	t_plc *new;

// 	new = head;
// 	if (!(x_cord >= 0 || y_cord >= 0))
// 		return (NULL);
// 	while (new->next)
// 	{
// 		if (new->x == x_cord && new->y == y_cord)
// 			return (new);
// 		new = new->next;
// 	}
// 	return (NULL);
// }

void    ft_find_struct(t_links *temp, t_links *links)
{

}

void    ft_draw(t_links *links, t_tools *tools)
{
    int da;
    t_links *temp;
    // i dont techniqly needd to mkae a function to check the da. I can just find it here.
    // open my mlx window here i guess.
    
    tempft_find_struct(temp, links);
    links->tru_x > links->tru_y ? ft_driving_x : ft_driving_y;
    tools->prev_x = links->tru_x;
    tools->prev_y = links->tru_y;
}