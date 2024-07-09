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
            if (!ft_strcmp(fractal->name, "mandelbort"))
                create_mandelboart(x, y, fractal);
            else if (!ft_strcmp(fractal->name, "julia"))
                    create_julia(x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img, 0, 0);
}

static void initialize_var(int *add, double *result, double *pow, int *sign)
{
    *add = 10;
    *result = 0.0;
    *pow = 1.0;
    *sign = 1;
}

static int  is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

double map(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double  ft_strtod(char *str)
{
    double  result;
    int     sign;
    double  pow;
    int     add;

    initialize_var(&add, &result, &pow, &sign);
    while (*str && *str == ' ')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str)
    {
        if (*str == '.')
            (1) && (pow = 10, add = 1);
        (!is_digit(*str) && *str != '.') && (send_error("Error", EINVAL));
        (is_digit(*str)) && (result = result * add + ((*str - '0') / pow));
        (pow != 1 && *str != '.') && (pow *= 10);
        str++;
    }
    return (result * sign);
}
