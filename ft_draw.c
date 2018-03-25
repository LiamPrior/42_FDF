/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:36:36 by lprior            #+#    #+#             */
/*   Updated: 2018/03/24 20:26:11 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_driving_x(t_links *initial, t_links *terminal, t_env *all)
{
    double e;
    double x;
    double y;
    double slope;

    x = initial->tru_x;
    y = initial->tru_y;
    e = 2 * all->theda_y - all->theda_x;
    slope = y < terminal->tru_y ? 1 : -1;
    while (x < terminal->tru_x)
    {
        mlx_pixel_put(all->mlx, all->win, x, y, 0xFFFFFF);
        if (e < 0)
            e += 2 * all->theda_y;
        else
        {
            y += slope;
            e += 2 * (all->theda_y - all->theda_x);
        }
        x++;
    }
}

void ft_driving_y(t_links *initial, t_links *terminal, t_env *all)
{
    double e;
    double x;
    double y;
    double slope;

    x = initial->tru_x;
    y = initial->tru_y;
    e = 2 * all->theda_x - all->theda_y;
    slope = x < terminal->tru_x ? 1 : -1;
    while (y < terminal->tru_y)
    {
        mlx_pixel_put(all->mlx, all->win, x, y, 0xFFFFFF);
        if (e < 0)
            e += 2 * all->theda_x;
        else
        {
            x += slope;
            e += 2 * (all->theda_x - all->theda_y);
        }
        y++;
    }
}

void ft_draw(t_links *initial, t_links *terminal, t_env *all)
{
    int     da;

    all->theda_x = fabs(terminal->tru_x - initial->tru_x);
    all->theda_y = fabs(terminal->tru_y - initial->tru_y);
    da = all->theda_x >= all->theda_y ? 1 : 0;
    if (da > 0)
        initial->tru_x <= terminal->tru_x ? ft_driving_x(initial, terminal, all) : ft_driving_x(terminal, initial, all);
    else if (da == 0)
        initial->tru_y <= terminal->tru_y ? ft_driving_y(initial, terminal, all) : ft_driving_y(terminal, initial, all);
}
