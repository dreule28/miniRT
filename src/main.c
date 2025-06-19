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

int	main(int argc, char **argv)
{
	t_m2	*m2;
	t_m3	*m3;
	t_m4	*m4;
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (1);
	// if (!parser(scene, argc, argv))
	// 	return (free(scene),1);
	(void)argc;
	(void)argv;

	DEBUG_INFO("Starting matrix function tests...");

	// Test M4 matrix
	m2 = init_m2();
	add_m2_col(m2, 1.0, 5.5);
	add_m2_col(m2, 2.0, 6.5);

	t_m2_col *curr = m2->head;
	int i = 1;
	write(1, "M2\n", 3);
	while (curr)
	{
		printf("COL%d X: %.3f Y:%.3f\n", i, curr->x, curr->y);
		i++;
		curr = curr->next;
	}

	// Test M3 matrix
	m3 = init_m3();
	add_m3_col(m3, 1.0, 5.5, 9.0);
	add_m3_col(m3, 2.0, 6.5, 10.0);
	add_m3_col(m3, 3.0, 7.5, 11.0);

	t_m3_col *curr3 = m3->head;
	i = 1;
	write(1, "M3\n", 3);
	while (curr3)
	{
		printf("COL%d X: %.3f Y:%.3f Z:%.3f\n", i, curr3->x, curr3->y, curr3->z);
		i++;
		curr3 = curr3->next;
	}

	// Test M4 matrix
	m4 = init_m4();
	append_col(m4, add_m4_col(1, 5.5, 9, 13.5));
	append_col(m4, add_m4_col(2, 6.5, 10, 14.5));
	append_col(m4, add_m4_col(3, 7.5, 11, 15.5));
	append_col(m4, add_m4_col(4, 8.5, 12, 16.5));

	t_m4_col *curr4 = m4->head;
	i = 1;
	write(1, "M4\n", 3);
	while (curr4)
	{
		printf("COL%d X: %.3f Y:%.3f Z:%.3f W:%.3f\n", i, curr4->x, curr4->y, curr4->z, curr4->w);
		i++;
		curr4 = curr4->next;
	}


	DEBUG_INFO("Matrix function tests completed");


	// free_obj_list(scene->obj_list);
	// free_light_list(scene->light_list);
	free(scene);
	free(m2);
	free(m3);
	free(m4);
	return (0);
}
