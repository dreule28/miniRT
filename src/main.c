#include "mini_rt.h"

// int create_color(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }


// void clear_image(mlx_image_t *img)
// {
//     int x, y;

//     y = 0;
//     while (y < HEIGHT)
//     {
//         x = 0;
//         while (x < WIDTH)
//         {
//             mlx_put_pixel(img, x, y, create_color(0, 0, 20, 255));
//             x++;
//         }
//         y++;
//     }
// }



int main(int argc, char **argv)
{
	// t_scene		*scene;

	(void)argc;
	(void)argv;
	// if(!parsing(scene))
	// {
	// 	ft_putstr_fd(2, "Error\nparsing error");
	// 	return(1);
	// }
    // scene->mlx = mlx_init(WIDTH, HEIGHT, argv[1], true);
    // if (!scene->mlx)
    // {
    //     printf("Failed to initialize MLX\n");
    //     return (1);
    // }

    // scene->img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
    // if (!scene->img)
    // {
    //     printf("Failed to create image\n");
    //     mlx_terminate(scene->mlx);
    //     return (1);
    // }

    // if (mlx_image_to_window(scene->mlx, scene->img, 0, 0) < 0)
    // {
    //     printf("Failed to display image\n");
    //     mlx_terminate(scene->mlx);
    //     return (1);
    // }

    // mlx_loop_hook(scene->mlx, ray_shooter, &scene);
	// mlx_loop(scene->mlx);

    // mlx_terminate(scene->mlx);
	// close_scene(scene);
    return (0);
}
