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

		// Test case 1: Adding two vectors
		t_tuples *vec1 = create_vector(1.0, 2.0, 3.0);
		t_tuples *vec2 = create_vector(2.0, 3.0, 4.0);
		t_tuples *result1 = tup_subtract(vec1, vec2);
		
		printf("\n=== Test Case 1: Adding Vectors ===\n");
		printf("Vector 1: (%.1f, %.1f, %.1f, %d)\n", vec1->x, vec1->y, vec1->z, vec1->w);
		printf("Vector 2: (%.1f, %.1f, %.1f, %d)\n", vec2->x, vec2->y, vec2->z, vec2->w);
		printf("Result:   (%.1f, %.1f, %.1f, %d)\n", result1->x, result1->y, result1->z, result1->w);
		
		// Test case 2: Adding point and vector
		t_tuples *point = create_point(1.0, 1.0, 1.0);
		t_tuples *vec3 = create_vector(1.0, 2.0, 3.0);
		t_tuples *result2 = tup_subtract(point, vec3);
		
		printf("\n=== Test Case 2: Adding Point and Vector ===\n");
		printf("Point:    (%.1f, %.1f, %.1f, %d)\n", point->x, point->y, point->z, point->w);
		printf("Vector:   (%.1f, %.1f, %.1f, %d)\n", vec3->x, vec3->y, vec3->z, vec3->w);
		printf("Result:   (%.1f, %.1f, %.1f, %d)\n", result2->x, result2->y, result2->z, result2->w);
		
		// Test case 3: Compare different tuples
		t_tuples *vec4 = create_vector(1.0, 2.0, 3.0);
		t_tuples *vec5 = tup_negate(vec4);
		
		printf("\n=== Test Case 3: Compare Tuples ===\n");
		printf("Vector 4: (%.1f, %.1f, %.1f, %d)\n", vec4->x, vec4->y, vec4->z, vec4->w);
		printf("Vector 5: (%.1f, %.1f, %.1f, %d)\n", vec5->x, vec5->y, vec5->z, vec5->w);
		
		// Don't forget to free allocated memory
		free(vec1);
		free(vec2);
		free(vec3);
		free(vec4);
		free(vec5);
		free(point);
		free(result1);
		free(result2);
	return (0);
}
