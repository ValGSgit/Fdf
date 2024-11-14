/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:29:53 by vagarcia          #+#    #+#             */
/*   Updated: 2024/11/13 12:56:19 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_color_styles(t_controller *data)
{
	data->color_style = (data->color_style + 1) % (4 + data->has_colors);
	data->random_color = 0;
	data->random_color2 = 0;
}

int	get_color(t_controller *params, t_dot a, t_dot b)
{
	if (params->color_style == 4)
		return (colors_mode5(a, b));
	if (params->color_style == 3)
		return (colors_mode4(params, a, b));
	if (params->color_style == 2)
		return (colors_mode3(params, a, b));
	if (params->color_style == 1)
		return (colors_mode2(a, b));
	else
		return (colors_mode1(a, b));
	return (0);
}
