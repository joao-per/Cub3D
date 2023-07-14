/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:20:52 by quackson          #+#    #+#             */
/*   Updated: 2023/07/14 17:32:22 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define CUB 1
# define XPM 2
# define MAX_LINE_LENGTH 1000
# define WIDTH 640
# define HEIGHT 480
# define TILE_SIZE 30
# define ESC 65307
# define KEY_PRESS_EVENT 2 
# define KEY_PRESS_MASK 1L
# define DESTROY_EVENT 17

# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	char	*path;
	int		width;
	int		fd;
	int		line_nbr;
	int		line_count;
	int		height;
	int		player_x;
	int		player_y;
	char	player_orientation;
}	t_map;

typedef struct s_scene
{
	int		num_lines;
	char	**lines;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	int		ceil_rgb[3];
	int		floor_rgb[3];
	t_map	*map;
}	t_scene;

typedef struct s_cub3d
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_scene	*scene;
	t_map	map_data;
}	t_cub3d;

/*				Check Map				*/
int		file_exists(char *filename);
int		is_file_type(int type, char *filename);
int		is_valid_file(t_cub3d *cubed, char *file);

t_cub3d	*init_data(void);
void	register_hooks(t_cub3d *game_data);
int		get_split_len(char **split);
void	free_char_doub_ptr(char **pointer);
void	free_resources(t_cub3d *game_data);
int		handle_closewindow(t_cub3d *game_data);
char	*get_next_line(int fd);
void	check_map_dimensions(int x, int oldx, int y);
void	check_map_validity(int x, int y);
int		get_scene_data(t_cub3d *game_data, char *map_file);
int		get_num_lines(char *map_file);
int		parse_data(t_cub3d *cubed, char *file);
#endif