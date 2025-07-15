#include "mini_rt.h"

void	free_obj_data(t_obj_data *data, int type)
{
	if (type == SPHERE && data->sphere)
	{
		if (data->sphere->matrix)
		{
			free(data->sphere->matrix->col0);
			free(data->sphere->matrix->col1);
			free(data->sphere->matrix->col2);
			free(data->sphere->matrix->col3);
			free(data->sphere->matrix);
		}
		free(data->sphere);
	}
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

void	print_matrix(t_m4 *m)
{
	if (!m || !m->col0 || !m->col1 || !m->col2 || !m->col3)
	{
		printf("Invalid matrix pointer.\n");
		return;
	}

	printf("Matrix:\n");
	printf("| %6.2f %6.2f %6.2f %6.2f |\n", m->col0->x, m->col1->x, m->col2->x, m->col3->x);
	printf("| %6.2f %6.2f %6.2f %6.2f |\n", m->col0->y, m->col1->y, m->col2->y, m->col3->y);
	printf("| %6.2f %6.2f %6.2f %6.2f |\n", m->col0->z, m->col1->z, m->col2->z, m->col3->z);
	printf("| %6.2f %6.2f %6.2f %6.2f |\n", m->col0->w, m->col1->w, m->col2->w, m->col3->w);
}

void	print_terminal(void)
{
	printf("===========================\n");
	printf("camera pos:\n");
	printf("x : 0.000000 y : 0.000000 z : 0.000000\n");
	printf("camera orientation:\n");
	printf("x : 0.000000 y : 0.000000 z : 0.000000\n");
	printf("===========================\n");
	fflush(stdout);
}

void	print_obj_list(t_obj_list *obj_list)
{
    t_obj_node	*curr;
    int			index;

    if (!obj_list)
    {
        printf("Object list is NULL\n");
        return;
    }
    
    printf("Object List (size: %zd):\n", obj_list->size);
    printf("Head: %p, Tail: %p\n", (void*)obj_list->head, (void*)obj_list->tail);
    
    if (!obj_list->head)
    {
        printf("List is empty\n");
        return;
    }
    
    curr = obj_list->head;
    index = 0;
    
    while (curr)
    {
        printf("Node %d: ", index);
        printf("Address: %p, ", (void*)curr);
        printf("Type: %d, ", curr->type);
        
        if (curr->t)
        {
            printf("t[0]: %.6f, t[1]: %.6f, ", curr->t[0], curr->t[1]);
        }
        else
        {
            printf("t: NULL, ");
        }
        
        printf("Next: %p\n", (void*)curr->next);
        
        curr = curr->next;
        index++;
        
        // Safety check to prevent infinite loops
        if (index > 100)
        {
            printf("Warning: Loop detected or list too long, stopping print\n");
            break;
        }
    }
    printf("--- End of list ---\n\n");
}


int	main(int argc, char **argv)
{
	t_scene	*scene;
	
	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1);
	if (!parser(scene, argc, argv))
		return (free(scene), 1);
	if(!init_mlx_window(scene))
		return(1);
	// print_obj_list(scene->obj_list);
	ray_tracing(scene);
	mlx_key_hook(scene->mlx, &key_hook, scene);
	mlx_loop(scene->mlx);
	mlx_terminate(scene->mlx);
	// free_obj_list(scene->obj_list);
	// free_light_list(scene->light_list);
	// free(scene);
	return(0);
}
