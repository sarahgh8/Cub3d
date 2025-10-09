#ifndef __CUB3D_H__
#define __CUB3D_H__

#include "../../minilibx-linux/mlx.h"
#include "../Libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum e_error
{
    ARG_ERR,
    CONT_ERR
}   t_error;

typedef enum e_category
{
    TEXTURE,
    FC_COLORS,
    MAP
}   t_category;

typedef struct s_prep
{
    void *con;
    void *win;
    void *img;
}t_prep;

typedef struct s_map_file
{
    char **dir_texture;
    char **fc_colors;
    char **map_content;
    char *file_name;
}   t_map_file;

void print_error(t_error type);
int check_args(int argc, char **argv);
int check_map_content(char *file_name);
void init_map_file(t_map_file *content, char *file_name);
void parse_texture(char *line, t_map_file *c);
void parse_file(t_map_file *c);

#endif