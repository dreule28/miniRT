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
	ft_memset(scene->img->pixels, 128, scene->img->width * scene->img->height
		* sizeof(int32_t));
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
	t_sphere_node	*sphere;

	sphere = &scene->obj_list->head->data.sphere;
	printf("\n--- Camera Settings ---\n");
	printf("Camera position: (%.1f, %.1f, %.1f. %d)\n", scene->camera.pos.x,
		scene->camera.pos.y, scene->camera.pos.z, scene->camera.pos.w);
	printf("Looking direction: (%.1f, %.1f, %.1f)\n",
		scene->camera.orientation_vector.x, scene->camera.orientation_vector.y,
		scene->camera.orientation_vector.z);
	printf("Field of View: %.1d degrees\n", scene->camera.fov);
	printf("\n--- Sphere  ---\n");
	printf("Center point: (%.1f, %.1f, %.1f, %d)\n", sphere->pos.x,
		sphere->pos.y, sphere->pos.z, sphere->pos.w);
	printf("Diameter: %.1f\n", sphere->diameter);
	printf("Color: RGB(%.1f, %.1f, %.1f)\n\n", sphere->rgb.r, sphere->rgb.g,
		sphere->rgb.b);

	mlx_loop_hook(scene->mlx, &ray_tracing, scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	mlx_scroll_hook(scene->mlx, &scroll_hook, scene);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (a << 24 | b << 16 | g << 8 | r);
}
