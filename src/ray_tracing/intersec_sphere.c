#include "mini_rt.h"

bool	setup_intersec_sphere(t_scene *scene, t_obj_node *curr, t_ray *ray)
{
	double	*t;
	t_ray	*transformed_ray;
	t_m4	*inv;

	(void)scene;
	transformed_ray = ray;
	if (curr->data->sphere->matrix)
	{
		inv = ftm_m4_inversion(curr->data->sphere->matrix);
		if (inv)
		{
			transformed_ray = transform_ray(ray, inv);
			free(inv);
		}
	}
	t = intersect_sphere(transformed_ray, curr->data->sphere);
	if (transformed_ray != ray)
		free_ray(transformed_ray);
	curr->t = t;
	return (true);
}
