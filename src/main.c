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
	// t_scene	*scene;

	// scene = malloc(sizeof(t_scene));
	// if (!scene)
	// {
	// 	// DEBUG_ERROR("Failed to allocate memory for scene");
	// 	return (1);
	// }
	// // DEBUG_INFO("Starting miniRT parser...");
	// if (!parser(scene, argc, argv))
	// {
	// 	// DEBUG_ERROR("Parsing failed");
	// 	free(sc
	// 	return (1);
	// }
	// DEBUG_INFO("Parsing completed successfully");
	// Debug the entire scene
	// print_scene(scene);
	// validate_scene(scene);
	// free_obj_list(scene->obj_list);
	// free_light_list(scene->light_list);
	// free(scene);
	(void)argc;
	(void)argv;
	t_tuples *start_pos = create_point(0, 1, 0);
    t_tuples *velocity = create_vector(1, 1, 0);
    tup_norm(velocity); // Normalize the velocity vector
    t_projectile *proj = create_projectile(start_pos, velocity);

    // Create environment
    t_tuples *gravity = create_vector(0, -0.1, 0);
    t_tuples *wind = create_vector(-0.01, 0, 0);
    t_environment *env = create_environment(gravity, wind);

    // Run simulation
    int ticks = 0;
    while (proj->position->y > 0)
    {
        printf("Position: x=%.2f, y=%.2f, z=%.2f\n", 
               proj->position->x, 
               proj->position->y, 
               proj->position->z);
        proj = tick(env, proj);
        ticks++;
    }
    printf("Final position: x=%.2f, y=%.2f, z=%.2f\n", 
           proj->position->x, 
           proj->position->y, 
           proj->position->z);
    printf("Total ticks: %d\n", ticks);
    return (0);
}
