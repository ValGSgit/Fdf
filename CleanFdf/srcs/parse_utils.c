/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:37 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/27 12:54:00 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	index_of(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	in_string(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (1);
}

int	hex_to_int(char *s)
{
	char	*hex;
	int		res;
	int		i;

	res = 0;
	hex = "0123456789abcdef";
	i = 0;
	while (s[i])
	{
		res = res * 16 + index_of(hex, to_lower(s[i]));
		i++;
	}
	return (res);
}

int	get_color_from_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ',')
		i++;
	if (!s[i])
		return (-1);
	return (hex_to_int(s + i + 2));
}
