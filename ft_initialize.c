/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:24:18 by lprior            #+#    #+#             */
/*   Updated: 2018/03/24 18:44:37 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_links    *ft_init_links(void)
{
    t_links *links;

    links = (t_links *)malloc(sizeof(t_links));
    links->x = -1;
    links->y = -1;
    links->altitude = -1;
    links->tru_x = -1;
    links->tru_y = -1;
	links->next = NULL;
    return (links);
}

t_tools     *ft_init_tools(void)
{
    t_tools *tools;
    
    if(!(tools = (t_tools *)malloc(sizeof(t_tools))))
        return (NULL);
    LINE = NULL;
	tools->i = 0;
    BAD = false;
    XVAL = -1;
    YVAL = 0;
    tools->prev_x = 0;
    tools->prev_y = 0;
    tools->altitude = NULL;
    FD = 0;
    return (tools);
}

t_rotation *ft_init_rot(void)
{
    t_rotation *rot;
    
    rot = (t_rotation *)malloc(sizeof(t_rotation));
    rot->degree_x = 0.0;
    rot->radian_x = 0.0;
    rot->degree_y = 0.0;
    rot->radian_y = 0.0;
    rot->degree_z = 0.0;
    rot->radian_z = 0.0;
    rot->x0 = 0.0;
    rot->x1 = 0.0;
    rot->x2 = 0.0;
    rot->y0 = 0.0;
    rot->y1 = 0.0;
    rot->y2 = 0.0;
    rot->z0 = 0.0;
    rot->z1 = 0.0;
    return (rot);    
}

t_env *ft_init(void)
{
    t_env *e;

    e = (t_env *)malloc(sizeof(t_env));
    e->tools = ft_init_tools();
    e->links = ft_init_links();
    e->rot = ft_init_rot();
    e->theda_x = 0;
    e->theda_y = 0;
    e->y_max = 0;
    e->x_max = 0;
    return (e);
}
