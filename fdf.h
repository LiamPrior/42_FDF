/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:32:52 by lprior            #+#    #+#             */
/*   Updated: 2018/03/21 17:18:53 by lprior           ###   ########.fr       */
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
	int			prev_x;
	int			prev_y;
    char        *altitude;
}               t_tools;

typedef struct  s_links
{
    struct      s_links *next;
    int         x;
    int         y;
    double         altitude;
    double         tru_y;
    double         tru_x;
}               t_links;

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
	double			scaling;
}					t_rotation;

typedef struct	s_env
{
	t_tools		*tools;
	t_links		*links;
	t_rotation	*rot;
	// t_mlx		*mlx;
	double		y_max;
	double		x_max;
	void        *mlx;
    void        *win;
}				t_env;
// typedef struct	s_env
// {
// 	void		*mlx;
// 	void		*win;
// 	void		*img;
// 	char		*pixels;
// 	t_tools		*tools;
// 	t_links		*links;
//  	t_rotation	*rot;
// 	// t_vertex	***points;
// 	// t_color		*colors;
// 	int			num_colors;
// 	int			width;
// 	int			height;
// 	int			z_min;
// 	int			z_max;
// 	float		theta;
// 	float		phi;
// 	float		psi;
// 	float		x_max;
// 	float		y_max;
// 	float		z_scale;
// 	float		scale;
// 	float		x_shift;
// 	float		y_shift;
// 	float		z_shift;
// 	float		r;
// 	float		g;
// 	float		b;
// 	int			focal_dist;
// 	int			bits_per_pixel;
// 	int			size_line;
// 	int			endian;
// 	// t_keys		*pressed;
// 	int			project:1;
// }				t_env;
//main
int 		ft_parse_the_map(t_env *all, t_tools *tools, t_links *links, int fd);//recursion used to increment y once x has finished
t_links 	*ft_parse_x(t_env *all, t_tools *tools, t_links *links);
int     	ft_create_list(t_links *head, t_tools *tools);
int 		ft_check_line(t_tools *tools);
//init
t_tools		*ft_init_tools(void);
t_links		*ft_init_links(void);
t_rotation	*ft_init_rot(void);
t_env		*ft_init(void);
// t_mlx   	*ft_init_mlx(void);
//lists
int 		ft_add_link(t_links *fresh, t_tools *tools);
//utilities
t_links     *create_link(t_tools *tools);
t_rotation	*ft_calc_radian(t_rotation *degrees);
//mlx bs
void		ft_repeat(t_env *all);
int	    	ft_key_hook(int key, t_env *all);
void 		ft_mlx_looper(t_env *all);
//rotation
t_links     *ft_lets_get_started(t_links *head, t_rotation *rot, t_env *all);
//draw
void    	ft_draw(t_env *all, t_links *links, t_tools *tools);
void    	ft_driving_y(t_env *all, double theda_x, double theda_y, double prev_x, double prev_y, double m);
void    	ft_driving_x(t_env *all, double theda_x, double theda_y, double prev_x, double prev_y, double m);


int		hook_keydown(int key, t_env *all);


#endif