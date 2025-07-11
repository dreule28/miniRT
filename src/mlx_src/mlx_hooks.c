#include "mini_rt.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(scene->mlx);
	// if (keydata.key == MLX_KEY_W)
	// 	scene->camera.movement.key_w = (keydata.action != MLX_RELEASE);
	// if (keydata.key == MLX_KEY_S)
	// 	scene->camera.movement.key_s = (keydata.action != MLX_RELEASE);
	// if (keydata.key == MLX_KEY_A)
	// 	scene->camera.movement.key_a = (keydata.action != MLX_RELEASE);
	// if (keydata.key == MLX_KEY_D)
	// 	scene->camera.movement.key_d = (keydata.action != MLX_RELEASE);
}

void	mlx_custom_hooks(t_scene *scene)
{
	mlx_loop_hook(scene->mlx, &ray_tracing, scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	// mlx_scroll_hook(scene->mlx, &scroll_hook, scene);
	// mlx_loop_hook(scene->mlx, &update_camera, scene);
	// mlx_set_cursor_mode(scene->mlx, MLX_MOUSE_DISABLED);
	// mlx_cursor_hook(scene->mlx, &cursor_hook, scene);
}

void	update_camera(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	print_terminal_update(scene);
	if (scene->camera.movement.key_w)
		scene->camera.pos.y += 0.08;
	if (scene->camera.movement.key_s)
		scene->camera.pos.y -= 0.08;
	if (scene->camera.movement.key_a)
		scene->camera.pos.x -= 0.08;
	if (scene->camera.movement.key_d)
		scene->camera.pos.x += 0.08;
}

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_scene		*scene;
	double		center_x;
	double		center_y;
	uint32_t	*pixels;

	scene = (t_scene *)param;
	pixels = (uint32_t *)scene->img->pixels;
	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	scene->camera.orientation_vector.x += (xpos - center_x) * 0.0001;
	scene->camera.orientation_vector.y += (ypos - center_y) * 0.001;
	mlx_set_mouse_pos(scene->mlx, center_x, center_y);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_scene		*scene;
	uint32_t	*pixels;

	(void)xdelta;
	scene = (t_scene *)param;
	pixels = (uint32_t *)scene->img->pixels;
	if (ydelta > 0)
		scene->camera.pos.z += 0.2;
	else if (ydelta < 0)
		scene->camera.pos.z -= 0.2;
}
