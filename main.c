/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:55:37 by lprior            #+#    #+#             */
/*   Updated: 2018/03/06 16:55:29 by lprior           ###   ########.fr       */
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

int ft_parse_map(t_links *head, t_tools *tools)
{
    t_links *next;
    t_links *prev;

    next = head;
    while (next->next != NULL)
        next = next->next;
    if (!(NEXTMLLC))
        return (-1);

}

int main(int argc, char **argv)
{
    void    *mlx;
    void    *window;
    t_tools *tools;
    t_links *links;
    
    ft_init_tools(links, tools);
    if (argc == 2)
    {
        tools->fd = open(argv[1], O_RDONLY);
        while (get_next_line(tools->fd, &tools->line) > 0)
        {
            if (!(tools->line[0]))
                return(0);
            ft_parse_map(links, tools)//->line, tools->y, tools->x);
            tools->line[0] = '\0';
        }
    }
    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 800, "Lprior FDF");
    mlx_hook(window, 2, 0, keydown, 0);
    mlx_loop(mlx);
}