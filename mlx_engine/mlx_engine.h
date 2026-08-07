#ifndef MLX_ENGINE_H
#define MLX_ENGINE_H


typedef struct s_mlx
{
    void    *mlx;
    void    *window;
    void    *image;

    char    *addr;

    int     bits_per_pixel;
    int     line_length;
    int     endian;

} t_mlx;






#endif

