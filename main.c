/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:55:37 by lprior            #+#    #+#             */
/*   Updated: 2018/03/10 17:24:06 by lprior           ###   ########.fr       */
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

void tools_to_list(t_tools *tools, t_links *fresh)
{
    fresh->x = tools->x;
    fresh->y = tools->y;
    fresh->ordinate = ft_atoi(tools->line);
}

int ft_parse_map(t_links *head, t_tools *tools)
{
    t_links *fresh;
    t_links *prev;

    fresh = head;
    while (fresh->next != NULL)//go to end of list!
        fresh = fresh->next;
    if (!(NEXTMLLC))//if it doesnt malloc return -1;
        return (-1);
    while(tools->line++ > 32)//move past spaces
        tools->line++;
    tools_to_list(tools, fresh);
    prev = fresh;
    fresh->next = NULL;
    fresh->prev = prev;
	if (tools->line[0] == '\0')
		return (-1);
	return (ft_strsrc(tools->line) ? 1 : -1);
}

int main(int argc, char **argv)
{
    void    *mlx;
    void    *window;
    t_tools *tools;
    t_links *links;
    
    ft_init_structs(links, tools);
    if (argc == 2)
    {
        tools->fd = open(argv[1], O_RDONLY);
        while (get_next_line(tools->fd, &tools->line) > 0)
        {
            if (!(tools->line[0]))
                return(0);
            ft_parse_map(links, tools);//->line, tools->y, tools->x);
            tools->line[0] = '\0';
        }
        close(tools->fd);
    }
    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 800, "Lprior FDF");
    mlx_hook(window, 2, 0, keydown, 0);
    mlx_loop(mlx);
}