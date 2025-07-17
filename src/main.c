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

void	generate_scene(t_scene *scene)
{
	t_obj_node	*first	= scene->obj_list->head;
	t_obj_node	*second	= scene->obj_list->head->next;
	t_obj_node	*third	= scene->obj_list->head->next->next;
	t_obj_node	*fourth	= scene->obj_list->head->next->next->next;
	t_obj_node	*fifth	= scene->obj_list->head->next->next->next->next;
	t_obj_node	*sixth	= scene->obj_list->tail;
	// First Sphere
	first->matrix = ftm_scaling(init_point(10, 0.01, 10));
	first->data->sphere->material = get_material();
	first->data->sphere->material.rgb = *init_rgb(1, 0.9, 0.9);
	first->data->sphere->material.specular = 0;

	// Second Sphere
	t_m4 *trans = ftm_translation(init_point(0, 0, 5));
	t_m4 *roty = ftm_rotate_y(-M_PI_4);
	t_m4 *rotx = ftm_rotate_x(M_PI_2);
	t_m4 *scale = ftm_scaling(init_point(10, 0.01, 10));
	t_m4 *mult1 = ftm_matrix_mult(trans, roty);
	t_m4 *mult2 = ftm_matrix_mult(mult1, rotx);
	t_m4 *mult3 = ftm_matrix_mult(mult2, scale);
	second->matrix = mult3;
	second->data->sphere->material = get_material();
	second->data->sphere->material.rgb = *init_rgb(1, 0.9, 0.9);
	second->data->sphere->material.specular = 0;

	// Third Sphere
	roty = ftm_rotate_y(M_PI_4);
	t_m4 *mult4 = ftm_matrix_mult(trans, roty);
	t_m4 *mult5 = ftm_matrix_mult(mult4, rotx);
	t_m4 *mult6 = ftm_matrix_mult(mult5, scale);
	third->matrix = mult6;
	third->data->sphere->material = get_material();
	third->data->sphere->material.rgb = *init_rgb(1, 0.9, 0.9);
	third->data->sphere->material.specular = 0;

	// Forth Sphere
	fourth->matrix = ftm_translation(init_point(-0.5, 1, 0.5));
	fourth->data->sphere->material = get_material();
	fourth->data->sphere->material.rgb = *init_rgb(0.1, 1, 0.5);
	fourth->data->sphere->material.diffuse = 0.7;
	fourth->data->sphere->material.specular = 0.3;

	// Fifth Sphere
	fifth->matrix = ftm_matrix_mult(ftm_translation(init_point(1.5, 0.5, -0.5)), ftm_scaling(init_point(0.5, 0.5, 0.5)));
	fifth->data->sphere->material = get_material();
	fifth->data->sphere->material.rgb = *init_rgb(0.5, 1, 0.1);
	fifth->data->sphere->material.diffuse = 0.7;
	fifth->data->sphere->material.specular = 0.3;

	// Sixth Sphere
	sixth->matrix = ftm_matrix_mult(ftm_translation(init_point(-1.5, 0.33, -0.75)), ftm_scaling(init_point(0.33, 0.33, 0.33)));
	sixth->data->sphere->material = get_material();
	sixth->data->sphere->material.rgb = *init_rgb(1, 0.8, 0.1);
	sixth->data->sphere->material.diffuse = 0.7;
	sixth->data->sphere->material.specular = 0.3;

	scene->camera.fov = M_PI/3;
	scene->camera.matrix = view_transformation(init_point(0, 1.5, -5), init_point(0, 1, 0), init_vector(0, 1, 0));
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

	if (!init_mlx_window(scene))
		return (1);
	render(scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	mlx_loop(scene->mlx);
	mlx_terminate(scene->mlx);
	return (0);
}
