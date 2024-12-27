/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:38 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/27 12:54:42 by vagarcia         ###   ########.fr       */
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

int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	if (!line)
		put_err(INVALID_MAP_ERR);
	dots = ft_split(line, ' ');
	if (!dots)
		return (ft_free(dots), put_err(MALLOC_ERR), exit(1), 0);
	x = 0;
	while (dots[x])
	{
		is_valid(dots[x]);
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].color = get_color_from_line(*(dots + x));
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

void	alloc_new(t_dot **new, int y, int x)
{
	while (y > 0)
	{
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
		if (!new[y])
			free_matrix(new);
	}
}

t_dot	**allocate_all_dots(char *file_name)
{
	t_dot	**new;
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
	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	if (!new)
		return (close(fd), free(file_name), exit(1), NULL);
	alloc_new(new, y, x);
	close(fd);
	return (new);
}

t_dot	**parse_map(char *file_name)
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = allocate_all_dots(file_name);
	fd = open_file(file_name, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		put_err(INVALID_MAP_ERR);
	}
	while (line)
	{
		get_dots_from_line(line, matrix_of_dots, y++);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (matrix_of_dots[y])
		free(matrix_of_dots[y]);
	return (matrix_of_dots[y] = NULL, close(fd), matrix_of_dots);
}
