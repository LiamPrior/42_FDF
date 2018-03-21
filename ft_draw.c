/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:36:36 by lprior            #+#    #+#             */
/*   Updated: 2018/03/20 16:52:01 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_driving_x(t_env *all, int theda_x, int theda_y, int prev_x, int prev_y, int m)
{
    int e;
    int x;
    int y;

    x = prev_x;
    y = prev_y;
    e = m - 1;
    while (x < theda_x && y < theda_y)
    {
        mlx_pixel_put(all->mlx, all->win, x, y, 0xFFFFFF);
        x++;
        e += m;
        if (e >= 0)
        {
            e -= 1;
            y += m;
        }
    }
}

void    ft_driving_y(t_env *all, int theda_x, int theda_y, int prev_x, int prev_y, int m)
{
    int e;
    int x;
    int y;

    x = prev_x;
    y = prev_y;
    e = m - 1;
    while (x < theda_x && y < theda_y)
    {
        mlx_pixel_put(all->mlx, all->win, x, y, 0xFFFFFF);
        y++;
        e += m;
        if (e >= 0)
        {
            e -= 1;
            x += m;
        }
    }
}

void    ft_draw(t_env *all, t_links *links, t_tools *tools)
{
    int da;
    t_links *temp;
    double theda_x;
    double theda_y;
    int m;

    printf("indraw\n");
    temp = links;
    da =-1;
    while (temp)
    {
        theda_x = links->tru_x - tools->prev_x;
        theda_y = links->tru_x - tools->prev_y;
        m = theda_y/theda_x;
        da = theda_x >= theda_y ? 1 : 0;
        if (da > 0)
        {
            if (theda_x > tools->prev_x)
                ft_driving_x(all, theda_x, theda_y, tools->prev_x, tools->prev_y, m);
            else
                ft_driving_x(all, tools->prev_x, tools->prev_y, theda_x, theda_y, m);
        }
        else if (da == 0)
        {
            if (theda_y > tools->prev_y)
                ft_driving_y(all, theda_x, theda_y, tools->prev_x, tools->prev_y, m);
            else
                ft_driving_y(all, tools->prev_x, tools->prev_y, theda_x, theda_y, m);
        }
        tools->prev_x = links->tru_x;
        tools->prev_y = links->tru_y;
        temp = temp->next;
    }
}