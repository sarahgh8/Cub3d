#include "../include/cub3d.h"

/** 
 * @brief Starts parsing the file content to extract map data.
 * @param file_info Pointer to the t_file_info structure containing file content.
 * @param map_data Pointer to the t_map_data structure to populate.
 * @param map_flags Pointer to the t_map_flags structure to track parsed elements.
 */
static int parse_direction_texture(char *line, t_map_data *map_data, t_map_flags *map_flags)
{
    char **tokens;

    tokens = ft_split(line, ' ');
    if (tokens[0] && tokens[1])
    {
        if (!ft_strncmp(tokens[0], "NO", 2) && !map_flags->north)
        {
            map_data->north = ft_strdup(tokens[1]);
            map_flags->north = 1;
        }
        else if (!ft_strncmp(tokens[0], "SO", 2) && !map_flags->south)
        {
            map_data->south = ft_strdup(tokens[1]);
            map_flags->south = 1;
        }
        else if (!ft_strncmp(tokens[0], "WE", 2) && !map_flags->west)
        {
            map_data->west = ft_strdup(tokens[1]);
            map_flags->west = 1;
        }
        else if (!ft_strncmp(tokens[0], "EA", 2) && !map_flags->east)
        {
            map_data->east = ft_strdup(tokens[1]);
            map_flags->east = 1;
        }
    }
    ft_2d_free(tokens);
    return 0;
}

/** 
 * @brief Parses floor and ceiling color information from a line.
 * @param line The line containing floor or ceiling color data.
 * @param map_data Pointer to the t_map_data structure to populate.
 * @param map_flags Pointer to the t_map_flags structure to track parsed elements.
 */
static int parse_floor_ceiling_color(char *line, t_map_data *map_data, t_map_flags *map_flags)
{
    char **tokens;

    tokens = ft_split(line, ' ');
    if(tokens[0] && tokens[1])
    {
        if(!ft_strncmp(tokens[0], "F", 1) && !map_flags->floor)
        {
            map_data->floor = ft_strdup(tokens[1]);
            map_flags->floor = 1;
        }
        else if(!ft_strncmp(tokens[0], "C", 1) && !map_flags->ceiling)
        {
            map_data->ceiling = ft_strdup(tokens[1]);
            map_flags->ceiling = 1;
        }
    }
    ft_2d_free(tokens);
    return 0;
}

/** 
 * @brief Parses the file content to extract map data.
 * @param file_info Pointer to the t_file_info structure containing file content.
 * @param map_data Pointer to the t_map_data structure to populate.
 * @param map_flags Pointer to the t_map_flags structure to track parsed elements.
 * @return 0 on success, 1 on failure.
 */
int start_parse_file_content(t_file_info *file_info, t_map_data *map_data, t_map_flags *map_flags)
{
    int i;

    i = 0;
    while(file_info->content[i])
    {
        if(!ft_strncmp(file_info->content[i], "NO", 2) || 
           !ft_strncmp(file_info->content[i], "SO", 2) ||
           !ft_strncmp(file_info->content[i], "WE", 2) ||
            !ft_strncmp(file_info->content[i], "EA", 2))
            parse_direction_texture(file_info->content[i], map_data, map_flags);
        else if(!ft_strncmp(file_info->content[i], "F", 1) ||
                !ft_strncmp(file_info->content[i], "C", 1))
            parse_floor_ceiling_color(file_info->content[i], map_data, map_flags);
        i++;
    }
    if(!map_flags->north || !map_flags->south || !map_flags->east ||
       !map_flags->west || !map_flags->floor || !map_flags->ceiling)
        return 1;
    if(validate_map_content(file_info, map_data))
        return 1;
    return 0;
}
