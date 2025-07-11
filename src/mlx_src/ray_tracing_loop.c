#include "mini_rt.h"

void	ray_tracing(void *param)
{
	t_scene		*scene;
	t_tuples	*ray_origin;
	double		wall_z;
	double		wall_size;
	double		pixel_size;
	double		half;
	double		world_y;
	double		world_x;

	int			pixel_index;
	t_ray		*ray;
	int x, y;
	scene = (t_scene *)param;
	// Book's suggested values
	ray_origin = init_point(scene->camera.pos.x, scene->camera.pos.y,
			scene->camera.pos.z);
	

	wall_z = HEIGHT * 0.1;
	wall_size = WIDTH * 0.07;
	int canvas_pixels = HEIGHT; // Start small for testing
	pixel_size = wall_size / canvas_pixels;
	half = wall_size / 2;


	// Cast rays for each pixel
	for (y = 0; y < canvas_pixels; y++)
	{
		world_y = half - pixel_size * y;
		for (x = 0; x < canvas_pixels; x++)
		{
			world_x = -half + pixel_size * x;
			ray = setup_shooting_ray(ray_origin, world_x, world_y, wall_z);
			pixel_index = y * canvas_pixels + x;
			paint_pixel(scene, ray, pixel_index);
		}
	}
}

void	paint_pixel(t_scene *scene, t_ray *ray, int pixel_index)
{
	t_sphere	*hit;
	uint32_t	*pixels;

	pixels = (uint32_t *)scene->img->pixels;
	hit = ray_hits_sphere(scene, ray);
	if (pixel_index < (int)scene->img->width * (int)scene->img->height)
	{
		if (hit)
			pixels[pixel_index] = get_rgba(hit->rgb.r, hit->rgb.g,
					hit->rgb.b, 255);
		else
			pixels[pixel_index] = get_rgba(0, 0, 0, 255);
	}
}

t_ray	*setup_shooting_ray(t_tuples *ray_origin, double world_x, double world_y, double wall_z)
{	
	t_tuples	*position;
	t_tuples	*direction;
	t_tuples	*normalized_dir;
	t_ray	*ray;

	position = init_point(world_x, world_y, wall_z);
	direction = ftm_tup_subtract(position, ray_origin);
	normalized_dir = ftm_tup_norm(direction);
	ray = init_ray(ray_origin, normalized_dir);
	return(ray);
}