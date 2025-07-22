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
    t_obj_node *two = scene->obj_list->tail;
	
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

	one->matrix = ftm_translation(init_point(0, 0, 0));
	two->matrix = ftm_matrix_mult(ftm_rotate_x(M_PI_2), ftm_translation(init_point(0, 0, -8)));

    scene->camera.fov = M_PI/3;
    scene->camera.matrix = view_transformation(init_point(0, 1.6, -30), init_point(0, 1, 0), init_vector(0, 1, 0));
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1);
	if (!parser(scene, argc, argv))
		return (free(scene), 1);
	generate_scene(scene);
	if (!init_mlx_window(scene))
		return (1);
	render(scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	mlx_loop(scene->mlx);
	mlx_terminate(scene->mlx);
	return (0);
}
