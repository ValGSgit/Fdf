/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:34 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/27 12:54:11 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

void	is_valid(char *s)
{
	int	i;

	if (!s)
		put_err(INVALID_MAP_ERR);
	i = 0;
	i += (s[i] == '-');
	while (s[i] && s[i] != ',')
	{
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]))
			put_err(INVALID_MAP_ERR);
		i++;
	}
	if (!s[i] || s[i] == ' ')
		return ;
	i += 1;
	if (ft_strlen(s + i) < 3)
		put_err(INVALID_MAP_ERR);
	while (s[i])
	{
		if (!in_string("0123456789abcdef", to_lower(s[i])))
			put_err(INVALID_MAP_ERR);
		i++;
	}
}

int	color_mode3(t_controller *params, t_dot a, t_dot b)
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

int	color_mode4(t_controller *params, t_dot a, t_dot b)
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

int	color_mode5(t_dot a, t_dot b)
{
	if (a.color >= 0)
		return (a.color);
	else if (b.color >= 0)
		return (b.color);
	return (0xFF0000);
}
