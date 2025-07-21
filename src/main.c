#include "mini_rt.h"

void	free_obj_data(t_obj_data *data, int type)
{
	if (type == SPHERE && data->sphere)
		free(data->sphere);
	else if (type == PLANE && data->plane)
		free(data->plane);
	else if (type == CYLINDER && data->cylinder)
		free(data->cylinder);
	free(data);
}

void	free_obj_list(t_obj_list *obj_list)
{
	t_obj_node	*curr;
	t_obj_node	*next;

	curr = obj_list->head;
	while (curr)
	{
		next = curr->next;
		free_obj_data(curr->data, curr->type);
		free(curr);
		curr = next;
	}
	free(obj_list);
}

void	free_light_list(t_light_list *light_list)
{
	t_light	*curr;
	t_light	*next;

	curr = light_list->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(light_list);
}

void generate_scene(t_scene *scene)
{
    t_obj_node *first = scene->obj_list->head;
    t_obj_node *second = scene->obj_list->head->next;
    t_obj_node *third = scene->obj_list->head->next->next;

    // First Sphere - move higher above the plane
    first->matrix = ftm_translation(init_point(-0.5, 1.0, 0.5));
    first->data->sphere->material = get_material();
    first->data->sphere->material.rgb = *init_rgb(0.1, 1, 0.5);
    first->data->sphere->material.diffuse = 0.7;
    first->data->sphere->material.specular = 0.3;

    // Second Sphere - move higher above the plane
    second->matrix = ftm_matrix_mult(ftm_translation(init_point(1.5, 0.5, -0.5)), ftm_scaling(init_point(0.5, 0.5, 0.5)));
    second->data->sphere->material = get_material();
    second->data->sphere->material.rgb = *init_rgb(0.5, 1, 0.1);
    second->data->sphere->material.diffuse = 0.7;
    second->data->sphere->material.specular = 0.3;

    // Third Sphere - move higher above the plane
    third->matrix = ftm_matrix_mult(ftm_translation(init_point(-1.5, 0.33, -0.75)), ftm_scaling(init_point(0.33, 0.33, 0.33)));
    third->data->sphere->material = get_material();
    third->data->sphere->material.rgb = *init_rgb(1, 0.8, 0.1);
    third->data->sphere->material.diffuse = 0.7;
    third->data->sphere->material.specular = 0.3;

    scene->camera.fov = M_PI/3;
    scene->camera.matrix = view_transformation(init_point(0, 1.5, -5), init_point(0, 1, 0), init_vector(0, 1, 0));
}

// Add this debug code to your main() function right before calling reflected_color

// void debug_scene(t_scene *scene)
// {
//     printf("=== SCENE DEBUG ===\n");

//     // Check lights
//     if (!scene->light_list || !scene->light_list->head)
//     {
//         printf("ERROR: No lights in scene!\n");
//         return;
//     }

//     t_light *light = scene->light_list->head;
//     int light_count = 0;
//     while (light)
//     {
//         printf("Light %d: pos=(%f,%f,%f), rgb=(%f,%f,%f), intensity=%f\n",
//             light_count,
//             light->pos.x, light->pos.y, light->pos.z,
//             light->rgb.r, light->rgb.g, light->rgb.b,
//             light->intensity);
//         light = light->next;
//         light_count++;
//     }
//     printf("Total lights: %d\n", light_count);

//     // Check objects
//     t_obj_node *obj = scene->obj_list->head;
//     int obj_count = 0;
//     while (obj)
//     {
//         printf("Object %d: type=%d, material rgb=(%f,%f,%f)\n",
//             obj_count, obj->type,
//             obj->material.rgb.r, obj->material.rgb.g, obj->material.rgb.b);
//         printf("  ambient=%f, diffuse=%f, specular=%f, reflective=%f\n",
//             obj->material.ambient, obj->material.diffuse,
//             obj->material.specular, obj->material.reflective);
//         obj = obj->next;
//         obj_count++;
//     }
//     printf("Total objects: %d\n", obj_count);
//     printf("=== END DEBUG ===\n");
// }

// Call this in your main() before the reflection test:
// debug_scene(scene);

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1);
	if (!parser(scene, argc, argv))
		return (free(scene), 1);

	// generate_scene(scene);

	t_ray	*ray;
	t_rgb	*color;


	// printf("Object type: %d\n", scene->obj_list->head->type);
	scene->obj_list->head->data->plane->material.reflective = 0.5;
	scene->obj_list->head->matrix = ftm_translation(init_point(0, -1, 0));
	ray = init_ray(init_point(0, 0, -3), init_vector(0, -sqrt(2)/2, sqrt(2)/2));
	intersect_to_list(scene, ray);
	// debug_scene(scene);
	color = reflected_color(scene, scene->obj_list->head);
	printf("Color: R=%f, G=%f, B=%f\n", color->r, color->g, color->b);





	// if (!init_mlx_window(scene))
	// 	return (1);
	// render(scene);
	// mlx_key_hook(scene->mlx, &key_hook, scene);
	// mlx_loop(scene->mlx);
	// mlx_terminate(scene->mlx);
	return (0);
}
