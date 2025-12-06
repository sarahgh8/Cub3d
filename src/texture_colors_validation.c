#include "../include/cub3d.h"

static int validate_color(char *color_str)
{
    int i;
    char **rgb;

    i = 0;
    rgb = ft_split(color_str, ',');
    if(!rgb)
        return 1;
    if(count_2d_array(rgb) != 3)
    {
        ft_2d_free(rgb);
        return 1;
    }
    while(rgb[i])
    {
        int value = ft_atoi(rgb[i]);
        if(value < 0 || value > 255)
        {
            ft_2d_free(rgb);
            return 1;
        }
        i++;
    }
    ft_2d_free(rgb);
    return 0;
}

static int check_extension(char *texture_path)
{
    int len;

    len = ft_strlen(texture_path);
    if(len < 4)
        return 1;
    if(ft_strncmp(&texture_path[len - 4], ".xpm", 4) != 0)
        return 1;
    return 0;
}

static int validate_texture_path(char *texture_path)
{
    if(check_extension(texture_path))
        return 1;
    return 0;
}
static int validate_floor_ceiling(char *floor_color, char *ceiling_color)
{
    if(validate_color(floor_color))
        return 1;
    if(validate_color(ceiling_color))
        return 1;
    return 0;
}
int validate_textures_colors(t_map_data *map_data)
{
    if(validate_floor_ceiling(map_data->floor, map_data->ceiling))
    {
        printf("Error\nInvalid floor or ceiling color format.\n");
        return 1;
    }
    if(validate_texture_path(map_data->north))
    {
        printf("Error\nInvalid north texture path.\n");
        return 1;
    }
    return 0;
}