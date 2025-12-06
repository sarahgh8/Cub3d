#include "../include/cub3d.h"

int count_2d_array(char **arr)
{
    int count = 0;
    while(arr && arr[count])
        count++;
    return count;
}