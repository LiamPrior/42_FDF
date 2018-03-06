/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:55:37 by lprior            #+#    #+#             */
/*   Updated: 2018/03/06 14:34:25 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int keydown(int keycode)
{
    ft_printf("%d\n", keycode);
    if (keycode == 53)
        exit(1);
    return (0);
}
int main(int argc, char **argv)
{
    void    *mlx;
    void    *window;
    static  int *fd;
    char    *line;

    *fd = (open argv[1], O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        
    }
    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 800, "Lprior FDF");
    mlx_hook(window, 2, 0, keydown, 0);
    mlx_loop(mlx);
}