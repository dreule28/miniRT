#include "mini_rt.h"

void	init_ray_params(t_ray_params *ray_params, t_scene *scene, t_ray *ray,
		t_m4 inv)
{
	ray_params->scene = *scene;
	ray_params->ray = *ray;
	ray_params->inv = inv;
}

void	get_aa_color(t_ray_params *ray_params, t_rgb *acc)
{
	t_rgb	sample;

	shade_single_ray(&ray_params->scene, &ray_params->ray, &sample);
	acc->r += sample.r;
	acc->g += sample.g;
	acc->b += sample.b;
}

void	normal_rendering(t_ray_params *ray_params, int x, int y)
{
	ray_for_pixel(ray_params, x, y);
	paint_pixel(&ray_params->scene, &ray_params->ray, y
		* ray_params->scene.camera.hsize + x);
}

void	swap_values(double t0, double t1)
{
	double	tmp;

	tmp = t0;
	t0 = t1;
	t1 = tmp;
}
