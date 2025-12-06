#include "include/cub3d.h"

int main(void)
{
    char *test1 = "20,20,20";
    char *test2 = "200,200,200";
    char **rgb;
    int i;

    printf("Testing: %s\n", test1);
    rgb = ft_split(test1, ',');
    if (!rgb)
        printf("ft_split returned NULL\n");
    else
    {
        i = 0;
        while (rgb[i])
        {
            printf("  [%d] = '%s' -> %d\n", i, rgb[i], ft_atoi(rgb[i]));
            i++;
        }
        printf("  Count: %d\n", i);
    }
    return 0;
}
