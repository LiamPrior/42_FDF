/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:03:23 by lprior            #+#    #+#             */
/*   Updated: 2018/03/20 19:17:17 by lprior           ###   ########.fr       */
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
