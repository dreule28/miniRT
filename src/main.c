#include "mini_rt.h"

int	main(int argc, char **argv)
{
	// t_scene		*scene;
	// t_rgb		sphere_color;
	// t_tuples	sphere_center;
	// double		sphere_diameter;

	(void)argc;
	(void)argv;
	// scene = ft_calloc(1, sizeof(t_scene));
	// scene->mlx = NULL;
	// scene->obj_list = ft_calloc(1, sizeof(t_obj_list));
	// if (!scene->obj_list)
	// {
	// 	free(scene);
	// 	return (1);
	// }

	// scene->obj_list->head = ft_calloc(1, sizeof(t_obj_node));
	// if (!scene->obj_list->head)
	// {
	// 	free(scene->obj_list);
	// 	free(scene);
	// 	return (1);
	// }

	// scene->obj_list->tail = scene->obj_list->head;
	// scene->obj_list->size = 1;
	// // Initialize sphere data
	// sphere_center = *create_point(2.0 , 2.0, 2.0);
	// sphere_color = *create_rgb(255,0 , 0);
	// sphere_diameter = 2;
	// // Set the node type and data
	// scene->obj_list->head->type = SPHERE;
	// scene->obj_list->head->data.sphere.rgb = sphere_color;
	// scene->obj_list->head->data.sphere.pos = sphere_center;
	// scene->obj_list->head->data.sphere.diameter = sphere_diameter;
	// scene->obj_list->head->next = NULL;
	// // camera settings
	// scene->camera.pos =  *create_point(0, 0, -10);
	// // Camera position
	// scene->camera.orientation_vector = *create_vector(0, 0, 1);
	// // Looking towards +z (where sphere is)
	// scene->camera.fov = 70;
	// // 70-degree field of view
	// if (!init_mlx_window(scene))
	// 	return (1);
	// mlx_custom_hooks(scene);
	// mlx_loop(scene->mlx);
	// mlx_terminate(scene->mlx);
	// test_tuples_operations();
	return (0);
}
