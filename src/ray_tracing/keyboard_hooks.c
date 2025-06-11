#include "mini_rt.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;
	int i = -1;
	scene = (t_scene *)param;
	uint32_t	*pixels;
	pixels = (uint32_t *)scene->img->pixels;

	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(scene->mlx);
		if(keydata.key == MLX_KEY_1)
			while (++i < (int)(scene->img->width * scene->img->height))
				pixels[i] = create_rgba(255, 0, 0, 255);
	}
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_scene		*scene;
	static int			brightness = 127;
	int			i;
	uint32_t	*pixels;

	i = -1;
	scene = (t_scene *)param;
	(void)xdelta;

	pixels = (uint32_t *)scene->img->pixels;
	if (ydelta > 0 && brightness < 255)
		brightness += 5;
	else if (ydelta < 0 && brightness > 0)
		brightness -= 5;
	if (brightness > 255)
		brightness = 255;
	if (brightness < 0)
		brightness = 0;
	while (++i < (int)(scene->img->width * scene->img->height))
		pixels[i] = create_rgba(brightness, brightness, brightness, 255);
}
