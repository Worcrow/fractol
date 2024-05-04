#include "fractol_bonus.h"


int    key_handler(int keysym, fractol_t *fractal)
{

    if (keysym == XK_Escape)
        destroy_display(fractal);
    else if (keysym == XK_Left)
        fractal->shift_X -= (0.2 * fractal->zoom);
    else if (keysym == XK_Right)
        fractal->shift_X += (0.2 * fractal->zoom);
    else if (keysym == XK_Up)
        fractal->shift_Y += (0.2 * fractal->zoom);
    else if (keysym == XK_Down)
        fractal->shift_Y -= (0.2 * fractal->zoom);

    mlx_destroy_image(fractal->mlx_ptr, fractal->img);
    render(fractal);
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

int     mouse_motion_hook(int x, int y, fractol_t *fractal)
{
    fractal->c.reel = REEL_LOWER_LIMIT + (x * (fabs(REEL_LOWER_LIMIT - REEL_UPPER_LIMIT) / WIDTH)) * fractal->zoom;
    fractal->c.imaginary = IMAGINARY_UPPER_LIMIT - (y * (fabs(IMAGINARY_UPPER_LIMIT - IMAGINARY_LOWER_LIMIT) / HEIGHT)) * fractal->zoom;

    render(fractal);
    return (0); 
}
