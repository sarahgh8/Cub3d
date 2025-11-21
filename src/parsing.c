#include "../include/cub3d.h"

int all_space(char *line)
{
    while (*line)
    {
        if (ft_isalnum(*line))
            return 0;
        line++;
    }
    return 1;
}

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

int start_parse_file_content(char **argv, int argc, t_file_info *file_info)
{
    int i;
    int count_lines;
    int bytes_read;
    char *line;

    i = 0;
    count_lines = 0;
    bytes_read = -1;
    if (!file_info)
        return 1;
    file_info->filename = argv[1];

    count_lines = how_many_lines(file_info->filename);
    file_info->content = malloc(sizeof(char *) * (count_lines + 1));
    int fd = open(file_info->filename, O_RDONLY);
    if (!file_info->content)
        return 1;
    while((line = get_next_line(fd)))
    {
        file_info->content[i] = line;
        printf("%s", file_info->content[i]);
        free(line);
        i++;
    }
    file_info->content[i] = NULL;
    close(fd);
    (void)argc;
    return 0;
}