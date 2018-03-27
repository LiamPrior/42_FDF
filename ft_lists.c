/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:08:18 by lprior            #+#    #+#             */
/*   Updated: 2018/03/26 14:41:18 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_add_link(t_links *fresh, t_tools *tools)
{
    while (fresh->next != NULL)
        fresh = fresh->next;
    if (!(fresh->next = ft_create_link(tools)))
        return (-1);
    return (1);
}