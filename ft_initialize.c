/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:24:18 by lprior            #+#    #+#             */
/*   Updated: 2018/03/14 20:47:27 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_links    *ft_init_links(void)
{
    t_links *links;

    links = (t_links *)malloc(sizeof(t_links));
    links->x = -1;
    links->y = -1;
    links->ordinate = -1;
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
    YVAL = -1;
    tools->ordinate = NULL;
    FD = 0;
    return (tools);
}

t_mlx   *ft_init_mlx(void)
{
    t_mlx *mlx;

    if(!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
        return (NULL);
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx, WIDTH, HEIGHT, "Lprior FDF");
    return (mlx);   
}

t_pov *ft_init_pov(void)
{
    t_pov *pov;

    pov = (t_pov *)malloc(sizeof(t_pov));
    pov->degree_x = 0;
    pov->radian_x = 0;
    pov->degree_y = 0;
    pov->radian_y = 0;
    pov->degree_z = 0;
    pov->radian_z = 0;
    return (pov);    
}
