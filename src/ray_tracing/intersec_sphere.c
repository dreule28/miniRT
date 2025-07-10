#include "mini_rt.h"

t_sphere	*ray_hits_sphere(t_scene *scene, t_ray *ray)
{
	t_obj_node	*curr;
	t_ray		*transformed_ray;
	t_m4		*inv;
	double		*t;

	curr = scene->obj_list->head;
	while (curr)
	{
		if (curr->type == SPHERE)
		{
			// Apply transformations if any
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
			if (t)
			{
				free(t);
				return (curr->data->sphere);
			}
		}
		curr = curr->next;
	}
	return (NULL);
}
