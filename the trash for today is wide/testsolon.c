#include "mlx.h"

#include <unistd.h>
#include <stdio.h>
//cc -I testsolon.c -L /usr/local/lib -lmlx -framework OpenGL -framework OpenGL -framework AppKit testsolon.c

int main()
{
    int nu = 50 ;
    int number = 50 ;
    void *ptr_check ;
    void *window_ptr ;
    void *imgptr ;
    ptr_check = mlx_init();
    window_ptr = mlx_new_window(ptr_check , 1024 , 900 , "mlx mohammead");
    mlx_pixel_put(ptr_check , window_ptr , 50, 50 ,0xFF0000 );
    mlx_pixel_put(ptr_check , window_ptr , 60, 60 ,0xFF0000 );
    mlx_pixel_put(ptr_check , window_ptr , 70, 70 ,0xFF6000 );
    imgptr = mlx_xpm_file_to_image(ptr_check , "hh.xpm" , &nu , &number );
    mlx_put_image_to_window(ptr_check , window_ptr , imgptr , 50 , 50);
    mlx_loop(ptr_check);
}