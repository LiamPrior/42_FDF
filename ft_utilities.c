/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:03:23 by lprior            #+#    #+#             */
/*   Updated: 2018/03/24 20:03:33 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_links     *ft_create_link(t_tools *tools)
{
    t_links *new;
    if (!(new = (t_links *)malloc(sizeof(t_links))))// remembere star
        return (NULL);
    new->x = XVAL;
    new->y = YVAL;
    new->altitude = ft_atoi(&(LINE[tools->i]));
    new->next = NULL;
    return (new);
}

t_rotation	*ft_calc_radian(t_rotation *degrees)
{
	t_rotation *pov;

	pov = degrees;
	pov->radian_x = pov->degree_x * (PI / 180);
	pov->radian_y = pov->degree_y * (PI / 180);
	pov->radian_z = pov->degree_z * (PI / 180);
	return (pov);
}

t_links *ft_find_terminal(t_env *all)
{
    t_links *new;
    t_links *down;

    new = all->links;
    while (new)
    {
        if (new->x == all->links->x && new->y == all->links->y + 1)
            return (new);
        else
		    new = new->next;
    }
    return (NULL);
}

void    ft_directions(t_env *all)
{
    t_links *initial;
    t_links *terminal;

    initial = all->links;
    terminal = ft_find_terminal(all);
    while (initial->next)
    {
        if (terminal->next != NULL && (terminal->next->x > terminal->x))
            ft_draw(initial, terminal, all);
        if (initial->next->x < initial->x && terminal->next != NULL)
            ft_draw(initial, terminal, all);
        if (initial->next && (initial->next->x > initial->x))
            ft_draw(initial, initial->next, all);
        if (initial && terminal && terminal->next == NULL)
            ft_draw(initial, terminal, all);
        if (initial->next)
            initial = initial->next;
        if (terminal->next)
            terminal = terminal->next;
    }
}