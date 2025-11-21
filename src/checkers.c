#include "../include/cub3d.h"

/** 
* @brief Checks the format of the given filename [filename.cub].
* @param filename The name of the file to check.
* @return 0 if the format is valid, 1 otherwise.
*/
int check_filename_format(char *filename)
{
    int i;

    i = 0;
    while(filename[i])
    {
        if(filename[0] == '.')
            return 1;
        if(filename[i] == '.')
        {
            i++;
            if (ft_strncmp(&filename[i], "cub", 3) == 0 && !filename[i + 3])
                return 0;
            else
                return 1;
        }
        i++;
    }
    return 1;
}

/**
 * @brief Checks the validity of the command line arguments.
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return 0 if the arguments are valid, 1 otherwise.
 */
int check_arguments(int argc, char **argv)
{
    if(argc != 2)
        return 1;
    if(check_filename_format(argv[1]))
        return 1;
    return 0;
}
