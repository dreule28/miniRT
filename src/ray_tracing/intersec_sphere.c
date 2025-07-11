#include "mini_rt.h"

bool	setup_intersec_sphere(t_scene *scene, t_obj_node *curr)
{
	t_ray	*ray;
	t_m4	*inv;

	ray = init_ray(copy_point(&scene->camera.pos),
			copy_vector(&scene->camera.orientation_vector));
	if (!ray)
		return (false);
	set_transform(curr->data->sphere, ftm_translation(init_identity(),
			init_vector(5, 0, 0)));
	inv = ftm_m4_inversion(curr->data->sphere->matrix);
	ray = transform_ray(ray, inv);
	curr->t = intersect_sphere(ray, curr->data->sphere);
	free(ray);
	return (true);
}

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
