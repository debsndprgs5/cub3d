/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:37:22 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/13 15:33:37 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUBE_H
# define CUBE_H

# include "./Includes/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 960

# define HEIGHT 540

# define FOV 90.2

# define SPEED 0.05

# define UP_KEY 119

# define DOWN_KEY 115

# define LEFT_KEY 97

# define RIGHT_KEY 100

# define LOOK_RIGHT 65363

# define LOOK_LEFT 65361

# define LOOK_SPEED 1

#define MOUSE_TGLE 96

# define TRUE 1

# define FALSE 0

# define MOUSE_TGLE 96

# define WALL_HIGTH  1.5

# define PLAYER_HEIGHT 0.75
// Walls/Ground raw images

typedef struct s_image
{
	void	**mlx_img;
	char	*address;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_asset
{
	t_image		image;
	int 		width;
	int 		height;
}	t_asset;

typedef struct s_ppos
{
	double	x;
	double	y;
}	t_ppos;

typedef struct s_dbl_int
{
	int start;
	int end;
}	t_dbl_int;

typedef struct s_ray
{
	double	deltadistx; /* La longueur
	du rayon depuis le point courant jusqu'au prochain cote x */
	double	deltadisty; /* La longueur
	du rayon depuis le point courant jusqu'au prochain cote y */
	double	sidedistx; // Distance vers le prochain mur en X
	double	sidedisty; // Distance vers le prochain mur en Y
	double	perpwalldist;
	int		stepx; // FLAG / Quel cote le rayon va tapper ensuite
	int		stepy; // FLAG / Quel cote le rayon va tapper ensuite
	int		hit; // FLAG / Est-ce que le rayon a touché un mur ?
	int		side; /* FLAG / Est-ce que le rayon a 
	touché un côté X ou un côté Y du bloc ?*/
	int		x0; // Valeur de x de depart (pos joueur)
	int		y0; // Valeur de y de depart (pos joueur)
	double	dx; // Vecteurs directionnel dx/dy
	double	dy;
}	t_ray;

typedef struct s_keypress
{
	bool	key_forward;
	bool	key_back;
	bool	key_left;
	bool	key_right;
	bool	look_right;
	bool	look_left;
}	t_keypress;

// Main struct
// Paths are N->0 S->1 E->2 W->3 in this order
typedef struct s_game
{
	t_asset		assets[4];
	t_image		background;
	t_image		current;
	t_image		next;
	bool		is_current;
	// int			ymin;
	int			ymax;
	// int			xmin;
	int			xmax;
	char		**paths;
	char		**map;
	void		*mlx_session;
	void		*mlx_window;
	int			groundcol[4];
	bool		ground_check;
	int			skycol[4];
	bool		sky_check;
	t_ppos		ppos;
	double		lookingdir;
	double		wall_dist;
	t_keypress	keypress;
}	t_game;

typedef enum s_ErrorCode
{
	MORE_THAN_ONE_DIRECTION = 1,
	MAP_NOT_ENCLOSED_BY_WALLS,
	CANNOT_OPEN_NORTH_ASSET,
	CANNOT_OPEN_SOUTH_ASSET,
	CANNOT_OPEN_EAST_ASSET,
	CANNOT_OPEN_WEST_ASSET,
	ARGS_UNDEFINED,
	RGB_RANGE,
	RGB_ARGS,
	INVALID_CONFIG,
	MEM_FAIL,
	FILE_NOT_EXIST,
	INVALID_MAP,
	MAP_NOT_EXIST,
	WRONG_EXTENT,
	DUP_ARGS,
	MISSING_ARGS,
	POS_ERROR,
	MATH_ERROR,
}	t_ErrorCode;

// PARSING FUNCTIONS //

int		raycasting_loop(t_game *game);
char	**readmap(char *pathtofile);
void	freetab(char **str);
int		get_param(char **config_file, t_game *game);
int		split_map(char **map, char ***part1, char ***part2);
int		get_color(char *parse_line, int *stack);
int		check_split_col(char **split);
int		init_struct(t_game *game, char **config_file);
char	*clean_first_spaces(char *str, int i);
char	*removes_spaces(char *spc_line);
char	*parse_config_line(char *line);
int		get_dir_path(char *path, char **stack, int index);
int		free_game(t_game *game);
int		map_check(char **map);
void	get_format(char ***parsedmap);
double	get_iniplayerdir(t_game *game);
void 	init_asset(t_game *game);
int		exit_game(t_game *game);

// RENDERING FUNCTIONS //

int get_textures(t_image texture, int x, int y);
int get_texture_line(int line, int wall_size, int size);
int get_texture_row(double x, double y, int size);
int		render_game(t_game *game);
void		set_good_wall(double wall_x, double wall_y, t_game *game, t_asset *current_wall);
double	get_wall_higth(t_game *game);
void	render_wall(double wall_x, double wall_y, int pixel_rows, t_game *game);
void	lhookylhook(t_game *game);
int		get_key(int key, t_game *game);
int		release_key(int key, t_game *game);
double	deg_to_rad(double degrees);
int		get_good_rgb(int *arr);/* use here only to have color render
wall instead of xpm textures */
t_image	create_background(t_game *game);
void	my_pixel_put(t_image *image, int x, int y, int color);
void	load_raycast_image(t_game *game);
int		check_cursor(int x, int y, t_game *game);
void	toggle_mouse(t_game *game);
void	player_move(int key, t_game *game);
void	player_look(int key, t_game *game);
void	distribute_rays(t_game *game, double *angles);
int		iswall(int x, int y, char **map);
void	init_calc_ray(t_ray *ray);
double	fisheyefix(double dx, double dy);

// ERROR CHECKING //

void	print_param(t_game *game);
int		is_good_char(char *parse_line);
int		check_extention(char *path, char *ext, int len);
int		check_game(t_game *game);
int		free_used_lines(char *a, char *b);
int		printerror(t_ErrorCode err);

// METH //

void	adjust_coords(double *x, double *y);
double	rad_to_deg(double radians);
double	deg_to_rad(double degrees);

#endif
