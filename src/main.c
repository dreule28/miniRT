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

int main(void)
{
	t_sphere_node	*sphere;
	t_ray			*ray;
	double			*interesection;

	sphere = init_sphere();
	ray = init_ray(init_point(0, 2, -5), init_vector(0, 0, 1));

	interesection = intersects(ray);
	if (!interesection)
	{
		printf("No interseciton\n");
		return (1);
	}
	printf("T[0]: %f T[1]: %f\n", interesection[0], interesection[1]);
	return (0);
}
