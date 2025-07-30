#include "mini_rt.h"

double	*intersect_shape(t_obj_node *curr, t_ray *ray)
{
	double	*intersection;

	if (curr->type == SPHERE)
		intersection = intersect_sphere(ray, curr->data->sphere);
	if (curr->type == PLANE)
		intersection = intersect_plane(ray, curr->data->plane);
	return (intersection);
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
			if (!transformed_ray)
				return (false);
			free_matrix_m4(inv);
		}
	}
	t = intersect_shape(curr, transformed_ray);
	if (transformed_ray != ray)
		free_ray(transformed_ray);
	curr->t = t;
	return (true);
}

void	add_inter_sorted(t_obj_list *list, t_obj_node *new_intersection)
{
	t_obj_node	*curr;

	if (!list->head || new_intersection->t[0] < list->head->t[0])
	{
		new_intersection->next = list->head;
		list->head = new_intersection;
		if (!list->tail)
			list->tail = new_intersection;
		return ;
	}
	curr = list->head;
	while (curr->next && curr->next->t[0] < new_intersection->t[0])
		curr = curr->next;
	new_intersection->next = curr->next;
	curr->next = new_intersection;
	if (!new_intersection->next)
		list->tail = new_intersection;
}

void	handle_inter_node(t_obj_list *intersections, t_obj_node *curr)
{
	t_obj_node	*inter1;
	t_obj_node	*inter2;

	if (curr->t[0] > 0)
	{
		inter1 = create_inter_node(curr, curr->t[0]);
		if (inter1)
			add_inter_sorted(intersections, inter1);
	}
	if (curr->t[1] > 0 && fabs(curr->t[1] - curr->t[0]) > DBL_EPSILON)
	{
		inter2 = create_inter_node(curr, curr->t[1]);
		if (inter2)
			add_inter_sorted(intersections, inter2);
	}
}

t_obj_list	*intersect_to_list(t_scene *scene, t_ray *ray)
{
	t_obj_node	*curr;
	t_obj_list	*intersections;

	curr = scene->obj_list->head;
	intersections = ft_calloc(sizeof(t_obj_list), 1);
	if (!intersections)
		return (NULL);
	while (curr)
	{
		if (!intersec_to_obj(scene, curr, ray))
			return (free(intersections), NULL);
		if (curr->t)
			handle_inter_node(intersections, curr);
		curr = curr->next;
	}
	curr = intersections->head;
	while (curr)
	{
		if (!set_comp_to_obj(curr, ray, intersections))
			return (NULL);
		curr = curr->next;
	}
	return (intersections);
}
