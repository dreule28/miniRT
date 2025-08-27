#include "mini_rt.h"

bool	intersect_shape(t_obj_node *curr, t_ray ray)
{
	if(curr->type == SPHERE) {
		return (intersect_sphere(curr, ray, *curr->data->sphere));
	}
	if(curr->type == PLANE) {
		return (intersect_plane(curr, ray));
	}
	if(curr->type == CYLINDER) {
		return (intersect_cylinder(curr, ray, *curr->data->cylinder));
	}
	if (curr->type == CUBE) {
		return (local_intersect(curr, ray));
	}
	return(false);
}

bool	intersec_to_obj(t_obj_node *curr, t_ray ray)
{
	t_ray	transformed_ray;
	t_m4	inv;

	transformed_ray = ray;
	ftm_m4_inversion(&inv, curr->matrix);
	transform_ray(&transformed_ray, ray, inv);
	return (intersect_shape(curr, transformed_ray));
}

t_obj_list	*intersect_to_list(t_scene *scene, t_ray *ray)
{
	t_obj_node	*curr;

	curr = scene->obj_list->head;
	while (curr)
	{
		if (!intersec_to_obj(curr, *ray)) {
			return (NULL);
		}
		if (!set_comp_to_obj(curr, ray)) {
			return (NULL);
		}
		curr = curr->next;
	}
	return (sort_obj_list(scene->obj_list));
}
