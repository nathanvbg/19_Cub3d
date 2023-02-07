/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:12:26 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/21 16:50:14 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"

typedef struct s_coord_int
{
	int				x;
	int				y;
}					t_coord_int;

typedef struct s_coord_double
{
	double			x;
	double			y;
}					t_coord_double;

typedef struct s_sprites
{
	int				spr_count;
	double			*sprite_x;
	double			*sprite_y;
	double			*distance;
	int				check;
	double			spritex;
	double			spritey;
	double			invdet;
	double			spr_screenx;
	t_coord_double	transform;
	t_coord_int		drawstart;
	t_coord_int		drawend;
	t_coord_int		text;
	int				width;
	int				height;
	int				stripe;
	double			*zbuffer;
}					t_sprites;

typedef struct s_img
{
	void			*ptr;
	int				*addr;
	int				endian;
	int				bbp;
	int				size_l;
	t_coord_int		size;
}					t_img;

typedef struct s_design
{
	char			**map;
	int				map_length;
	t_img			text_no;
	t_img			text_so;
	t_img			text_ea;
	t_img			text_we;
	t_img			text_s;
	char			*text_path_no;
	char			*text_path_so;
	char			*text_path_ea;
	char			*text_path_we;
	char			*text_path_s;
	int				fl;
	int				c;
	t_coord_int		screen;
	t_coord_int		max;
	int				nb1;
	int				nb2;
	int				nb3;
}					t_design;

typedef struct s_dda
{
	t_coord_double	pos;
	t_coord_double	dir;
	t_coord_double	olddir;
	t_coord_double	plane;
	double			oldplx;
	double			camx;
	t_coord_double	raydir;
	t_coord_int		map;
	t_coord_double	distbetween;
	t_coord_double	distnext;
	t_coord_int		jump;
	double			step;
	int				hit;
	int				side;
	double			wallperp;
	int				lineheight;
	int				drawmin;
	int				drawmax;
	double			wall_x;
	double			texpos;
	t_coord_int		text;
}					t_dda;

typedef struct s_idx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				save;
	t_img			img;
	t_dda			dda;
	t_design		ds;
	t_sprites		spr;
}					t_idx;

void				init_mlx(t_idx *c);
void				check_args(t_idx *c, int argc, char **argv);
void				bmp(t_idx *c);
void				create_header(int fd, t_idx *c, int file_size);
void				init(t_idx *c);
void				init_design(t_idx *c);
void				init_dda(t_idx *c);
void				init_sprites(t_idx *c);
void				def_resolution(t_idx *c, char *line);
char				*str_pointer(char *line);
void				def_direction(t_idx *c, char pos);
void				def_floor_ceiling(t_idx *c, char *line, int *color);
void				def_floor_ceiling_2(t_idx *c, char *line, int *color);
void				parsing(t_idx *c, char *file);
void				gnl_info(t_idx *c, int fd);
void				parse_info(char *str, t_idx *c);
void				gnl_map(t_idx *c, int fd);
int					line_empty(char *line);
void				adjust_map(t_idx *c);
char				*ft_strdup_line(char *line, int max);
void				init_texture(t_idx *c);
void				def_text_path(t_idx *c, char **text_path, char *line);
void				define_texture(t_idx *c, char *path, t_img *text);
t_img				*get_texture_img(t_idx *c);
void				manage_sprites(t_idx *c);
void				malloc_sprites(t_idx *c);
void				sprites_position(t_idx *c);
void				sort_sprites(t_idx *c);
void				ft_swap(t_idx *c, int i, int j);
void				transform_sprites(t_idx *c, int i);
void				sprites_draw_limits(t_idx *c);
void				sprites_draw_line(t_idx *c);
void				draw_sprites(t_idx *c);
void				position_init(t_idx *c);
void				def_direction(t_idx *c, char pos);
void				map_error(t_idx *c);
void				map_length(t_idx *c);
void				is_map_closed(t_idx *c, int x, int y);
void				ft_exit(t_idx *c, char *str);
void				free_map(t_idx *c);
void				free_text(t_idx *c);
void				free_sprites(t_idx *c);
void				algo(t_idx *c);
void				init_map_var1(t_idx *c, int x);
void				init_map_var2(t_idx *c);
void				dda(t_idx *c);
void				line_height(t_idx *c);
void				check_empty_line(t_idx *c, char *map);
void				draw_line(t_img *text_img, t_idx *c, int x);
int					command_vertical(int key, t_idx *c);
int					command_horizontal(int key, t_idx *c, double speed);
int					command_rotation(int key, t_idx *c);
int					red_cross(t_idx *c);
void				init_save(t_idx *c);

#endif
