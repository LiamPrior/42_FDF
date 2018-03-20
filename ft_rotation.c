/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:56:05 by lprior            #+#    #+#             */
/*   Updated: 2018/03/20 13:08:54 by lprior           ###   ########.fr       */
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

t_links     *ft_lets_get_started(t_links *head, t_rotation *rot, t_env *all)
{
    t_links *links;

    // rot = (t_rotation *)malloc(sizeof(t_rotation));
    links = head;
    while (links)
    {
        //x axis roation
        // printf("HERE\n");
        rot->x0  =  links->x;
        rot->y0  =  (links->y * cos(rot->radian_x)) + (links->ordinate * sin(rot->radian_x));
        rot->z0  =  (links->ordinate * cos(rot->radian_x)) - (links->y * sin(rot->radian_x));
        //y axis rotation
        rot->x1  =  (rot->x0 * cos(rot->radian_y)) - (rot->z0 * sin(rot->radian_y));
        rot->y1  =  rot->y0;
        rot->z1  =  (rot->z0 * cos(rot->radian_y)) + (rot->x0 * sin(rot->radian_y));
        //apply x1 and y1 to x2 y2
        rot->x2  =  (rot->x1 * cos(rot->radian_z)) + (rot->y1 * sin(rot->radian_z));
        rot->y2  =  (rot->y1 * cos(rot->radian_z)) - (rot->x1 * sin(rot->radian_z));
        //scaling
        printf("here = [%f] [%f]\n", all->x_max, all->y_max);
        rot->x2 *= (WIDTH - 200) / all->x_max;
        rot->y2 *= (HEIGHT - 200) / all->y_max;
        rot->x2 += 100;
        rot->y2 += 100;
        //the endpoint where the pixle location is deffined
        links->tru_y = (int)rot->y2;
        links->tru_x = (int)rot->x2;
        links = links->next;
    }
    return (head);
}