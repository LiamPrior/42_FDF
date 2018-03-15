/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:03:23 by lprior            #+#    #+#             */
/*   Updated: 2018/03/14 19:48:52 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_pov	*ft_find_radian(t_pov *degrees)
{
	t_pov *pov;

	pov = degrees;
	pov->radian_x = pov->degree_x * (PI / 180);
	pov->radian_y = pov->degree_y * (PI / 180);
	pov->radian_z = pov->degree_z * (PI / 180);
	return (pov);
}
