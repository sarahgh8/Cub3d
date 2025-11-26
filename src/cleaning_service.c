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
