/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:28:56 by vagarcia          #+#    #+#             */
/*   Updated: 2024/11/14 13:13:19 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_key(int key)
{
	return (key == XK_Return || key == XK_2 || key == XK_3 || \
			key == XK_z || key == XK_x || key == XK_c || \
			key == XK_a || key == XK_d || key == XK_q || key == XK_w || \
			key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down
		|| key == XK_Escape);
}

void	get_back_to_normal_state(t_controller *data)
{
	data->scale = get_scale(data) * 25;
	data->z_scale = get_z_scale(data);
	data->angle = 0.563599;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
}

void	move_events(int key, t_controller *data)
{
	if (key == XK_Left)
		data->shift_x -= 10;
	else if (key == XK_Right)
		data->shift_x += 10;
	else if (key == XK_Up)
		data->shift_y -= 10;
	else if (key == XK_Down)
		data->shift_y += 10;
	else if (key == XK_a)
		data->angle += 0.07;
	else if (key == XK_d)
		data->angle -= 0.07;
	else if (key == XK_q)
		data->z_scale += get_z_scale(data);
	else if (key == XK_w)
		data->z_scale -= get_z_scale(data);
	else if (key == XK_z)
		data->scale += get_scale(data);
	else if (key == XK_x)
		data->scale -= get_scale(data);
}

void	do_key(int key, t_controller *data)
{
	move_events(key, data);
	if (key == XK_Return)
		get_back_to_normal_state(data);
	if (key == XK_2 || key == XK_3)
		data->is_isometric = !data->is_isometric;
	if (key == XK_c)
		set_color_styles(data);
	if (key == XK_Escape)
		ft_exit(data);
}

int	catch_events(int key, t_controller *data)
{
	if (is_key(key))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		do_key(key, data);
		print_menu(data);
		draw(data->matrix, data);
	}
	return (0);
}
