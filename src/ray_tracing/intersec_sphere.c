#include "mini_rt.h"

double *intersect_shape(t_obj_node *curr, t_ray *ray)
{
	double *intersection;

	if(curr->type == SPHERE)
		intersection = intersect_sphere(ray, curr->data->sphere);
	if(curr->type == PLANE)
		intersection = intersect_plane(ray, curr->data->plane);
	return(intersection);
}

bool	intersec_to_obj(t_scene *scene, t_obj_node *curr, t_ray *ray)
{
	double	*t;
	t_ray	*transformed_ray;
	t_m4	*inv;

	(void)scene;
	transformed_ray = ray;
	if (curr->matrix)
	{
		inv = ftm_m4_inversion(curr->matrix);
		if (inv)
		{
			transformed_ray = transform_ray(ray, inv);
			free_matrix_m4(inv);
		}
	}
	t = intersect_shape(curr, ray);
	if (transformed_ray != ray)
		free_ray(transformed_ray);
	curr->t = t;
	return (true);
}
