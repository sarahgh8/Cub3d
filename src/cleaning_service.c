#include "../include/cub3d.h"

/** 
 * @brief Cleans up the memory allocated for the t_file_info structure.
 * @param file_info Pointer to the t_file_info structure to clean.
 */
void clean_file_info(t_file_info *file_info)
{
    if (file_info->content)
    {
        int i = 0;
        while (file_info->content[i])
        {
            free(file_info->content[i]);
            i++;
        }
        free(file_info->content);
    }
}

/** 
 * @brief Cleans up the memory allocated for the t_map_data structure.
 * @param map_data Pointer to the t_map_data structure to clean.
 */
void clean_map_data(t_map_data *map_data)
{
    if (map_data->north)
        free(map_data->north);
    if (map_data->south)
        free(map_data->south);
    if (map_data->east)
        free(map_data->east);
    if (map_data->west)
        free(map_data->west);
    if (map_data->floor)
        free(map_data->floor);
    if (map_data->ceiling)
        free(map_data->ceiling);
    if (map_data->map)
        ft_2d_free(map_data->map);
}
