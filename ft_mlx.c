/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:14:00 by lprior            #+#    #+#             */
/*   Updated: 2018/03/26 17:14:14 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_repeat(t_env *all)
{
    all->i = 0;
    // ft_calc_radian(all->rot);
    ft_lets_get_started(all->links, all->rot, all);
    mlx_clear_window(all->mlx, all->win);
    ft_directions(all);
}

int    ft_key_hook(int key, t_env *all)
{

    if (key == 53)
        ft_quit(all);
    else if (key == 126)
        all->rot->degree_x += 1;
    else if (key == 124)
        all->rot->degree_y += 1;
    else if (key == 125)
        all->rot->degree_x -= 1;
    else if (key == 123)
        all->rot->degree_y -= 1;
	else if (key == 13)
		all->rot->degree_x += 1;
	else if (key == 1)
		all->rot->degree_x -= 1;
	else if (key == 2)
		all->rot->degree_y += 1;
	else if (key == 0)
		all->rot->degree_y -= 1;
	ft_repeat(all);
	return (0);

}

void ft_mlx_looper(t_env *all)
{
    all->mlx = mlx_init();
    all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "KMS");
    ft_directions(all);
    mlx_hook(all->win, 2, 0, ft_key_hook, all);
    mlx_loop(all->mlx);
}