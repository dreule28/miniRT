#include "mini_rt.h"

bool	ray_shooter(t_scene *scene, int pixel)
{
	(void)scene;
	(void)pixel;
	return(false);
}

void	ray_tracing(void *param)
{
	int count;
	int window_size;
	t_scene		*scene;
	uint32_t	*pixels;

	count = 0;
	scene = (t_scene *)param;
	pixels = (uint32_t *)scene->img->pixels;
	window_size = (int)(scene->img->width * scene->img->height);
	while (count < window_size)
	{
		if(ray_shooter(scene, pixels[count]))
			pixels[count] = get_rgba(255, 0, 0, 255);
		else
			pixels[count] = get_rgba(0, 0, 255, 255);
		count++;
	}
}
