/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:36:36 by lprior            #+#    #+#             */
/*   Updated: 2018/03/23 21:20:28 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void    ft_driving_x(t_env *all, double theda_x, double theda_y, double prev_x, double prev_y, double m)
// {
//     int e;
//     int x;
//     int y;

//     x = prev_x;
//     y = prev_y;
//     e = m - 1;
//     while (x < theda_x && y < theda_y)
//     {
//         mlx_pixel_put(all->mlx, all->win, (x + 100), (y + 100), 0xFFFFFF);
//         x++;
//         e += m;
//         if (e >= 0)
//         {
//             e -= 1;
//             y += m;
//         }
//     }
// }

// void    ft_driving_y(t_env *all, double theda_x, double theda_y, double prev_x, double prev_y, double m)
// {
//     int e;
//     int x;
//     int y;

//     x = prev_x;
//     y = prev_y;
//     e = m - 1;
//     while (x < theda_x && y < theda_y)
//     {
//         mlx_pixel_put(all->mlx, all->win, (x + 100), (y + 100), 0xFFFFFF);
//         y++;
//         e += m;
//         if (e >= 0)
//         {
//             e -= 1;
//             x += m;
//         }
//     }
// }

// void    ft_draw(t_env *all, t_links *links, t_tools *tools)
// {
//     int da;
//     t_links *temp;
//     double theda_x;
//     double theda_y;
//     int m;

//     temp = links;
//     da = -1;
//     while (temp)
//     {
//         theda_x = temp->tru_x - tools->prev_x;
//         theda_y = temp->tru_y - tools->prev_y;
//         m = theda_y/theda_x;
//         da = theda_x >= theda_y ? 1 : 0;
//         if (da > 0)
//         {
//             if (theda_x > tools->prev_x)
//                 ft_driving_x(all, theda_x, theda_y, tools->prev_x, tools->prev_y, m);
//             else
//                 ft_driving_x(all, tools->prev_x, tools->prev_y, theda_x, theda_y, m);
//         }
//         else if (da == 0)
//         {
//             if (theda_y > tools->prev_y)
//                 ft_driving_y(all, theda_x, theda_y, tools->prev_x, tools->prev_y, m);
//             else
//                 ft_driving_y(all, tools->prev_x, tools->prev_y, theda_x, theda_y, m);
//         }
//         tools->prev_x = temp->tru_x;
//         tools->prev_y = temp->tru_y;
//         temp = temp->next;
//     }
// }
// void	draw_xaxis(t_plc *start, t_plc *end, t_position *line, t_mlx *mlx)
// {
// 	int				e;
// 	int				slope;
// 	unsigned int	x;
// 	unsigned int	y;

// 	x = start->x_place;
// 	y = start->y_place;
// 	e = 2 * line->dy - line->dx;
// 	if (y < (int)end->y_place)
// 		slope = 1;
// 	else
// 		slope = -1;
// 	while (x < (int)end->x_place)
// 	{
// 		mlx_pixel_put(mlx->mlx, mlx->window, x, y, 0xFFFFFF);
// 		if (e < 0)
// 			e += 2 * line->dy;
// 		else
// 		{
// 			y += slope;
// 			e += 2 * (line->dy - line->dx);
// 		}
// 		x++;
// 	}
// }
// void    ft_driving_x(t_env *all, double theda_x, double theda_y, double prev_x, double prev_y, double m)
// {
//     int e;
//     int x;
//     int y;

//     x = prev_x;
//     y = prev_y;
//     e = m - 1;
//     while (x < theda_x && y < theda_y)
//     {
//         mlx_pixel_put(all->mlx, all->win, (x + 100), (y + 100), 0xFFFFFF);
//         x++;
//         e += m;
//         if (e >= 0)
//         {
//             e -= 1;
//             y += m;
//         }
//     }
// }
//////////////////////////////////

void ft_driving_x(t_links *initial, t_links *terminal, t_env *all)
{
    double e; //element of;
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
    double e; //element of;
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

    all->theda_x = terminal->tru_x - initial->tru_x;
    all->theda_y = terminal->tru_y - initial->tru_y;
    da = all->theda_x >= all->theda_y ? 1 : 0;
    if (da > 0)
        initial->tru_x <= terminal->tru_x ? ft_driving_x(initial, terminal, all) : ft_driving_x(terminal, initial, all);
    else if (da == 0)
        initial->tru_y <= terminal->tru_y ? ft_driving_y(initial, terminal, all) : ft_driving_y(terminal, initial, all);
    // if (da > 0)
    // {
    //     if (initial->tru_x <= terminal->tru_x)
    //         ft_driving_x(initial, terminal, all);
    //     else
    //         ft_driving_x(terminal, initial, all);
    // }
    // else if (da == 0)
    // {
    //     if (initial->tru_y <= terminal->tru_y)
    //         ft_driving_y(initial, terminal, all);
    //     else
    //         ft_driving_y(terminal, initial, all);
    // }    

}
