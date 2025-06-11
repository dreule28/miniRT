#include "mini_rt.h"

bool	init_mlx_window(t_scene *scene)
{
	scene->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	if (!scene->mlx)
	{
		printf("Failed to initialize MLX\n");
		return (false);
	}
	scene->img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	if (!scene->img)
	{
		printf("Failed to create image\n");
		mlx_terminate(scene->mlx);
		return (false);
	}
	ft_memset(scene->img->pixels, 128, scene->img->width * scene->img->height * sizeof(int32_t));
	if (mlx_image_to_window(scene->mlx, scene->img, 0, 0) < 0)
	{
		printf("Failed to display image\n");
		mlx_terminate(scene->mlx);
		return (false);
	}
	return (true);
}

void	mlx_custom_hooks(t_scene *scene)
{
	mlx_loop_hook(scene->mlx, &ray_tracing, scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	mlx_scroll_hook(scene->mlx, &scroll_hook, scene);
}

uint32_t create_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}