/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:35 by vagarcia          #+#    #+#             */
/*   Updated: 2025/01/12 13:48:15 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	get_z_scale(t_data *data)
{
	if (data->map_scale < 50)
		return (1.3);
	if (data->map_scale < 100)
		return (1);
	if (data->map_scale < 300)
		return (0.5);
	if (data->map_scale < 500)
		return (0.4);
	if (data->map_scale < 700)
		return (0.3);
	if (data->map_scale < 900)
		return (0.2);
	return (0.1);
}

double	get_scale(t_data *data)
{
	if (data->map_scale < 100)
		return (3);
	if (data->map_scale < 200)
		return (1.5);
	if (data->map_scale < 400)
		return (1);
	if (data->map_scale < 500)
		return (0.5);
	if (data->map_scale < 700)
		return (0.4);
	if (data->map_scale < 900)
		return (0.3);
	return (0.2);
}

void	isometric(t_pixl *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void	zoom(t_pixl *a, t_pixl *b, t_data *param)
{
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
}

void	print_menu(t_data *param)
{
	char	*menu;

	menu = "CLICK [ENTER] TO GET BACK TO INITIAL STATE";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 10, 0xffffff, menu);
	menu = "PRESS [2/3] FOR 2D/3D MODE";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 45, 0xffffff, menu);
	menu = "PRESS [z/x] TO ZOOM IN OR ZOOM OUT";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 80, 0xffffff, menu);
	menu = "PRESS [c] TO CHANGE COLORS";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 115, 0xffffff, menu);
	menu = "PRESS [q/w] KEYS TO CHANGE DEPTH (Z-SCALE)";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 150, 0xffffff, menu);
	menu = "PRESS [a/d] KEYS FOR ROTATING THE Y AXIS";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 185, 0xffffff, menu);
	menu = "MOVE THE PROJECT BY PRESSING THE ARROW KEYS";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 220, 0xffffff, menu);
	menu = "PRESS [ESC] TO CLOSE THE WINDOW";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 255, 0xffffff, menu);
}
