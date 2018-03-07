/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:32:52 by lprior            #+#    #+#             */
/*   Updated: 2018/03/06 16:54:27 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define NEXTMLLC (new->next = (t_plc *)malloc(sizeof(t_plc)))

# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "GNL/libft/libft.h"
# include "GNL/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <math.h>

typedef struct  s_tools
{
    char		*line;
    int         fd;
    int         y;
    int         x;

}               t_tools;

typedef struct  s_links;
{
    struct s_link *next;
    struct s_link *prev;
}               t_links;

// typedef struct		s_plc
// {
// 	struct s_plc	*next;
// 	struct s_plc	*lasåt;
// 	unsigned int	x;
// 	unsigned int	y;
// 	int				z;
// 	int				x_place;
// 	int				y_place;
// }					t_plc;

// typedef struct		s_position
// {
// 	double			dx;
// 	double			dy;
// }					t_position;

// typedef struct		s_cam
// {
// 	double			angle_x;
// 	double			radian_x;
// 	double			angle_y;
// 	double			radian_y;
// 	double			angle_z;
// 	double			radian_z;
// 	double			scaling;
// }					t_cam;

// typedef struct		s_rot
// {
// 	double			x0;
// 	double			x1;
// 	double			x2;
// 	double			y0;
// 	double			y1;
// 	double			y2;
// 	double			z0;
// 	double			z1;
// 	double			z2;
// }					t_rot;

// typedef struct		s_mlx
// {
// 	void			*mlx;
// 	void			*window;
// }					t_mlx;

// typedef struct		s_all
// {
// 	struct s_plc	*head;
// 	struct s_cam	*cam;
// 	struct s_mlx	*mlx;
// }					t_all;

// typedef struct		s_read
// {
// 	int				fd;
// 	char			*line;
// 	int				y;
// }					t_read;
    links = ft_init_links();
    tools = ft_init_tools();
#endif