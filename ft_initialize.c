/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:24:18 by lprior            #+#    #+#             */
/*   Updated: 2018/03/22 14:49:36 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_links    *ft_init_links(void)
{
    t_links *links;

    links = (t_links *)malloc(sizeof(t_links));
    links->x = -1;
    links->y = -1;
    links->altitude = -1;
    links->tru_x = -1;
    links->tru_y = -1;
	links->next = NULL;
    return (links);
}

t_tools     *ft_init_tools(void)
{
    t_tools *tools;
    
    if(!(tools = (t_tools *)malloc(sizeof(t_tools))))
        return (NULL);
    LINE = NULL;
    BAD = false;
    XVAL = -1;
    YVAL = 0;
    tools->prev_x = 0;
    tools->prev_y = 0;
    tools->altitude = NULL;
    FD = 0;
    return (tools);
}

// t_mlx   *ft_init_mlx(void)
// {
//     t_mlx *mlx;

//     if(!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
//         return (NULL);
//         // mlx = (t_mlx *)malloc(sizeof(t_mlx));
//     // mlx->mlx = mlx_init();
//     // mlx->win = mlx_new_window(mlx, WIDTH, HEIGHT, "Lprior FDF");
//     return (mlx);   
// }

t_rotation *ft_init_rot(void)
{
    t_rotation *rot;
    
    rot = (t_rotation *)malloc(sizeof(t_rotation));
    rot->degree_x = 0.0;
    rot->radian_x = 0.0;
    rot->degree_y = 0.0;
    rot->radian_y = 0.0;
    rot->degree_z = 0.0;
    rot->radian_z = 0.0;
    rot->x0 = 0.0;
    rot->x1 = 0.0;
    rot->x2 = 0.0;
    rot->y0 = 0.0;
    rot->y1 = 0.0;
    rot->y2 = 0.0;
    rot->z0 = 0.0;
    rot->z1 = 0.0;
    return (rot);    
}

t_env *ft_init(void)
{
    t_env *e;

    e = (t_env *)malloc(sizeof(t_env));
    e->tools = ft_init_tools();
    e->links = ft_init_links();
    e->rot = ft_init_rot();
    e->y_max = 0;
    e->x_max = 0;
    return (e);
}

// t_env *ft_init(void)
// {

//     // view->tools = ft_init_tools();
//     // view->links = ft_init_links();
//     // view->rot = ft_init_rot();
//     // view->y_max = 0;
//     // view->x_max = 0;
//     t_env *view;

// 	view = (t_env*)malloc(sizeof(t_env));
//     view->tools = ft_init_tools();
//     view->links = ft_init_links();
//     view->rot = ft_init_rot();
//     view->project = 0;
// 	view->theta = 0.0;
// 	view->phi = 0.0;
// 	view->psi = 0.0;
// 	view->scale = 0.5;
// 	view->z_scale = 1;
// 	view->x_shift = 0.0;
// 	view->y_shift = 0.0;
// 	view->z_shift = 0.0;
// 	view->focal_dist = 7;
// 	view->r = 1;
// 	view->g = 1;
// 	view->b = 1;
// 	return (view);
// }