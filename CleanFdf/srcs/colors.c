/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:45 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/30 20:00:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	color1(t_pix a, t_pix b)
{
	if (b.z && a.z && b.z == a.z)
		return (VIOLET_HEX);
	if (b.z != a.z)
		return (YELLOW_HEX);
	return (BLUE_HEX);
}

int	color2(t_pix a, t_pix b)
{
	if (b.z && a.z && b.z == a.z)
		return (YELLOW_HEX);
	if (b.z != a.z)
		return (VIOLET_HEX);
	return (MAX_COLOR_HEX);
}

void	change_color(t_data *data)
{
	data->color = (data->color + 1) % (4 + data->is_colors);
	data->random_color = 0;
	data->random_color2 = 0;
}

int	get_color(t_data *params, t_pix a, t_pix b)
{
	if (params->color == 4)
		return (color5(a, b));
	if (params->color == 3)
		return (color4(params, a, b));
	if (params->color == 2)
		return (color3(params, a, b));
	if (params->color == 1)
		return (color2(a, b));
	else
		return (color1(a, b));
	return (0);
}
