#include "fractol.h"

void    create_julia(int x, int y, fractol_t *fractal)
{
    int         it;
    int         point_outside;
    double      temp;

    fractal->z.reel = REEL_LOWER_LIMIT + (x * (fabs(REEL_LOWER_LIMIT - REEL_UPPER_LIMIT) / WIDTH)) * fractal->zoom; 
    fractal->z.imaginary = IMAGINARY_UPPER_LIMIT - (y * (fabs(IMAGINARY_UPPER_LIMIT - IMAGINARY_LOWER_LIMIT) / HEIGHT)) * fractal->zoom;
    point_outside = 0;
    it = 0;
    while (it++ < MAX_ITERATION && !point_outside)
    {
        temp = fractal->z.reel * fractal->z.reel - fractal->z.imaginary * fractal->z.imaginary + fractal->c.reel;
        fractal->z.imaginary = 2 * fractal->z.reel * fractal->z.imaginary + fractal->c.imaginary + fractal->c.imaginary;
        fractal->z.reel = temp;
        if (sqrt(fractal->z.reel * fractal->z.reel + fractal->z.imaginary * fractal->z.imaginary) > 2.0)
            point_outside = 1;
    }
    if (!point_outside)
        color_pixel(fractal, x, y, 0x000000); 
    else
        color_pixel(fractal, x, y, 0x114ffc * it);

}
