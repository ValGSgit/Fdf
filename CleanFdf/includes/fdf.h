/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:03:01 by codespace         #+#    #+#             */
/*   Updated: 2024/12/27 13:03:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
//# include <mlx.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define INPUT_ERR "Please provide a valid FDF map: ./my_fdf [map.42]"
# define MALLOC_ERR "Memory allocation failed."
# define FILE_ERR "File not found."
# define EXTENSION_ERR "File must have a .fdf extension."
# define INVALID_MAP_ERR "Invalid map format."
# define END_MSG "Program closed successfully."
# define MLX_ERR "MiniLibX initialization failed."
# define WIN_ERR "Window creation failed."
# define TITLE "My FDF"

# define MAX_COLOR_HEX 16777215
# define VIOLET_HEX 0x8F00FF
# define YELLOW_HEX 0xFFFF00
# define BLUE_HEX 0x177E89
# define L_MAX 9223372036854775807

typedef struct pix
{
    float	x;
    float	y;
    float	z;
    int		is_last;
    int		color;
}	t_pix;

typedef struct s_img
{
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}	t_img;

typedef struct data
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
    t_pix		**matrix;
    t_img		img;
}	t_data;

// Colors
int		color5(t_pix a, t_pix b);
int		color4(t_data *params, t_pix a, t_pix b);
int		color3(t_data *params, t_pix a, t_pix b);
int		get_color(t_data *params, t_pix a, t_pix b);
void	change_color(t_data *data);
int		color2(t_pix a, t_pix b);
int		color1(t_pix a, t_pix b);

// Error Handling
int		is_ext_valid(const char *s);
void	ft_error(char *msg);
void	put_err(const char *s);
void	*malloc_check(size_t size, size_t size_of);
void	ft_free(char **arr);
void	is_valid(char *s);
int		ft_isspace(char c);
int		ft_exit(t_data *data);
char	to_lower(char c);

// Bunch of Meth
void	apply_isometric(t_pix *pix, double angle);
float	absolute_value(float x);
float	max_value(float x, float y);
void	apply_zoom(t_pix *a, t_pix *b, t_data *param);
int		coordinate_x(float x, t_data *data);
int		coordinate_y(float y, t_data *data);
double	get_z_scale(t_data *data);
double	get_scale(t_data *data);
void	init_coords(t_pix *a, t_pix *b, t_data *param);

// Mapping
t_pix	**parse_map(char *file_name);
int		open_file(char *file_name, int permissions);
void	draw(t_pix **matrix, t_data *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		get_color_from_line(char *s);

// Mlx Stuff
int		if_key(int key, t_data *data);
void	print_menu(t_data *param);

// Struct
void	init_data(t_data *data, t_pix **matrix);

// Utils
int		index_of(char *s, char c);
int		hex_to_int(char *s);
void	set_color_styles(t_data *data);
char	*get_next_line(int fd);
int		in_string(char *s, char c);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_wdcounter(char const *str, char c);
void	free_matrix(t_pix **matrix);
int		ft_skipspace(const char *str);

#endif
