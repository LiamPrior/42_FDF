/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:24:18 by lprior            #+#    #+#             */
/*   Updated: 2018/03/13 18:10:30 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_init_structs(t_tools *tools, t_links *links)
{
    links = ft_init_links();
    tools = ft_init_tools();
}

t_links    *ft_init_links()
{
    t_links *links;

    links = (t_links *)malloc(sizeof(t_links));
    links->x = -1;
    links->y = -1;
    links->ordinate = -1;
	links->next = NULL;
    return (links);
}

t_tools     *ft_init_tools()
{
    t_tools *tools;
    
    tools = (t_tools *)malloc(sizeof(t_tools));
    LINE = NULL;
    BAD = false;
    XVAL = -1;
    YVAL = -1;
    tools->ordinate = NULL;
    FD = 0;
    return (tools);
}

void tools_to_list(t_tools *tools, t_links *fresh)
{
    fresh->x = XVAL;
    fresh->y = YVAL;
    fresh->ordinate = ft_atoi(LINE);
}

t_links     *create_link(t_tools *tools)
{
    t_links *new;

    if (!(new = malloc(sizeof(t_links))))
        return (NULL);
    new->x = XVAL;
    new->y = YVAL;
    new->ordinate = ft_atoi(LINE);
    new->next = NULL;
    return (new);
}