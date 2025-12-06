#ifndef __CUB3D_H__
#define __CUB3D_H__

#include "../../minilibx-linux/mlx.h"
#include "../Libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_file_info
{
    char *filename;
    char **content;
}   t_file_info;

typedef struct s_map_data
{
    char *north;
    char *south;
    char *east;
    char *west;
    char *floor;
    char *ceiling;
    char **map;
    int *player_pos;
} t_map_data;

typedef struct s_map_flags
{
    int north;
    int south;
    int east;
    int west;
    int floor;
    int ceiling;
} t_map_flags;

int check_filename_format(char *filename);
int check_arguments(int argc, char **argv);
int start_extract_file_content(char **argv, t_file_info *file_info);
void clean_file_info(t_file_info *file_info);
void ft_2d_free(char **arr);
int start_parse_file_content(t_file_info *file_info, t_map_data *map_data, t_map_flags *map_flags);
int init_flags(t_map_flags *map_flags);
void clean_map_data(t_map_data *map_data);
int init_flags(t_map_flags *map_flags);
int validate_map_content(t_file_info *file_info, t_map_data *map_data);
int is_map_content(char *map_line);
int count_2d_array(char **arr);
int validate_textures_colors(t_map_data *map_data);

#endif