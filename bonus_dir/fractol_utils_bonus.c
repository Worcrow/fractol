#include "fractol_bonus.h"

void    to_lower(char *str)
{
    int i;

    i = 0;
    while (str && str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        ++i;
    }
}


int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    to_lower(str1);
    while (str1 && str2 && str1[i] == str2[i] && str1[i] && str2[i])
    {
        ++i;
    }
    return (str1[i] - str2[i]);
}

void   ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src && src[i] != '\0')
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

void    send_error(char *message, int err)
{
    int errno;
    int i;

    i = 0;
    errno = err;
    while (message && message[i] != '\0')
    {
        write(2, message + i, 1);
        ++i;
    }
    write(2, ": ", 2);
    perror(NULL);
    exit(errno);
}

void  color_pixel(fractol_t *fractal, int x, int y, int color)
{
   char *pixel_to_color;

    pixel_to_color = fractal->addr + (y * fractal->depth + (x * fractal->bits_per_pixel / 8));
    *(unsigned int *)pixel_to_color = color;
}

int    destroy_display(fractol_t *fractal)
{
    if (fractal->img)
    {
        mlx_destroy_image(fractal->mlx_ptr, fractal->img);
        fractal->img = NULL;
    }
    if (fractal->win_ptr)
    {
        mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
        fractal->win_ptr = NULL;
    }
    if (fractal->mlx_ptr)
    {
        //mlx_destroy_display(fractal->mlx_ptr);
        free(fractal->mlx_ptr);
        fractal->mlx_ptr = NULL;
    }
    exit(0);
    return (0);
}
