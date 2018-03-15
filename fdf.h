/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:32:52 by lprior            #+#    #+#             */
/*   Updated: 2018/03/14 20:48:13 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1000
# define HEIGHT 1000
 
# define FD tools->fd
# define NXT fresh->next
# define LINE tools->line
# define XVAL tools->x
# define YVAL tools->y
# define BAD tools->bad
# define ISVLD !ft_isdigit(LINE[i]) || LINE[i] != '-'
# define NEXTMLLC (fresh->next = (t_links *)malloc(sizeof(t_links)))
# define PI 3.14159265359

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
    int         tru_y;
    int         tru_x;
}               t_links;

typedef struct s_mlx
{
    void        *mlx;
    void        *win;
}              t_mlx;

typedef struct		s_rotation
{
	double			x0;
	double			x1;
	double			x2;
	double			y0;
	double			y1;
	double			y2;
	double			z0;
	double			z1;
	// double			z2;
}					t_rotation;
typedef struct		s_pov
{
	double			degree_x;
	double			radian_x;
	double			degree_y;
	double			radian_y;
	double			degree_z;
	double			radian_z;
	// double			scaling;
}					t_pov;

int     ft_parse_the_map(t_tools *tools, t_links *links, int fd);//recursion used to increment y once x has finished
t_links *ft_parse_x(t_tools *tools, t_links *links);
int     ft_create_list(t_links *head, t_tools *tools);
void    tools_to_list(t_tools *tools, t_links *fresh);
t_tools    *ft_init_tools(void);
t_links    *ft_init_links(void);
int     ft_check_line(t_tools *tools);
int     ft_add_link(t_links *fresh, t_tools *tools);
t_links     *create_link(t_tools *tools);
t_pov	*ft_find_radian(t_pov *degrees);

#endif