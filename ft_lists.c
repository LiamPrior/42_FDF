/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:08:18 by lprior            #+#    #+#             */
/*   Updated: 2018/03/13 16:40:19 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_add_link(t_links *fresh, t_tools *tools)
{
    int i = 0;
    // printf("%d\n", fresh->x);
    while (fresh->next != NULL)//go to end of list!
    {
        fresh = fresh->next;
        i++;
        // printf("\n\n\n\nthis is i = %d\n\n\n\n ", i);
    }
    if (!(fresh->next = create_link(tools)))//if it doesnt malloc return -1;
        return (-1);
    return (1);
}
