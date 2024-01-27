#ifndef SO_LONG_H
# define SO_LONG_H

// INCLUDES
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct img
{
	int			width;
	int			height;
	int			x_pos;
	int			y_pos;
	char		*path;
	void		*img_data;
} t_img;

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

//---------------------------------------MAP_CHECK.
void    is_map_valid(char * file_path, t_map *map);
void	is_line_components_valid(char *line);
void	is_line_valid(char *curr_line);
int 	is_map_file_path_valid(char * file_path);
int		is_border_wall(char *line);
int		custom_strlen(char *line);
//--------------------------------

//-----------------------ERROR_HANDLING
void    error_handle(char *error_msg);
void	destroy_images(t_mlx *mlx);
void    free_textures(t_mlx *mlx);
void    free_lines(t_mlx *mlx);
//-----------------------------

//--------------------------------Inits
void	initialize_structs(t_mlx *mlx);
int 	initialize_mlx(t_mlx *mlx);
void	initialize_map(t_mlx *mlx, int CoinFrame, int cat_frame, int exit_frame, int monster_frame);
void	initialize_textures(t_mlx *mlx);
int		texture_attach(t_mlx *mlx, t_img *texture, int pos_x, int pos_y);
//-----------------------------------------------------------------------

//------------------------------Hooks
void	initialize_hooks(t_mlx *mlx);
int		on_keypress(int keysym, t_mlx *mlx);
int		on_destroy(t_mlx *mlx);
//-----------------------------

//----------------------------------------------------Events
void    handle_player_move(t_mlx *mlx, char move_direction);
int		is_next_move_valid(t_mlx *mlx, int next_x, int next_y);
int 	is_next_move_earn_clb(t_mlx *mlx, int next_x, int next_y);
int		is_next_move_exit(t_mlx *mlx, int next_x, int next_y);
int		is_next_move_enemy(t_mlx *mlx, int next_x, int next_y);
void    handle_next_move_exit(t_mlx *mlx);
void	handle_game_exit_won(t_mlx *mlx);
void    handle_game_lose(t_mlx *mlx);
void	handle_monster_move(t_mlx *mlx);
//--------------------------------------

//Libft------------------------
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t elements_count, size_t element_size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strrchr(const char *str, int c);
int		gnl_strlen(char *str);
int		gnl_strchr(char *s, char c);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
int		ft_putadress(unsigned long nb);
int		ft_putchar(char c);
int		ft_puthex_m(unsigned int nb);
int		ft_puthex(unsigned int nb);
int		ft_putnbr(int nb);
int		ft_putstr(char *s);
int		ft_putunbr(unsigned int nb);
//-----------------------------


#endif