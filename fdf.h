/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:32:52 by lprior            #+#    #+#             */
/*   Updated: 2018/03/12 20:42:37 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FD tools->fd
# define NXT fresh->next
# define LINE tools->line
# define X tools->x
# define Y tools->y
# define BAD tools->bad
# define ISVLD !ft_isdigit(LINE[i]) || LINE[i] != '-'
# define NEXTMLLC (fresh->next = (t_links *)malloc(sizeof(t_links)))

# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <math.h>

typedef struct  s_tools
{
    char		*line;
    bool        bad;
    int         fd;
    int         y;
    int         x;
    char        *ordinate;
}               t_tools;

typedef struct  s_links
{
    struct      s_links *next;
    int         x;
    int         y;
    int         ordinate;
}               t_links;

int     ft_parse_the_map(t_tools *tools, t_links *links, int fd);//recursion used to increment y once x has finished
t_links *ft_parse_x(t_tools *tools, t_links *links);
int     ft_create_list(t_links *head, t_tools *tools);
void    tools_to_list(t_tools *tools, t_links *fresh);
t_tools    *ft_init_tools(void);
t_links    *ft_init_links(void);
void    ft_init_structs(t_tools *tools, t_links *links);
int     ft_check_line(t_tools *tools);
int     ft_add_link(t_links *fresh);

#endif