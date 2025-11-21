#include "../include/cub3d.h"

int main(int argc, char **argv)
{
    t_file_info file_info;
    if(check_arguments(argc, argv))
        return 1;
    int result = start_parse_file_content(argv, argc, &file_info);
    printf("Number of lines: %d\n", result);
    return 0;
}


