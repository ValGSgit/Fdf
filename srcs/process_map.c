/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:38 by vagarcia          #+#    #+#             */
/*   Updated: 2025/01/15 18:33:45 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_rows(int fd, char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
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

int	init_matrix(char *line, t_pixl **matrix, int y)
{
	char	**points;
	int		x;

	points = ft_split(line, ' ');
	if (!points)
		return (ft_free(points), put_err(MALLOC_ERR), exit(1), 0);
	x = 0;
	while (points[x])
	{
		if (!is_valid(points[x]))
			return (put_err(INVALID_MAP_ERR), 0);
		matrix[y][x].z = ft_atoi(points[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].color = line_color(*(points + x));
		matrix[y][x].is_last = 0;
		free(points[x++]);
	}
	free(points);
	matrix[y][--x].is_last = 1;
	return (x);
}

void	alloc_new(t_pixl **new, int y, int x)
{
	while (y > 0)
	{
		new[--y] = (t_pixl *)malloc(sizeof(t_pixl) * (x + 1));
		if (!new[y])
		{
			free_matrix(new);
			put_err(MALLOC_ERR);
		}
	}
}

t_pixl	**alloc_points(char *file_name)
{
	t_pixl	**new;
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
	x = count_words(line, ' ');
	y = count_rows(fd, line);
	new = (t_pixl **)malloc(sizeof(t_pixl *) * (++y + 1));
	if (!new)
		return (close(fd), free(file_name), exit(1), NULL);
	alloc_new(new, y, x);
	close(fd);
	return (new);
}

t_pixl	**process_map(char *file_name)
{
	t_pixl	**matrix;
	int		y;
	int		fd;
	char	*line;

	matrix = alloc_points(file_name);
	if (!matrix)
		put_err(MALLOC_ERR);
	fd = open_file(file_name, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), put_err(INVALID_MAP_ERR), NULL);
	while (line && ft_srch(line, '\n'))
	{
		init_matrix(line, matrix, y++);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (matrix[y])
		free(matrix[y]);
	return (matrix[y] = NULL, close(fd), matrix);
}
