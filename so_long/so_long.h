#ifndef SO_LONG_H
# define SO_LONG_H

// INCLUDES
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// # include "./srcs/libft/printf/ft_printf.h" 
# include "./srcs/libft/libft/libft.h"
# include "./srcs/libft/get_next_line/get_next_line.h"

typedef struct img
{
	int			width;
	int			height;
	int			x_pos;
	int			y_pos;
	char		*path;
	void		*img_data;
} t_img;

typedef struct monster
{
	int			x_pos;
	int			y_pos;
	int			reached_edge;
} t_monster;

typedef struct player
{
	int		player_pos_x;
	int		player_pos_y;
	int		colectibles_earned;
	int		is_won;
	int		is_lost;
	int		moves;
}	t_player;

typedef struct map
{
	int			width;
	int			height;
	char		**map_lines;
	int			collectibles;
	t_player	player1;
	t_monster 	monsters[10];
} t_map;

typedef struct data
{
	void		*ptr;
	void		*win;
	t_map		map;
	t_img		*bg;
	t_img		*wall;
	t_img		*cat_moves;
	t_img		*you_lose;
	t_img		*you_win;
	t_img		*cat_right[8];
	t_img		*cat_left[8];
	t_img		*cat_damaged[4];
	t_img		*coin[6];
	t_img		*exit[4];
	t_img		*monster[4];
	int			cat_direction;
	int			exit_frame;
}	t_mlx;


// MAP_CHECK.
void    is_map_valid(char * file_path, t_map *map);
int 	is_map_file_path_valid(char * file_path);
int		custom_strlen(char *line);
void	is_line_components_valid(char *line);
int		is_border_wall(char *line);

// ERROR_HANDLING
void    error_handle(char *error_name);

//Inits
void	initialize_structs(t_mlx *mlx);
int 	initialize_mlx(t_mlx *mlx);
void	initialize_map(t_mlx *mlx, int CoinFrame, int cat_frame, int exit_frame, int monster_frame);
void	initialize_textures(t_mlx *mlx);
int		texture_attach(t_mlx *mlx, t_img *texture, int pos_x, int pos_y);

//Hooks
void	initialize_hooks(t_mlx *mlx);
int		on_keypress(int keysym, t_mlx *mlx);
int		on_destroy(t_mlx *mlx);

//Events
void    handle_player_move(t_mlx *mlx, char move_direction);
int		is_next_move_valid(t_mlx *mlx, int next_x, int next_y);
int 	is_next_move_earn_clb(t_mlx *mlx, int next_x, int next_y);
int		is_next_move_exit(t_mlx *mlx, int next_x, int next_y);
int		is_next_move_enemy(t_mlx *mlx, int next_x, int next_y);
void    handle_next_move_exit(t_mlx *mlx);
void 	handle_game_exit_won();
void    handle_game_lose(t_mlx *mlx);
void	handle_monster_move(t_mlx *mlx);

#endif