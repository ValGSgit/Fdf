/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:38 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/31 13:27:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_rows(int fd, char *line)
{
	int	i;

	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (i);
}

int	get_pixs_from_line(char *line, t_pix **matrix, int y)
{
	char	**points;
	int		x;

	if (!line)
		put_err(INVALID_MAP_ERR);
	points = ft_split(line, ' ');
	if (!points)
		return (ft_free(points), put_err(MALLOC_ERR), exit(1), 0);
	x = 0;
	while (points[x])
	{
		is_valid(points[x]);
		matrix[y][x].z = ft_atoi(points[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].color = get_color_from_line(*(points + x));
		matrix[y][x].is_last = 0;
		free(points[x++]);
	}
	free(points);
	matrix[y][x - 1].is_last = 1;
	return (x);
}

void	alloc_new(t_pix **new, int y, int x)
{
	while (y > 0)
	{
		new[--y] = (t_pix *)malloc(sizeof(t_pix) * (x + 1));
		if (!new[y])
			free_matrix(new);
	}
}

t_pix	**allocate_all(char *file_name)
{
	t_pix	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open_file(file_name, O_RDONLY);
	line = get_next_line(fd);
	new = NULL;
	if (!line)
	{
		close(fd);
		put_err(INVALID_MAP_ERR);
	}
	x = ft_wdcounter(line, ' ');
	y = count_rows(fd, line);
	new = (t_pix **)malloc(sizeof(t_pix *) * (++y + 1));
	if (!new)
		return (close(fd), free(file_name), exit(1), NULL);
	alloc_new(new, y, x);
	close(fd);
	return (new);
}

t_pix	**parse_map(char *file_name)
{
	t_pix	**matrix;
	int		y;
	int		fd;
	char	*line;

	matrix = allocate_all(file_name);
	fd = open_file(file_name, O_RDONLY);
	if (!matrix || fd < 0)
		return (free(file_name), NULL);
	y = 0;
	line = get_next_line(fd);
	if (!line)
		return (free_matrix(matrix), (fd), put_err(INVALID_MAP_ERR), NULL);
	while (line)
	{
		get_pixs_from_line(line, matrix, y++);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (matrix[y])
		free(matrix[y]);
	return (matrix[y] = NULL, close(fd), matrix);
}
