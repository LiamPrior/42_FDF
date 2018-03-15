/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:56:05 by lprior            #+#    #+#             */
/*   Updated: 2018/03/14 21:05:49 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_plc	*do_find_points(t_cam *cam, t_plc *current)
// {
// 	t_plc *header;
// 	t_plc *last;

// 	header = current;
// 	while (header->next != NULL)
// 	{
// 		header = find_points(cam, header);
// 		last = header;
// 		header = header->next;
// 		header->last = last;
// 	}
// 	header = find_points(cam, header);
// 	return (current);
// }

// t_plc	*find_points(t_cam *cam, t_plc *current)
// {
// 	t_rot	*alg;
// 	t_plc	*cur;

// 	cur = current;
// 	alg = (t_rot *)malloc(sizeof(t_rot));
// 	alg->x0 = cur->x;
// 	alg->y0 = (cur->y * cos(cam->angle_x)) + (cur->z * sin(cam->angle_x));
// 	alg->z0 = (cur->z * cos(cam->angle_x)) - (cur->y * sin(cam->angle_x));
// 	alg->x1 = (alg->x0 * cos(cam->angle_y)) - (alg->z0 * sin(cam->angle_y));
// 	alg->y1 = alg->y0;
// 	alg->z1 = (alg->z0 * cos(cam->angle_y)) + (alg->x0 * sin(cam->angle_y));
// 	alg->x2 = (alg->x1 * cos(cam->angle_z)) + (alg->y1 * sin(cam->angle_z));
// 	alg->y2 = (alg->y1 * cos(cam->angle_z)) - (alg->x1 * sin(cam->angle_z));
// 	alg->x2 *= 10;
// 	alg->y2 *= 10;
// 	alg->x2 += 150;
// 	alg->y2 += 150;
// 	cur->x_place = (int)alg->x2;
// 	cur->y_place = (int)alg->y2;
// 	free(alg);
// 	return (cur);

t_links     *ft_lets_get_started(t_links *links, t_pov *pov)
{
    t_links *head;

    head = links;
    while ()


}