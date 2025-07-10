#include "mini_rt.h"

void	ray_tracing(void *param)
{
	t_scene		*scene;
	uint32_t	*pixels;
	t_tuples	*ray_origin;
	double		wall_z;
	double		wall_size;
	double		pixel_size;
	double		half;
	double		world_y;
	double		world_x;
	t_tuples	*position;
	t_tuples	*direction;
	t_tuples	*normalized_dir;
	t_ray		*ray;
	t_sphere	*hit;
	int			pixel_index;

	int x, y;
	scene = (t_scene *)param;
	pixels = (uint32_t *)scene->img->pixels;
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
		// Convert canvas y to world y (flip coordinate)
		world_y = half - pixel_size * y;
		for (x = 0; x < canvas_pixels; x++)
		{
			// Convert canvas x to world x
			world_x = -half + pixel_size * x;
			// Target point on the wall
			position = init_point(world_x, world_y, wall_z);
			// Direction from ray origin to wall point
			direction = ftm_tup_subtract(position, ray_origin);
			normalized_dir = ftm_tup_norm(direction);
			// Create ray
			ray = init_ray(ray_origin, normalized_dir);
			// Test intersection with sphere
			hit = ray_hits_sphere(scene, ray);
			// Set pixel color
			pixel_index = y * canvas_pixels + x;
			if (pixel_index < (int)scene->img->width * (int)scene->img->height)
			{
				if (hit)
					pixels[pixel_index] = get_rgba(hit->rgb.r, hit->rgb.g,
							hit->rgb.b, 255);
				else
					pixels[pixel_index] = get_rgba(0, 0, 0, 255); // Black
			}
			// Cleanup
			free(position);
			free(direction);
			free(normalized_dir);
			free_ray(ray);
		}
	}
	free(ray_origin);
}
