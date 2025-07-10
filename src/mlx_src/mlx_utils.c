#include "mini_rt.h"

bool	init_mlx_window(t_scene *scene)
{
	scene->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
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
	if (mlx_image_to_window(scene->mlx, scene->img, 0, 0) < 0)
	{
		printf("Failed to display image\n");
		mlx_terminate(scene->mlx);
		return (false);
	}
	return (true);
}

void	print_terminal_update(t_scene *scene)
{
	printf("\033[4A");
	printf("\r\033[Kx : %.6f y : %.6f z : %.6f\n", scene->camera.pos.x,
		scene->camera.pos.y, scene->camera.pos.z);
	printf("camera orientation vecotr");
	printf("\r\033[Kx : %.6f y : %.6f z : %.6f\n",
		scene->camera.orientation_vector.x, scene->camera.orientation_vector.y,
		scene->camera.orientation_vector.z);
	printf("\033[4B");
	fflush(stdout);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (a << 24 | b << 16 | g << 8 | r);
}
