/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamprior <liamprior@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:55:37 by lprior            #+#    #+#             */
/*   Updated: 2018/03/12 23:24:01 by liamprior        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//  gcc main.c fdf.h ft_lists.c ft_initialize.c -L./libft -lft
int keydown(int keycode)
{
    ft_printf("%d\n", keycode);
    if (keycode == 53)
        exit(1);
    return (0);
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
int ft_check_line(t_tools *tools)
{
    // int i;

    // i = 0;
    // // printf("HERELS\n");
    // while (LINE[i])
    // {
    //     if (!ft_isdigit(LINE[i]) || LINE[i] != '-')
    //         i++;
    //     else
    //         return (1);
    // }
    // printf("HERELS\n");
    // return (-1);
    int i;

	i = 0;
	while (LINE[i])
	{
		if (ft_isdigit(LINE[i]) || LINE[i] == '-')
			return (1);
		i++;
	}
	return (-1);
}
int ft_create_list(t_links *head, t_tools *tools)
{
    t_links *fresh;

    fresh = head;
	if (tools->line[0] == '\0')
        return (-1);
    if(!ft_add_link(fresh))
        return (-1);
    tools_to_list(tools, fresh);
    // fresh->x = X;
    // fresh->y = Y;
    // fresh->ordinate = ft_atoi(LINE);
    printf("x = %d, y = %d, z = %d", fresh->x, fresh->y, fresh->ordinate);
    fresh->next = NULL;
	return (ft_check_line(tools) ? 1 : -1);
}

t_links *ft_parse_x(t_tools *tools, t_links *links)
{
    int i;

    i = 0;
    X++;
    // printf("line = [%s]", tools->line);
    while (*LINE == ' ')
    {
        // printf("line = %c", tools->line[0]);
        LINE++;
        if (*LINE && (!ft_isdigit(*LINE) && *LINE != '-'))
            BAD = true;
    }
    if (ft_create_list(links, tools) == -1)
        return(links);
    else
        while (*LINE && (ft_isdigit(LINE[0]) || LINE[0] == '-'))
            LINE++;
    return (ft_parse_x(tools, links));
}

int ft_parse_the_map(t_tools *tools, t_links *links, int fd)
{
    Y++;
    if (get_next_line(fd, &LINE) > 0)
    {
        ft_parse_x(tools, links);
        X = 0;
        if (BAD == false)
            ft_parse_the_map(tools, links, fd);
        else
        {   
            ft_printf(RED);
            ft_printf("Errno: BAD MAP!");
            ft_printf(NORMAL);
            return (0);
        }
    }
    return (1);
}

int main(int argc, char **argv)
{
    void    *mlx;
    void    *window;
    t_tools *tools;
    t_links *links;
    int     fd;

    links = ft_init_links();
    tools = ft_init_tools();
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (!ft_parse_the_map(tools, links, fd))
            return (0);
            // tools->fd = open(argv[1], O_RDONLY);
        // while (get_next_line(tools->fd, &tools->line) > 0)
        // {
        //     if (!(tools->line[0]))
        //         return(0);
        //     ft_parse_map(links, tools);//->line, tools->y, tools->x);
        //     tools->line[0] = '\0';
        // }
        // close(tools->fd);
    }
    // free links
    // mlx = mlx_init();
    // window = mlx_new_window(mlx, 800, 800, "Lprior FDF");
    // mlx_hook(window, 2, 0, keydown, 0);
    // mlx_loop(mlx);
}