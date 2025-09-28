#include "../include/cub3d.h"

int destroy_everything(t_prep *p)
{
    mlx_destroy_image(p->con, p->img);
    mlx_destroy_window(p->con, p->win);
    mlx_destroy_display(p->con);
    free(p->con);
    exit(0);
}

int mouse_interactions(int keycode, t_prep *p)
{
    if(keycode == 65307)
        destroy_everything(p);
    return 0;
}


int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
    t_prep p;
    p.con = mlx_init();
    if(!p.con)
        destroy_everything(&p);
    p.win = mlx_new_window(p.con, 500, 500, "test");
    p.img = mlx_new_image(p.con, 500, 500);
    mlx_hook(p.win, 2, 1L << 0, mouse_interactions, &p);
    mlx_hook(p.win, 17, 0, destroy_everything, &p);
    
    mlx_loop(p.con);
    (void)p.win;
    (void)p.img;
    return 0;
}