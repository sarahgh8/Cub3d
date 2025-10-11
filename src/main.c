#include "../include/cub3d.h"

int main(int argc, char **argv)
{
    char *file_name;
    t_file_content data[100];
    if(!check_argv(argc, argv))
        return 1;
    file_name = argv[1];
    if(!check_file_content(file_name, &data));
        return 1;
    printf("File content read successfully\n");
    return 0;
}
