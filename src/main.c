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
    t_obj_node *one = scene->obj_list->head->next->next->next;
    t_obj_node *two = scene->obj_list->head->next->next->next->next;
    t_obj_node *three = scene->obj_list->tail;
    
    // First sphere - WHITE
    first->matrix = ftm_translation(init_point(-0.5, 1.0, 0.5));
    first->data->sphere->material = get_material();
    first->data->sphere->material.rgb = *init_rgb(1.0, 1.0, 1.0);  // Pure white
    first->data->sphere->material.diffuse = 0.7;
    first->data->sphere->material.specular = 0.1;
    first->data->sphere->material.ambient = 0.2;  // Add ambient for better visibility

    // Second sphere - BEIGE
    second->matrix = ftm_matrix_mult(ftm_translation(init_point(1.5, 0.33, -0.5)), ftm_scaling(init_point(0.33, 0.33, 0.33)));
    second->data->sphere->material = get_material();
    second->data->sphere->material.rgb = *init_rgb(0.9, 0.8, 0.6);  // Beige color
    second->data->sphere->material.diffuse = 0.7;
    second->data->sphere->material.specular = 0.1;
    second->data->sphere->material.ambient = 0.2;

    // Third sphere - BLACK
    third->matrix = ftm_matrix_mult(ftm_translation(init_point(-1.5, 0.33, -0.75)), ftm_scaling(init_point(0.33, 0.33, 0.33)));
    third->data->sphere->material = get_material();
    third->data->sphere->material.rgb = *init_rgb(0.1, 0.1, 0.1);  // Dark gray (pure black would be invisible)
    third->data->sphere->material.diffuse = 0.7;
    third->data->sphere->material.specular = 0.3;  // Higher specular for black objects
    third->data->sphere->material.ambient = 0.1;

    // ... rest of your plane setup remains the same
    one->matrix = ftm_translation(init_point(0, 0, 0));
    one->data->plane->material.ambient = 0.2;
    one->data->plane->material.diffuse = 0.8;
    one->data->plane->material.specular = 0.1;
    one->data->plane->material.shininess = 10.0;
    one->data->plane->material.rgb = *init_rgb(1, 0, 0.2);

    two->matrix = ftm_matrix_mult(ftm_translation(init_point(0, 0, 3)), ftm_rotate_x(M_PI_2));
    two->data->plane->material.ambient = 0.2;
    two->data->plane->material.diffuse = 0.8;
    two->data->plane->material.specular = 0.1;
    two->data->plane->material.shininess = 10.0;
    two->data->plane->material.rgb = *init_rgb(1, 0, 0.2);

    three->matrix = ftm_matrix_mult(ftm_translation(init_point(3, 0, 0)), ftm_rotate_z(M_PI_2));
    three->data->plane->material.ambient = 0.2;
    three->data->plane->material.diffuse = 0.8;
    three->data->plane->material.specular = 0.1;
    three->data->plane->material.shininess = 10.0;
    three->data->plane->material.rgb = *init_rgb(1, 0, 0.2);
    
    scene->camera.fov = M_PI/3;
    scene->camera.matrix = view_transformation(init_point(0, 1.5, -6), init_point(0, 1, 0), init_vector(0, 1, 0));
}

void	default_world(t_scene *scene)
{
	// The test expects to START with just two spheres, then ADD a plane
	// But your parsed scene has a plane first, so we need to work around this

	t_obj_node	*plane_node = scene->obj_list->head;        // This is your plane from parser
	t_obj_node	*first_sphere = scene->obj_list->head->next; // First sphere
	t_obj_node	*second_sphere = scene->obj_list->head->next->next; // Second sphere

	// Light at (-10, 10, -10)
	scene->light_list->head = point_light(*init_point(-10, 10, -10), *init_rgb(1, 1, 1));

	// Set up the plane (which should be reflective for the test)
	plane_node->data->plane->material.reflective = 0.5;
	// The plane should be at y = -1 (below the spheres)
	plane_node->matrix = ftm_translation(init_point(0, -1, 0));

	// First sphere (outer) - this is what the reflected ray should hit
	first_sphere->data->sphere->material.rgb = *init_rgb(0.8, 1.0, 0.6);
	first_sphere->data->sphere->material.diffuse = 0.7;
	first_sphere->data->sphere->material.specular = 0.2;
	first_sphere->data->sphere->material.ambient = 0.1;
	first_sphere->data->sphere->material.shininess = 200.0;
	first_sphere->data->sphere->material.reflective = 0;
	first_sphere->data->sphere->pos.x = 0;
	first_sphere->data->sphere->pos.y = 0;
	first_sphere->data->sphere->pos.z = 0;
	first_sphere->data->sphere->radius = 1.0;
	// first_sphere->matrix = NULL; // No transformation (unit sphere at origin)

	// Second sphere (inner) - scaled to 0.5 radius
	second_sphere->data->sphere->material = get_material(); // Default material
	second_sphere->data->sphere->pos.x = 0;
	second_sphere->data->sphere->pos.y = 0;
	second_sphere->data->sphere->pos.z = 0;
	second_sphere->data->sphere->radius = 1.0; // Will be scaled by matrix
	second_sphere->matrix = ftm_scaling(init_point(0.5, 0.5, 0.5));
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1);
	if (!parser(scene, argc, argv))
		return (free(scene), 1);

	// generate_scene(scene);

	// // t_ray	*ray;
	// // t_rgb	*color;

	default_world(scene);

	// // scene->obj_list->head->matrix = ftm_translation(init_point(0, -1, 0));
	// // ray = init_ray(init_point(0, 0, -3), init_vector(0, -sqrt(2)/2, sqrt(2)/2));
	// // intersect_to_list(scene, ray);
	// // // debug_scene(scene);
	// // color = reflected_color(scene, scene->obj_list->head->comp, 1);
	// // color = shade_hit(scene, scene->obj_list->head->comp, scene->light_list->head, 4);
	// // printf("Color: R=%f, G=%f, B=%f\n", color->r, color->g, color->b);

	// t_pattern *test;
	// test = stripe_pattern(init_rgb(1, 0, 1), init_rgb(0, 2350, 3245));
	// printf("pattern.color1 : x = %.6f, y = %.6f, z = %.6f\n", test->color1->r, test->color1->g, test->color1->b);
	// printf("pattern.color2 : x = %.6f, y = %.6f, z = %.6f\n", test->color2->r, test->color2->g, test->color2->b);


	if (!init_mlx_window(scene))
		return (1);
	render(scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	mlx_loop(scene->mlx);
	mlx_terminate(scene->mlx);
	return (0);
}
