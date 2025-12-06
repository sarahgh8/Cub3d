#include "../include/cub3d.h"

/**
 * @brief Counts the number of map content lines in the file info.
 * @param file_info The file information containing the content.
 * @return The number of map content lines.
 */
static int map_lines_count(t_file_info *file_info)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(file_info->content[i])
    {
        if(is_map_content(file_info->content[i]))
            count++;
        i++;
    }
    return count;
}

/** 
 * @brief Parses the map content from the file info and populates the map data.
 * @param file_info The file information containing the content.
 * @param map_data Pointer to the map data structure to populate.
 * @return 0 on success, 1 on failure.
 */
static int parse_map_content(t_file_info *file_info, t_map_data *map_data)
{
    int i;
    int j;
    int map_line_count;

    i = 0;
    j = 0;
    map_line_count = map_lines_count(file_info);
    map_data->map = (char **)malloc(sizeof(char *) * (map_line_count + 1));
    if(!map_data->map)
        return 1;
    i = 0;
    while(file_info->content[i])
    {
        if(is_map_content(file_info->content[i]))
        {
            map_data->map[j] = ft_strdup(file_info->content[i]);
            if(!map_data->map[j])
                return 1;
            j++;
        }
        i++;
    }
    map_data->map[j] = NULL;
    return 0;
}

/** 
 * @brief Finds the player's position in the map.
 * @param map The 2D array representing the map.
 * @return An array containing the player's row and column positions.
 */
int *find_player_position(char **map)
{
    int i;
    int j;
    int *player_pos; 
    
    i = 0;
    player_pos = malloc(sizeof(int) * 2);
    if(!player_pos)
        return NULL;
    player_pos[0] = -1;
    player_pos[1] = -1;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
            {
                player_pos[0] = i;
                player_pos[1] = j;
                return player_pos;
            }
            j++;
        }
        i++;
    }
    return player_pos;
}

/**
 * @brief Flood fill algorithm to check if map is closed.
 * @param map The map array.
 * @param visited 2D array to track visited cells.
 * @param x Current x position.
 * @param y Current y position.
 * @return 1 if map is open (invalid), 0 if closed (valid).
 */
static int flood_fill(char **map, int **visited, int x, int y, int max_height)
{
   if (y < 0 || y >= max_height || !map[y])
        return (1);
    if (x < 0 || x >= (int)ft_strlen(map[y]))
        return (1);
    if (map[y][x] == ' ' || map[y][x] == '\t')
        return (1);
    if (map[y][x] == '1' || visited[y][x])
        return (0);
    visited[y][x] = 1;
    if (flood_fill(map, visited, x + 1, y, max_height) ||
        flood_fill(map, visited, x - 1, y, max_height) ||
        flood_fill(map, visited, x, y + 1, max_height) ||
        flood_fill(map, visited, x, y - 1, max_height))
        return (1);
    
    return (0);
}

/** 
 * @brief Checks if the map is closed (surrounded by walls).
 * @param map_data Pointer to the map data structure.
 * @return 0 if the map is closed, 1 if it is open.
 */
int is_map_closed(t_map_data *map_data)
{
    int **visited;
    int i;
    int map_height;
    int result;
    
    i = 0;
    map_height = 0;
    while (map_data->map[map_height])
        map_height++;
    visited = malloc(sizeof(int *) * (map_height + 1));
    if (!visited)
        return (1);
    while (i < map_height)
    {
        visited[i] = ft_calloc(ft_strlen(map_data->map[i]) + 1, sizeof(int));
        if (!visited[i])
        {
            while (--i >= 0)
                free(visited[i]);
            free(visited);
            return (1);
        }
        i++;
    }
    result = flood_fill(map_data->map, visited, 
                map_data->player_pos[1], map_data->player_pos[0], map_height);
    i = 0;
    while (i < map_height)
        free(visited[i++]);
    free(visited);
    return (result);
}

/** 
 * @brief Validates the map content and populates the map data.
 * @param file_info The file information containing the content.
 * @param map_data Pointer to the map data structure to populate.
 * @return 0 on success, 1 on failure.
 */
int validate_map_content(t_file_info *file_info, t_map_data *map_data)
{
    if(parse_map_content(file_info, map_data))
        return 1;
    int *player_pos = find_player_position(map_data->map);
    if(player_pos[0] == -1 && player_pos[1] == -1)
        return 1;
    map_data->player_pos = player_pos;
    if(is_map_closed(map_data))
        return 1;
    return 0;
}