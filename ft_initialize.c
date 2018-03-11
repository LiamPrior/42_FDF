/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:24:18 by lprior            #+#    #+#             */
/*   Updated: 2018/03/10 17:00:53 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_init_structs(t_links *links, t_tools *tools)
{
    lft_init_links(links);
    ft_init_tools(tools);
}

void    ft_init_links(t_links *links)
{
    links = (t_links *)malloc(sizeof(t_links));
    links->x = 0;
    links->y = 0;
	links->prev = NULL;
	links->next = NULL;
}

void    ft_init_tools(t_tools *tools)
{
    tools = (t_tools *)malloc(sizeof(t_tools));
    tools->line = NULL;
    tools->x = 0;
    tools->y = 0;
    tools->fd = 0;
}

