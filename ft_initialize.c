/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:24:18 by lprior            #+#    #+#             */
/*   Updated: 2018/03/06 16:45:59 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_init_tools(t_links *links, t_tools *tools)
{
    lft_init_links(links);
    ft_init_tools(tools);
}

void    ft_init_links(t_links *links)
{
    links = (t_links *)malloc(sizeof(t_links));
	links->prev = NULL;
	links->next = NULL;
}

void    ft_init_tools(t_tools *tools)
{
    tools = (t_tools *)malloc(sizeof(t_tools));
    tools->line = NULL;
    tools->fd = 0;
    return (tools);
}

