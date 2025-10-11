#include "../include/cub3d.h"

/**
 * @brief: This function checks the number of arguments passesd
 *          as well as the correct format of the file passed
 * @return: returns 0 if the argument is valid
 *              1 if there's an issue
 * @param argc: number of arguments
 * @param argv: the argument itself
 */
int check_argv(int argc, char **argv)
{
    int i;
    char *file_name;

    if(argc != 2)
        return 0;
    i = 0;
    file_name = argv[1];
    while(file_name[i])
    {
        if(i && file_name[i + 1] == '.')
        {
            i += 2;
            if(!ft_strncmp(&file_name[i], "cub", 3))
            {
                i += 3;
                if(!file_name[i])
                    return 1;
            }
        }
        i++;
    }
    return 0;
}

int check_file_content(char *file_name, t_file_content *data)
{
    int i;
    int fd;
    char *line;

    i = 0;
    line = NULL;
    fd = open(file_name, O_RDONLY, 0644);
    if(fd < 0)
        return 0;
    while((line = get_next_line(fd)))
    {
        data[i].content = line;
        if(!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
            || !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
            data[i].category = TEXTURE;
        else if(!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
            data[i].category = FC_COLORS;
        else
            data[i].category = MAP;
        i++;
    }
    close(fd);
    return 1;
}