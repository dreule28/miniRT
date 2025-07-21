#include "mini_rt.h"

t_tuples	*reflect(t_tuples *in, t_tuples *normal)
{
	t_tuples	*result;
	t_tuples	*scaled_normal;
	double		dot_product;

	dot_product = 2 * ftm_tup_dot(in, normal);
	scaled_normal = ftm_tup_mult(normal, dot_product);
	if (!scaled_normal)
		return (NULL);
	result = ftm_tup_subtract(in, scaled_normal);
	free(scaled_normal);
	return (result);
}

t_light	*point_light(t_tuples position, t_rgb intensity)
{
	t_light	*light;

	light = ft_calloc(sizeof(t_light), 1);
	if (!light)
		return (NULL);
	light->pos = position;
	light->rgb = intensity;
	light->intensity = 1;
	light->next = NULL;
	return (light);
}

t_material	get_material(void)
{
	t_material	material;

	material.rgb.r = 1;
	material.rgb.g = 1;
	material.rgb.b = 1;
	material.ambient = 0.1;
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	material.reflective = 0;
	return (material);
}

t_rgb	*shade_hit(t_scene *scene, t_computations *comps, t_light *curr)
{
	comps->in_shadow = is_shadowed(scene, comps->over_point);
	return (lighting(scene, comps, curr));
}

t_material *get_object_material(t_obj_node *curr)
{
    if (curr->type == SPHERE)
        return &curr->data->sphere->material;
    else if (curr->type == PLANE)
        return &curr->data->plane->material;
    else if (curr->type == CYLINDER)
        return &curr->data->cylinder->material;
    return NULL;
}

t_rgb	*reflected_color(t_scene *scene, t_obj_node *curr)
{
	t_rgb		*color;
	t_ray		*reflected_ray;
	t_rgb		*finale_reflected;
	t_material	*material;
	t_obj_node	*hit_obj;

	material = &curr->d;
	if (material->reflective == 0)
	{
		printf("reflective is zero\n");
		return (init_rgb(0, 0, 0));
	}
	// Debug: print reflection ray info
	printf("Reflection ray origin: (%f, %f, %f)\n", curr->comp->over_point->x, curr->comp->over_point->y, curr->comp->over_point->z);
	printf("Reflection ray direction: (%f, %f, %f)\n", curr->comp->reflectv->x, curr->comp->reflectv->y, curr->comp->reflectv->z);

	reflected_ray = init_ray(curr->comp->over_point, curr->comp->reflectv);

	intersect_to_list(scene, reflected_ray);
	if (!scene->obj_list->head || !scene->obj_list->head->t)
	{
		printf("No intersections found for reflected ray\n");
		free_ray(reflected_ray);
		return (init_rgb(0, 0, 0));
	}
	hit_obj = scene->obj_list->head;
	double closest_t = (hit_obj->t[0] > 0) ? hit_obj->t[0] : hit_obj->t[1];
	if (closest_t <= 0)
	{
		printf("All intersections behind ray origin\n");
		free_ray(reflected_ray);
		return (init_rgb(0, 0, 0));
	}
	printf("Reflected ray hit object at t = %f\n", scene->obj_list->head->t[0]);
		// Debug: check if the hit object has proper material and lighting setup
	// printf("Hit object material - ambient: %f, diffuse: %f, specular: %f\n", hit_obj->material.ambient, hit_obj->material.diffuse, hit_obj->material.specular);
	// printf("Hit object RGB: (%f, %f, %f)\n", hit_obj->material.rgb.r, hit_obj->material.rgb.g, hit_obj->material.rgb.b);

	t_obj_list *original_list = scene->obj_list;

	color = get_shaded_with_shadows(scene, scene->obj_list->head);

	scene->obj_list = original_list;
	printf("Shaded color: R=%f, G=%f, B=%f\n", color->r, color->g, color->b);
	printf("Reflective value: %f\n", material->reflective);
	finale_reflected = ftm_rgb_mult(color, material->reflective);
	printf("Final reflected color: R=%f, G=%f, B=%f\n",
		finale_reflected->r, finale_reflected->g, finale_reflected->b);
	free_ray(reflected_ray);
	free(color);
	return (finale_reflected);
}
