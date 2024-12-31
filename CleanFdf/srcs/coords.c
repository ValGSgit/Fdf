/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:43 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/30 20:04:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	absolute_value(float x)
{
    if (x < 0)
        return (-x);
    return (x);
}

float	max_value(float x, float y)
{
    if (x > y)
        return (x);
    return (y);
}

int	coordinate_x(float x, t_data *data)
{
    if ((int)round(x) >= data->win_x)
        return ((int) x);
    return ((int) round(x));
}

int	coordinate_y(float y, t_data *data)
{
    if ((int) round(y) >= data->win_y)
        return ((int) y);
    return ((int) round(y));
}

void	init_coords(t_pix *a, t_pix *b, t_data *param)
{
    a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
    if (param->is_isometric)
    {
        a->x = (a->x - a->y) * cos(param->angle);
	    a->y = (a->x + a->y) * sin(param->angle) - a->z;
        b->x = (b->x - b->y) * cos(param->angle);
	    b->y = (b->x + b->y) * sin(param->angle) - b->z;
    }
    a->x += param->shift_x;
    a->y += param->shift_y;
    b->x += param->shift_x;
    b->y += param->shift_y;
}
