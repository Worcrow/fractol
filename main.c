#include "fractol.h"

void    window_init(fractol_t *fractal)
{
    fractal->mlx_ptr = mlx_init();
    if (!fractal->mlx_ptr)
        send_error("Can't Allocate", ENOMEM);
    fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, fractal->name);
    if (!fractal->win_ptr)
    {
        free(fractal->mlx_ptr);
        send_error("Can't Allocate", ENOMEM);
    }
    fractal->zoom = 1;
}

int main(int argc, char *argv[])
{
    fractol_t   fractol;

    if (argc >= 2)
    {
        if (!ft_strcmp(argv[1], "mandelbort"))
            ft_strcpy(fractol.name, argv[1]);
        else if (!ft_strcmp(argv[1], "julia") && argc == 4)
        {
            ft_strcpy(fractol.name, argv[1]);
            fractol.c.reel = ft_strtod(argv[2]);
            fractol.c.imaginary = ft_strtod(argv[3]);
        }
        else
            send_error("Supported Argument: { \"mandelbort\" | \"julia\" }", EINVAL);
        window_init(&fractol);
        render(&fractol);
        mlx_key_hook(fractol.win_ptr, key_handler, &fractol);
        mlx_mouse_hook(fractol.win_ptr, mouse_handler, &fractol);
        mlx_hook(fractol.win_ptr, 17, 1L<<17, destroy_display, &fractol);
        mlx_loop(fractol.mlx_ptr);
    }
    else
        send_error("Usage: ./fractol mandelbort | ./fractol julia", EINVAL);

    return (0);
}
