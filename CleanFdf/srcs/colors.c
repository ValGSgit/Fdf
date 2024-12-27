/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:45 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/27 12:55:50 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	color_mode1(t_dot a, t_dot b)
{
	if (b.z && a.z && b.z == a.z)
		return (VIOLET_HEX);
	if (b.z != a.z)
		return (YELLOW_HEX);
	return (BLUE_HEX);
}

int	color_mode2(t_dot a, t_dot b)
{
	if (b.z && a.z && b.z == a.z)
		return (YELLOW_HEX);
	if (b.z != a.z)
		return (VIOLET_HEX);
	return (MAX_COLOR_HEX);
}

void	change_color(t_controller *data)
{
	data->color = (data->color + 1) % (4 + data->is_colors);
	data->random_color = 0;
	data->random_color2 = 0;
}

int	get_color(t_controller *params, t_dot a, t_dot b)
{
	if (params->color == 4)
		return (color_mode5(a, b));
	if (params->color == 3)
		return (color_mode4(params, a, b));
	if (params->color == 2)
		return (color_mode3(params, a, b));
	if (params->color == 1)
		return (color_mode2(a, b));
	else
		return (color_mode1(a, b));
	return (0);
}
