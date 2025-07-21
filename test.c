// Fixed reflection.c with proper state management and debugging

#include "mini_rt.h"

t_rgb	*reflected_color(t_scene *scene, t_obj_node *curr)
{
	t_rgb		*color;
	t_ray		*reflected_ray;
	t_rgb		*finale_reflected;
	t_material	*material;
	t_obj_list	*new_list;
	t_obj_node	*hit_obj;

	material = &curr->material;
	if (material->reflective == 0)
	{
		printf("reflective is zero\n");
		return (init_rgb(0, 0, 0));
	}

	// Debug: print reflection ray info
	printf("Reflection ray origin: (%f, %f, %f)\n",
		curr->comp->over_point->x, curr->comp->over_point->y, curr->comp->over_point->z);
	printf("Reflection ray direction: (%f, %f, %f)\n",
		curr->comp->reflectv->x, curr->comp->reflectv->y, curr->comp->reflectv->z);

	reflected_ray = init_ray(curr->comp->over_point, curr->comp->reflectv);

	// Intersect with all objects to find what the reflected ray hits
	intersect_to_list(scene, reflected_ray);
	if (!scene->obj_list->head || !scene->obj_list->head->t)
	{
		printf("No intersections found for reflected ray\n");
		free_ray(reflected_ray);
		return (init_rgb(0, 0, 0));
	}

	// Find the closest valid hit
	hit_obj = scene->obj_list->head;
	double closest_t = (hit_obj->t[0] > 0) ? hit_obj->t[0] : hit_obj->t[1];
	if (closest_t <= 0)
	{
		printf("All intersections behind ray origin\n");
		free_ray(reflected_ray);
		return (init_rgb(0, 0, 0));
	}

	printf("Reflected ray hit object at t = %f\n", closest_t);

	// Debug: check if the hit object has proper material and lighting setup
	printf("Hit object material - ambient: %f, diffuse: %f, specular: %f\n",
		hit_obj->material.ambient, hit_obj->material.diffuse, hit_obj->material.specular);
	printf("Hit object RGB: (%f, %f, %f)\n",
		hit_obj->material.rgb.r, hit_obj->material.rgb.g, hit_obj->material.rgb.b);

	// Temporarily replace the scene's object list for lighting calculation
	t_obj_list *original_list = scene->obj_list;
	scene->obj_list = new_list;

	color = get_shaded_with_shadows(scene, hit_obj);

	// Restore original list
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