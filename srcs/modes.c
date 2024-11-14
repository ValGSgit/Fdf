/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:31:07 by vagarcia          #+#    #+#             */
/*   Updated: 2024/11/13 12:58:03 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	colors_mode1(t_dot a, t_dot b)
{
	if (b.z && a.z && b.z == a.z)
		return (VIOLET_HEX);
	if (b.z != a.z)
		return (YELLOW_HEX);
	return (BLUE_HEX);
}

int	colors_mode2(t_dot a, t_dot b)
{
	if (b.z && a.z && b.z == a.z)
		return (YELLOW_HEX);
	if (b.z != a.z)
		return (VIOLET_HEX);
	return (MAX_COLOR_HEX);
}

int	colors_mode3(t_controller *params, t_dot a, t_dot b)
{
	if ((a.z || b.z) && a.z != b.z)
	{
		if (params->random_color)
			return (params->random_color);
		params->random_color = 0xFF0000;
		return (params->random_color);
	}
	return (YELLOW_HEX);
}

int	colors_mode4(t_controller *params, t_dot a, t_dot b)
{
	if ((a.z || b.z) && a.z != b.z)
	{
		if (params->random_color)
			return (params->random_color);
		params->random_color = BLUE_HEX;
		return (params->random_color);
	}
	if (params->random_color2)
		return (params->random_color2);
	params->random_color2 = YELLOW_HEX;
	return (params->random_color2);
}

int	colors_mode5(t_dot a, t_dot b)
{
	if (a.color >= 0)
		return (a.color);
	else if (b.color >= 0)
		return (b.color);
	return (0xFF0000);
}
