#include "fractol.h"

void    image_initializer(fractol_t *fractal)
{
    fractal->img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
    if (!fractal->img)
    {
        destroy_display(fractal);
        send_error("Cant't Allocate", ENOMEM);
    }
    fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->depth, &fractal->endian);
}


void    render(fractol_t *fractal)
{
    int x;
    int y;

    y = 0;
    image_initializer(fractal);
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (!ft_strcmp(fractal->name, "mandelboart"))
                create_mandelboart(x, y, fractal);
            else if (!ft_strcmp(fractal->name, "julia"))
                    create_julia(x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img, 0, 0);
}
