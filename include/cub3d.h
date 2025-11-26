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

int check_filename_format(char *filename);
int check_arguments(int argc, char **argv);
int start_parse_file_content(char **argv, int argc, t_file_info *file_info);


#endif