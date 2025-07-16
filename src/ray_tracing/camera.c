#include "mini_rt.h"

t_ray	*ray_for_pixel(t_camera *camera, double px, double py)
{
	double xoffset;
	double yoffset;

	xoffset = (px + 0.5) * camera->pixel_size;
	yoffset = (py + 0.5) * camera->pixel_size;
	
}