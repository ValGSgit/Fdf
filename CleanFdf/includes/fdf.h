/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/12/26 11:23:22 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/26 11:23:22 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define INPUT_ERR "please enter a valid fdf map as follows: ./fdf [map.42]"
# define MALLOC_ERR "there was an unexpected error in malloc :( "
# define FILE_ERR "the file you entered was not found :("
# define EXTENSION_ERR "please enter a file that ends with [.fdf]"
# define INVALID_MAP_ERR "the map you entered is invalid :("
# define END_MSG "the program has been closed properly!"
# define MLX_ERR "THERE WAS AN ERROR IN THE MINILIBX INITIALIZATION :("
# define WIN_ERR "THERE WAS AN UNEXPECTED ERROR IN CREATING THE WINDOW :("
# define TITLE "FDF"

# define MAX_COLOR_HEX 16777215
# define VIOLET_HEX 0x8F00FF
# define YELLOW_HEX 0xFFFF00
# define BLUE_HEX 0x177E89
# define L_MAX 9223372036854775807

typedef struct dot
{
	float	x;
	float	y;
	float	z;
	int		is_last;
	int		color;
}	t_dot;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct controller
{
	double		scale;
	int			color;
	int			random_color;
	int			random_color2;
	int			map_scale;
	int			is_colors;
	double		z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
	t_dot		**matrix;
	t_img		img;
}	t_controller;

// Colors
int		color_mode5(t_dot a, t_dot b);
int		color_mode4(t_controller *params, t_dot a, t_dot b);
int		color_mode3(t_controller *params, t_dot a, t_dot b);
int		get_color(t_controller *params, t_dot a, t_dot b);
void	change_color(t_controller *data);
int		color_mode2(t_dot a, t_dot b);
int		color_mode1(t_dot a, t_dot b);

// Error Handling
int		is_ext_valid(const char *s);
void	ft_error(char *msg);
void	put_err(const char *s);
void	*malloc_check(size_t size, size_t size_of);
void	ft_free(char **arr);
void	is_valid(char *s);
int		ft_isspace(char c);
int		ft_exit(t_controller *data);
char	to_lower(char c);

// Bunch of Meth
void	isometric(t_dot *dot, double angle);
float	abs_float_value(float x);
float	max_float_value(float x, float y);
void	zoom(t_dot *a, t_dot *b, t_controller *param);
int		coor_x(float x, t_controller *data);
int		coor_y(float y, t_controller *data);
double	get_z_scale(t_controller *data);
double	get_scale(t_controller *data);
void	init_coords(t_dot *a, t_dot *b, t_controller *param);

// Mapping
t_dot	**parse_map(char *file_name);
int		open_file(char *file_name, int permissions);
void	draw(t_dot **matrix, t_controller *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		get_color_from_line(char *s);

// Mlx Stuff
int		if_key(int key, t_controller *data);
void	print_menu(t_controller *param);

// Struct
void	init_controller(t_controller *data, t_dot **matrix);

// Utils
int		index_of(char *s, char c);
int		hex_to_int(char *s);
void	set_color_styles(t_controller *data);
char	*get_next_line(int fd);
int		in_string(char *s, char c);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_wdcounter(char const *str, char c);
void	free_matrix(t_dot **matrix);
int		ft_skipspace(const char *str);

#endif
