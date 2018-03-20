/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:55:37 by lprior            #+#    #+#             */
/*   Updated: 2018/03/19 19:35:54 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//  gcc main.c fdf.h ft_lists.c ft_initialize.c -L./libft -lft
int ft_key_hook(int keycode)
{
    ft_printf("%d\n", keycode);
    if (keycode == 53)
        ft_exit();
    return (0);
}


int ft_check_line(t_tools *tools)//change me
{
    int i;

	i = 0;
	while (LINE[i])
	{
		if (ft_isdigit(LINE[i]) || LINE[i] == '-')
			return (1);
		i++;
	}
	return (-1);
}//.............
int ft_create_list(t_links *head, t_tools *tools)
{
    t_links *fresh;

    fresh = head;
	if (tools->line[0] == '\0')
        return (-1);
    if(!ft_add_link(fresh, tools))
        return (-1);
	return (ft_check_line(tools) ? 1 : -1);
}

t_links *ft_parse_x(t_env *all, t_tools *tools, t_links *links)
{
    int i;

    i = 0;
    XVAL++;
    printf("%d\n", XVAL);
    all->x_max = (double)XVAL;
    while (*LINE == ' ')
    {
        LINE++;
        if (*LINE && (!ft_isdigit(*LINE) && *LINE != '-'))
            BAD = true;
    }
    if (ft_create_list(links, tools) == -1)
        return(links);
    else
        while (*LINE && (ft_isdigit(LINE[0]) || LINE[0] == '-'))
            LINE++;
    // all->x_max = (double)XVAL;
    return (ft_parse_x(all, tools, links));
}


int ft_parse_the_map(t_env *all, t_tools *tools, t_links *links, int fd)
{
    YVAL++;
    if (get_next_line(fd, &LINE) > 0)
    {
        ft_parse_x(all, tools, links);
        // LINE = NULL;
        XVAL = 0;
        if (BAD == false)
            ft_parse_the_map(all, tools, links, fd);
        else
        {   
            ft_printf(RED);
            ft_printf("Errno: BAD MAP!");
            ft_printf(NORMAL);
            return (0);
        }
    }
    all->y_max = (double)YVAL;
    return (1);
}

int main(int argc, char **argv)
{
    // t_mlx       *mlx;
    // t_tools     *tools;
    // t_links     *links;
    // t_rotation  *rot;
    t_env       *all;
    int     fd;//possibly put into a struct

    all = ft_init();
    // links = ft_init_links();
    // tools = ft_init_tools();
    // rot = ft_init_rot();
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (!ft_parse_the_map(all, all->tools, all->links, fd))
            return (0);
        // free (all);
        ft_calc_radian(all->rot);
        all->links = all->links->next;
        ft_lets_get_started(all->links, all->rot, all);
        // ft_draw(all->links, all->tools);
        ft_mlx_looper(all);
    }
    // mlx = ft_init_mlx();
    // mlx = (t_mlx *)malloc(sizeof(t_mlx));
    // while (all->links)
    // {
    //     printf("x = [%d], y = [%d], z = [%d]\n", all->links->x, all->links->y, all->links->ordinate);
    //     all->links = all->links->next;
    // }
    // mlx->mlx = mlx_init();
    // mlx->win = mlx_new_window(mlx, WIDTH, HEIGHT, "Lprior FDF");
    // // return (0);
    // mlx = mlx_init();
    // mlx->win = mlx_new_window(mlx, WIDTH, HEIGHT, "Lprior FDF");
    // mlx_hook(mlx->win, 2, 0, keydown, 0);
    // mlx_loop(mlx);
}


// int		ft_strsrc(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (ft_isdigit(str[i]) || str[i] == '-')
// 			return (1);
// 		i++;
// 	}
// 	return (-1);
// }

// int		put_t_plc(t_plc *first, char *str, int y, int x)
// {
// 	t_plc			*new;
// 	t_plc			*last;

// 	new = first;
// 	while (new->next != NULL)
// 		new = new->next;
// 	if (!(new->next = (t_plc *)malloc(sizeof(t_plc))))
// 		return (-1);
// 	new->x = x;
// 	new->y = y;
// 	new->z = ft_atoi(str);
// 	last = new;
// 	new = new->next;
// 	new->next = NULL;
// 	new->last = last;
// 	while (str[0] == '\0')
// 		return (-1);
// 	return (ft_strsrc(str) ? 1 : -1);
// }

// t_plc	*parse(t_plc *current, char *str, int y, int x)
// {
// 	while (!(ft_isdigit(str[0]) || str[0] == '-') && str[0])
// 		str++;
// 	if (!(str[0]))
// 		return (0);
// 	if (put_t_plc(current, str, y, x) == -1)
// 		return (current);
// 	else
// 		while (ft_isdigit(str[0]) || str[0] == '-')
// 			str++;
// 	return (parse(current, str, y, x + 1));
// }

// int		main(int argc, char **argv)
// {
// 	t_read			*read;
// 	t_plc			*start;
// 	t_cam			*cam;
// 	t_all			*all;

// 	read = init_read();
// 	start = init_plc();
// 	cam = init_cam();
// 	if (argc == 2)
// 	{
// 		read->fd = open(argv[1], O_RDONLY);
// 		while (get_next_line(read->fd, &read->line) != 0)
// 		{
// 			parse(start, read->line, read->y++, 0);
// 			read->line = NULL;
// 		}
// 		close(read->fd);
// 		free(read);
// 	}
// 	reinit_cam(cam);
// 	do_find_points(cam, start);
// 	all = init_all(cam, start);
// 	mlx_looper(all);
// 	return (0);
// }
// int		ft_strsrc(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (ft_isdigit(str[i]) || str[i] == '-')
// 			return (1);
// 		i++;
// 	}
// 	return (-1);
// }