#include "../include/cub3d.h"

/**
 * @brief Checks if a line consists entirely of whitespace characters.
 * @param line The line to check.
 * @return 1 if the line is all whitespace, 0 otherwise.
 */
static int all_space(char *line)
{
    while (*line)
    {
        if (ft_isalnum(*line))
            return 0;
        line++;
    }
    return 1;
}

/** 
 * @brief Counts the number of non-empty lines in a file.
 * @param filename The name of the file to read.
 * @return The number of non-empty lines, or -1 on error.
 */
static int how_many_lines(char *filename)
{
    char *line;
    int fd;
    int count = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return -1;

    while ((line = get_next_line(fd)))
    {
        if (!all_space(line))
            count++;
        free(line);
    }
    close(fd);
    return count;
}

/** 
 * @brief Reads the content of a file into the provided t_file_info structure.
 * @param file_info Pointer to the t_file_info structure to populate.
 * @return 0 on success, 1 on failure.
 */
static int move_content(t_file_info *file_info)
{
    char *line;
    int fd; 
    
    fd = open(file_info->filename, O_RDONLY);
    if (fd < 0)
        return 1;
    int i = 0;
    while ((line = get_next_line(fd)))
    {
        if(all_space(line))
        {
            free(line);
            continue;
        }
        file_info->content[i] = ft_strdup(line);
        free(line);
        i++;
    }
    file_info->content[i] = NULL;
    close(fd);
    return 0;
}

/** 
 * @brief Starts parsing the file content and populates the t_file_info structure.
 * @param argv The command line arguments.
 * @param file_info Pointer to the t_file_info structure to populate.
 * @return 0 on success, 1 on failure.
 */
int start_parse_file_content(char **argv, t_file_info *file_info)
{
    int count_lines;

    count_lines = how_many_lines(argv[1]);
    file_info->filename = argv[1];
    file_info->content = malloc(sizeof(char *) * (count_lines + 1));
    if (!file_info->content)
        return 1;
    if (move_content(file_info))
        return 1;
    return 0;
}