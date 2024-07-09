#include "fractol.h"


int    key_handler(int keysym, fractol_t *fractal)
{

    if (keysym == 53)
        destroy_display(fractal);
    return (0);
}

int     mouse_handler(int keysym, int x, int y, fractol_t *fractal)
{
    if (keysym == 4)
        fractal->zoom *= 0.3;
    if (keysym == 5)
        fractal->zoom /= 0.3;
    mlx_destroy_image(fractal->mlx_ptr, fractal->img);
    render(fractal);
    return (0);
}