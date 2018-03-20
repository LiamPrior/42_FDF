/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:14:00 by lprior            #+#    #+#             */
/*   Updated: 2018/03/19 16:06:27 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// int		hook_keydown(int key, t_all *all)
// {
// 	int i;

// 	if (key == 53)
// 		ft_exit(1, all);
// 	if (key == 13)
// 		all->cam->angle_x += .01;
// 	if (key == 1)
// 		all->cam->angle_x -= .01;
// 	if (key == 2)
// 		all->cam->angle_y += .01;
// 	if (key == 0)
// 		all->cam->angle_y -= .01;
// 	redraw(all);
// 	return (0);
// }
void ft_repeat(t_env *all)
{
    ft_calc_radian(all->rot);
    ft_lets_get_started(all->links, all->rot, all);
    ft_draw(all->links, all->tools);
}

void    ft_key_hook(int key, t_env *all)
{
    if (key == 53)
        ft_exit(1, all);//I have to free all my structs close window and terminate program;
    else if (key == 37)
        all->rot->degree_x += .01;
    else if (key == 38)
        all->rot->degree_y += .01;
    else if (key == 39)
        all->rot->degree_x += .01;
    else if (key == 40)
        all->rot->degree_y += .01;
    re_repeat(all);
}

void ft_mlx_looper(t_env *all)
{
    t_list *dup;

    dup = all->links;
    ft_init_mlx();
    ft_draw(all->links, all->tools);
    mlx_key_hook(all->mlx->win, ft_key_hook, all);
    mlx_loop(all->mlx->mlx);
}