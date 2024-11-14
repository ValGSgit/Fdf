/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:30:24 by vagarcia          #+#    #+#             */
/*   Updated: 2024/11/12 13:09:22 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

typedef struct dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;
	int			color;
}				t_dot;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct controller
{
	double			scale;
	int				color_style;
	int				random_color;
	int				random_color2;
	int				map_largenest;
	int				has_colors;
	double			z_scale;
	int				shift_x;
	int				shift_y;
	int				is_isometric;
	double			angle;
	int				win_x;
	int				win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	t_dot			**matrix;
	t_img			img;
}	t_controller;

#endif
