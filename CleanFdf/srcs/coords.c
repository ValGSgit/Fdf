/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:43 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/27 12:53:53 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	abs_float_value(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

float	max_float_value(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

int	coor_x(float x, t_controller *data)
{
	if ((int)round(x) >= data->win_x)
		return ((int) x);
	return ((int) round(x));
}

int	coor_y(float y, t_controller *data)
{
	if ((int) round(y) >= data->win_y)
		return ((int) y);
	return ((int) round(y));
}

void	init_coords(t_dot *a, t_dot *b, t_controller *param)
{
	zoom(a, b, param);
	if (param->is_isometric)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}
