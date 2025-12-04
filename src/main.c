#include "../include/cub3d.h"

void ft_2d_free(char **arr)
{
    int i = 0;
    if (!arr)
        return;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int main(int argc, char **argv)
{
    t_file_info file_info;
    if(check_arguments(argc, argv))
        return 1;
    if(start_extract_file_content(argv, &file_info))
        return 1;
    clean_file_info(&file_info);
    return 0;
}