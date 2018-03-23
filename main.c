/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:55:37 by lprior            #+#    #+#             */
/*   Updated: 2018/03/22 21:44:03 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}
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
    all->x_max = (double)XVAL;
    while (*LINE == ' ')
    {
        LINE++;
        if (*LINE && (!ft_isdigit(*LINE) && *LINE != '-' && *LINE != ' '))
            BAD = true;
    }
    if (ft_create_list(links, tools) == -1)
        return(links);
    else
        while (*LINE && (ft_isdigit(LINE[0]) || LINE[0] == '-'))
            LINE++;
    return (ft_parse_x(all, tools, links));
}


int ft_parse_the_map(t_env *all, t_tools *tools, t_links *links, int fd)
{
    YVAL++;
    if (get_next_line(fd, &LINE) > 0)
    {
        XVAL = 0;
        free(LINE);
        ft_parse_x(all, tools, links);
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
    t_env       *all;
    int     fd;//possibly put into a struct
    all = ft_init();
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (!ft_parse_the_map(all, all->tools, all->links, fd))
            return (0);
        close (fd);
        all->links = all->links->next;
        ft_calc_radian(all->rot);
        ft_lets_get_started(all->links, all->rot, all);
        ft_mlx_looper(all);
    }
}
