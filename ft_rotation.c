/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:56:05 by lprior            #+#    #+#             */
/*   Updated: 2018/03/22 22:50:09 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
// }



//okay bud im leaking in here!!!!!!!!!!!
t_links     *ft_lets_get_started(t_links *head, t_rotation *rot, t_env *all)
{
    t_links *links;

    links = head;
    while (links)//->next != NULL)
    {
        rot->x0  =  (double)links->x - 1;
        // printf("here = %f\n", rot->x0);
        rot->y0  =  ((links->y - 1) * cos(rot->radian_x)) + (links->altitude * sin(rot->radian_x));
        rot->z0  =  (links->altitude * cos(rot->radian_x)) - (links->y * sin(rot->radian_x));

        rot->x1  =  (rot->x0 * cos(rot->radian_y)) - (rot->z0 * sin(rot->radian_y));
        rot->y1  =  rot->y0;
        rot->z1  =  (rot->z0 * cos(rot->radian_y)) + (rot->x0 * sin(rot->radian_y));

        rot->x2  =  (rot->x1 * cos(rot->radian_z)) + (rot->y1 * sin(rot->radian_z));
        rot->y2  =  (rot->y1 * cos(rot->radian_z)) - (rot->x1 * sin(rot->radian_z));

        rot->x2 *= 10;// (WIDTH - 200) / all->x_max;
        rot->y2 *= 10;// (HEIGHT - 200) / all->y_max;
        // printf("x = %f y = %f\n", rot->x2, rot->y2);
        rot->x2 += 150;
        rot->y2 += 150;
        // printf("x2 = %f y2 = %f\n", rot->x2, rot->y2);
        links->tru_y = rot->y2;
        links->tru_x = rot->x2;
        // printf("tru_x = %f tru_y = %f\n", links->tru_x, links->tru_y);
        links = links->next;
    }
    return (head);
}
