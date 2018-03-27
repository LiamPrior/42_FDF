/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:32:52 by lprior            #+#    #+#             */
/*   Updated: 2018/03/26 17:00:25 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 800
# define HEIGHT 600
# define FD int fd
# define NXT fresh->next
# define LINE tools->line
# define XVAL tools->x
# define YVAL tools->y
# define BAD tools->bad
# define ISVLD !ft_isdigit(LINE[i]) || LINE[i] != '-'
# define NEXTMLLC (fresh->next = (t_links *)malloc(sizeof(t_links)))
# define PI 3.14159265359
# define TRANS_Y (links->altitude * sin(rot->radian_x)
# define TRANS_Z links->y * sin(rot->radian_x)
# define SIN_Y sin(rot->radian_y)
# define SIN_Z sin(rot->radian_z)

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
    char			*line;
	int				i;
    bool        	bad;
    int         	fd;
    int         	y;
	int         	x;
	double			prev_x;
	double			prev_y;
    char        	*altitude;
}               	t_tools;

typedef struct  	s_links
{
    struct      	s_links *next;
    int         	x;
    int         	y;
    int         	altitude;
    double        	tru_y;
	double         	tru_x;
}               	t_links;

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
	double			degree_x;
	double			radian_x;
	double			degree_y;
	double			radian_y;
	double			degree_z;
	double			radian_z;
	double			z2;
}					t_rotation;

typedef struct		s_env
{
	t_tools			*tools;
	t_links			*links;
	t_rotation		*rot;
	double			y_max;
	double			x_max;
	double			theda_x;
	double			theda_y;
	void        	*mlx;
	void        	*win;
	int 			i;
}					t_env;

int 		ft_parse_the_map(t_env *all, t_tools *tools, t_links *links, FD);
t_links 	*ft_parse_x(t_env *all, t_tools *tools, t_links *links);
int     	ft_create_list(t_links *head, t_tools *tools);
int 		ft_check_line(t_tools *tools);
//init
t_tools		*ft_init_tools(void);
t_links		*ft_init_links(void);
t_rotation	*ft_init_rot(void);
t_env		*ft_init(void);
//lists
int 		ft_add_link(t_links *fresh, t_tools *tools);
//utilities
t_links     *ft_create_link(t_tools *tools);
t_rotation	*ft_calc_radian(t_rotation *degrees);
//mlx bs
void		ft_repeat(t_env *all);
int	    	ft_key_hook(int key, t_env *all);
void 		ft_mlx_looper(t_env *all);
//rotation
void 		ft_lets_get_started(t_links *head, t_rotation *rot, t_env *all);
//draw
void    	ft_directions(t_env *all);
t_links 	*ft_find_terminal(t_env *all);
void 		ft_draw(t_links *initial, t_links *terminal, t_env *all);
void 		ft_driving_y(t_links *initial, t_links *terminal, t_env *all);
void 		ft_driving_x(t_links *initial, t_links *terminal, t_env *all);
int			hook_keydown(int key, t_env *all);
void		ft_quit(t_env *all);


#endif