#include "../include/cub3d.h"

int main(int argc, char **argv)
{
    t_file_info file_info;
    if(check_arguments(argc, argv))
        return 1;
    if(start_parse_file_content(argv, &file_info))
        return 1;
    clean_file_info(&file_info);
    return 0;
}


