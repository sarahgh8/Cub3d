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
    if (!tokens[0] || !tokens[1])
    {
        ft_2d_free(tokens);
        return 1;
    }
    if (!ft_strncmp(tokens[0], "NO", 2))
    {
        if (map_flags->north)
            return (ft_2d_free(tokens), 1);
        map_data->north = ft_strdup(tokens[1]);
        map_flags->north = 1;
    }
    else if (!ft_strncmp(tokens[0], "SO", 2))
    {
        if (map_flags->south)
            return (ft_2d_free(tokens), 1);
        map_data->south = ft_strdup(tokens[1]);
        map_flags->south = 1;
    }
    else if (!ft_strncmp(tokens[0], "WE", 2))
    {
        if (map_flags->west)
            return (ft_2d_free(tokens), 1);
        map_data->west = ft_strdup(tokens[1]);
        map_flags->west = 1;
    }
    else if (!ft_strncmp(tokens[0], "EA", 2))
    {
        if (map_flags->east)
            return (ft_2d_free(tokens), 1);
        map_data->east = ft_strdup(tokens[1]);
        map_flags->east = 1;
    }
    ft_2d_free(tokens);
    return 0;
}

static int validate_rgb(char *rgb_str)
{
    char **rgb;
    int i, val;

    rgb = ft_split(rgb_str, ',');
    if (!rgb)
        return 1;
    if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
    {
        ft_2d_free(rgb);
        return 1;
    }
    i = 0;
    while (i < 3)
    {
        val = ft_atoi(rgb[i]);
        if (val < 0 || val > 255)
        {
            ft_2d_free(rgb);
            return 1;
        }
        i++;
    }
    ft_2d_free(rgb);
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
    if (!tokens[0] || !tokens[1])
    {
        ft_2d_free(tokens);
        return 1;
    }
    if(!ft_strncmp(tokens[0], "F", 1))
    {
        if (map_flags->floor || validate_rgb(tokens[1]))
            return (ft_2d_free(tokens), 1);
        map_data->floor = ft_strdup(tokens[1]);
        map_flags->floor = 1;
    }
    else if(!ft_strncmp(tokens[0], "C", 1))
    {
        if (map_flags->ceiling || validate_rgb(tokens[1]))
            return (ft_2d_free(tokens), 1);
        map_data->ceiling = ft_strdup(tokens[1]);
        map_flags->ceiling = 1;
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
        else if(is_map_content(file_info->content[i]))
            return 1;
        i++;
    }
    if(map_flags->north != 1 && map_flags->south != 1 && map_flags->east != 1 &&
        map_flags->west != 1 && map_flags->floor != 1 && map_flags->ceiling != 1)
        return 1;
    if(validate_map_content(file_info, map_data))
        return 1;
    if(validate_textures_colors(map_data))
        return 1;
    return 0;
}
