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

typedef struct s_file_content
{
    t_category category;
    char *content;
}   t_file_content;

void print_error(t_error type);
int check_argv(int argc, char **argv);
int check_file_content(char *file_name, t_file_content *data);


#endif