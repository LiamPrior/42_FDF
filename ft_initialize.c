/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:24:18 by lprior            #+#    #+#             */
/*   Updated: 2018/03/12 19:55:35 by lprior           ###   ########.fr       */
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
    X = -1;
    Y = -1;
    tools->ordinate = NULL;
    FD = 0;
    return (tools);
}

void tools_to_list(t_tools *tools, t_links *fresh)
{
    fresh->x = X;
    fresh->y = Y;
    fresh->ordinate = ft_atoi(LINE);
}
