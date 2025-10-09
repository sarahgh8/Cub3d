#include "../include/cub3d.h"

int check_file_name(t_map_file c)
{
    int i;

    i = 0;
    while(c.file_name[i])
    {
        if(c.file_name[i] && c.file_name[i + 1] == '.')
        {
            i += 2;
            if(!ft_strncmp(&c.file_name[i], "cub", 3) && !c.dir_texture[i + 1])
                return 1;
        }
        i++;
    }
    return 0;
}

void init_map_file(t_map_file *c, char *file_name)
{
    c->file_name = file_name;
}

int main(int argc, char **argv)
{
    if(argc != 2)
        return 1;
    t_map_file c;
    init_map_file(&c, argv[1]);
    if(check_file_name(c))
        printf("success\n");
    else
        printf("error\n");    
    return 0;
}
