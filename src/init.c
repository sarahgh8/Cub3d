#include "../include/cub3d.h"

/** 
 * @brief Initializes the map flags to zero.
 * @param map_flags Pointer to the t_map_flags structure to initialize.
 * @return 0 on success.
 */
int init_flags(t_map_flags *map_flags)
{
    map_flags->north = 0;
    map_flags->south = 0;
    map_flags->east = 0;
    map_flags->west = 0;
    map_flags->floor = 0;
    map_flags->ceiling = 0;
    return 0;
}