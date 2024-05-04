#ifndef FRACTOL_BONUS_H
#define FRACTOL_BONUS_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include <X11/keysym.h>

#define HEIGHT 800
#define WIDTH 800
#define MAX_ITERATION 50
#define REEL_LOWER_LIMIT -1.5
#define REEL_UPPER_LIMIT 0.5 
#define IMAGINARY_LOWER_LIMIT -1.0
#define IMAGINARY_UPPER_LIMIT 1.0

typedef struct complex {
    double  reel;
    double  imaginary;
}   complex_t;

typedef struct fractal {
    void        *mlx_ptr;
    void        *win_ptr;
    void        *img;
    char        *addr;
    int         depth;
    int         bits_per_pixel;
    int         endian;
    complex_t   z;
    complex_t   c;
    char        name[12];
    double      shift_X;
    double      shift_Y;
    double      zoom;
}   fractol_t;


int ft_strcmp(char *str1, char *str2);
void   ft_strcpy(char *dest, char *src);
void    send_error(char *message, int err);
void    render(fractol_t *fractal);
void    image_initializer(fractol_t *fractal);
void    create_mandelboart(int x, int y, fractol_t *fractal);
void  color_pixel(fractol_t *fractal, int x, int y, int color);
int    destroy_display(fractol_t *fractal);
int    key_handler(int keysym, fractol_t *fractal);
int     mouse_handler(int keysym, int x, int y, fractol_t *fractal);
void    create_julia(int x, int y, fractol_t *fractal);
int     mouse_motion_hook(int x, int y, fractol_t *fractal);

#endif
