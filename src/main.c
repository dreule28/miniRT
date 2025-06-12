#include "mini_rt.h"

int	main(int argc, char **argv)
{
	t_scene		*scene;
	t_rgb		sphere_color;
	t_tuples	sphere_center;
	double		sphere_diameter;

	(void)argc;
	(void)argv;
	scene = ft_calloc(1, sizeof(t_scene));
	scene->mlx = NULL;
	scene->obj_list = ft_calloc(1, sizeof(t_obj_list));
	if (!scene->obj_list)
	{
		free(scene);
		return (1);
	}
	// Initialize the first node
	scene->obj_list->head = ft_calloc(1, sizeof(t_obj_node));
	if (!scene->obj_list->head)
	{
		free(scene->obj_list);
		free(scene);
		return (1);
	}
	// Set tail to point to head since we only have one node
	scene->obj_list->tail = scene->obj_list->head;
	scene->obj_list->size = 1;
	// Initialize sphere data
	sphere_center = (t_tuples){2, 2, 2, POINT};
	sphere_color = (t_rgb){255, 0, 0};
	sphere_diameter = 2;
	// Set the node type and data
	scene->obj_list->head->type = SPHERE;
	scene->obj_list->head->data.sphere.rgb = sphere_color;
	scene->obj_list->head->data.sphere.sphere_center = sphere_center;
	scene->obj_list->head->data.sphere.sphere_diameter = sphere_diameter;
	scene->obj_list->head->next = NULL;
	// camera settings
	scene->camera.view_point = (t_tuples){0, 0, -10, POINT};
	// Camera position
	scene->camera.orientation_vector = (t_tuples){0, 0, 1, VECTOR};
	// Looking towards +z (where sphere is)
	scene->camera.fov = 70;
	// 70-degree field of view
	if (!init_mlx_window(scene))
		return (1);
	mlx_custom_hooks(scene);
	mlx_loop(scene->mlx);
	mlx_terminate(scene->mlx);
	// close_scene(scene);
	return (0);
}
