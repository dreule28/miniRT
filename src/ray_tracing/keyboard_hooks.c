#include "mini_rt.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;
	// int i;
	// uint32_t	*pixels;

	// pixels = (uint32_t *)scene->img->pixels;
	// i = -1;
	scene = (t_scene *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(scene->mlx);
		// if(keydata.key == MLX_KEY_1)
		// {
		// 	while (++i < (int)(scene->img->width * scene->img->height))
		// 	{
		// 		scene->current_r = 255;
		// 		scene->current_g = 0;
		// 		scene->current_b = 0;
		// 		scene->brightness = 255;
		// 		pixels[i] = get_rgba(scene->current_r, scene->current_g, scene->current_b, scene->brightness);
		// 	}
		// }
	}
}


void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_scene		*scene;

	scene = (t_scene *)param;
	(void)xdelta;
	(void)ydelta;
}
