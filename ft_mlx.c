/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:14:00 by lprior            #+#    #+#             */
/*   Updated: 2018/03/20 19:42:38 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_repeat(t_env *all)
{
    ft_calc_radian(all->rot);
    ft_lets_get_started(all->links, all->rot, all);
    mlx_clear_window(all->mlx, all->win);
    ft_draw(all, all->links, all->tools);
}

int    ft_key_hook(int key, t_env *all)
{
    if (key == 53)
    {
        write(1, "quit\n", 5);
        //ft_exit(1, all);//I have to free all my structs close window and terminate program;
    }
    else if (key == 37)
        all->rot->degree_x += .01;
    else if (key == 38)
        all->rot->degree_y += .01;
    else if (key == 39)
        all->rot->degree_x += .01;
    else if (key == 40)
        all->rot->degree_y += .01;
    ft_repeat(all);
    return (0);
}

void ft_mlx_looper(t_env *all)
{
    void *img;
    void *win;

    img = mlx_init();
    win = mlx_new_window(img, WIDTH, HEIGHT, "KMS");
    // ft_draw(all, all->links, all->tools);
    // mlx_key_hook(win, ft_key_hook, all);
    mlx_loop(img);
}