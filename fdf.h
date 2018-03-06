/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:32:52 by lprior            #+#    #+#             */
/*   Updated: 2018/03/05 19:33:53 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "unistd.h"
# include "stdlib.h"
# include <fcntl.h>
# include "get_next_line/libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "math.h"

typedef struct		s_plc
{
	struct s_plc	*next;
	struct s_plc	*last;
	unsigned int	x;
	unsigned int	y;
	int				z;
	int				x_place;
	int				y_place;
}					t_plc;

typedef struct		s_position
{
	double			dx;
	double			dy;
}					t_position;

typedef struct		s_cam
{
	double			angle_x;
	double			radian_x;
	double			angle_y;
	double			radian_y;
	double			angle_z;
	double			radian_z;
	double			scaling;
}					t_cam;

typedef struct		s_rot
{
	double			x0;
	double			x1;
	double			x2;
	double			y0;
	double			y1;
	double			y2;
	double			z0;
	double			z1;
	double			z2;
}					t_rot;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
}					t_mlx;

typedef struct		s_all
{
	struct s_plc	*head;
	struct s_cam	*cam;
	struct s_mlx	*mlx;
}					t_all;

typedef struct		s_read
{
	int				fd;
	char			*line;
	int				y;
}					t_read;
