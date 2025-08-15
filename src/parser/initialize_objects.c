#include "mini_rt.h"

t_sphere	*init_sphere(void)
{
	t_sphere	*sphere;

	sphere = ft_calloc(sizeof(t_sphere), 1);
	if (!sphere)
		return (NULL);
	sphere->pos.x = 0;
	sphere->pos.y = 0;
	sphere->pos.z = 0;
	sphere->pos.w = 0;
	sphere->radius = 0;
	sphere->material.rgb.r = 0;
	sphere->material.rgb.g = 0;
	sphere->material.rgb.b = 0;
	return (sphere);
}

t_plane	*init_plane(void)
{
	t_plane	*plane;

	plane = ft_calloc(sizeof(t_plane), 1);
	if (!plane)
		return (NULL);
	plane->pos.x = 0;
	plane->pos.y = 0;
	plane->pos.z = 0;
	plane->pos.w = 0;
	plane->axis.x = 0;
	plane->axis.y = 0;
	plane->axis.z = 0;
	plane->axis.w = 0;
	plane->material.rgb.r = 0;
	plane->material.rgb.g = 0;
	plane->material.rgb.b = 0;
	return (plane);
}

t_cylinder	*init_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	if (!cylinder)
		return (NULL);
	cylinder->pos.x = 0;
	cylinder->pos.y = 0;
	cylinder->pos.z = 0;
	cylinder->pos.w = 0;
	cylinder->axis.x = 0;
	cylinder->axis.y = 0;
	cylinder->axis.z = 0;
	cylinder->axis.w = 0;
	cylinder->radius = 0;
	cylinder->height = 0;
	cylinder->material.rgb.r = 0;
	cylinder->material.rgb.g = 0;
	cylinder->material.rgb.b = 0;
	cylinder->maximum = INFINITY;
	cylinder->minimum = INFINITY;
	return (cylinder);
}
