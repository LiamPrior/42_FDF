/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:03:23 by lprior            #+#    #+#             */
/*   Updated: 2018/03/22 18:26:11 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_links     *create_link(t_tools *tools)
{
    t_links *new;

    if (!(new = (t_links *)malloc(sizeof(t_links))))// remembere star
        return (NULL);
    new->x = XVAL;
    new->y = YVAL;
    new->altitude = ft_atoi(LINE);
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
// t_plc	*find_struct(t_plc *head, int x_cord, int y_cord)
// {
// 	t_plc *new;

// 	new = head;
// 	if (!(x_cord >= 0 || y_cord >= 0))
// 		return (NULL);
// 	while (new->next)
// 	{
		// if (new->x == x_cord && new->y == y_cord)
		// 	return (new);
		// new = new->next;
// 	}
// 	return (NULL);
// }

t_links *ft_find_terminal(t_env *all)
{
    t_links *new;
    t_links *down;

    new = all->links;
    // down = all->links;
    // if (all->links->x < 0 || all->links->y + 1 < 0)
    //     return (NULL);
    // printf("new x = %d new y = %d links x = %d links y + 1 = %d\n", new->x, new->y, all->links->x, all->links->y + 1);
    while (new)
    {
        // printf("new x = %d new y = %d links x = %d links y + 1 = %d\n", new->x, new->y, all->links->x, all->links->y + 1);
        if (new->x == all->links->x && new->y == all->links->y + 1)
			return (new);
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
    // printf("initial x = %d initial y = %d itru_x = %f itru_y = %f\n", initial->x, initial->y, initial->tru_x, initial->tru_y);
    // printf("terminal x = %d terminal y = %d ttru_x = %f ttru_y = %f\n", terminal->x, terminal->y, terminal->tru_x, terminal->tru_y);
    while (initial->next)
    {
        if (terminal->next != NULL && (terminal->next->x > terminal->x))//this means it hasnt hit the end of the line yet so its draws down;
            ft_draw(initial, terminal, all);
        if (initial->next && (initial->next->x > initial->x))//draws the line to the right!
            ft_draw(initial, initial->next, all);
        if (initial->next->x < initial->x && terminal->next != NULL)//the next link is less then the current one and down to next doesnt equal null keep going.
            ft_draw(initial, terminal, all);
        if (initial->next)
            initial = initial->next;
        if (terminal->next)
            terminal = terminal->next;
    }
}





// t_plc	*find_struct(t_plc *head, int x_cord, int y_cord)
// {
// 	t_plc *new;

// 	new = head;
// 	if (!(x_cord >= 0 || y_cord >= 0))
// 		return (NULL);
// 	while (new->next)
// 	{
		// if (new->x == x_cord && new->y == y_cord)
		// 	return (new);
		// new = new->next;
// 	}
// 	return (NULL);
// }

// int		draw(t_all *all)
// {
// 	t_plc	*a;
// 	t_plc	*down;
// 	int		x[1];
// 	int		y[1];
// 	a = all->head;
// 	down = find_struct(a, a->x, a->y + 1);
// 	while (a->next)
// 	{
// 		if (down->next != NULL && (down->next->x > down->x))
// 			coord_calc(a, down, all->mlx);
// 		if (a->next && (a->next->x > a->x))//if its at the end/.
// 			coord_calc(a, a->next, all->mlx);
// 		if (a->next->x < a->x && down->next != NULL)if the next link is less then the current one and down to next doesnt equal null keep going.
// 			coord_calc(a, down, all->mlx);
// 		if (a->next != NULL)
// 			a = a->next;
// 		if (down->next != NULL)
// 			down = down->next;
// 	}
// 	return (0);
// }