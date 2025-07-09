#include "mini_rt.h"

t_sphere	*init_sphere(void)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->pos.x = 0;
	sphere->pos.y = 0;
	sphere->pos.z = 0;
	sphere->pos.w = 0;
	sphere->radius = 0;
	sphere->rgb.r = 0;
	sphere->rgb.g = 0;
	sphere->rgb.b = 0;
	sphere->matrix = init_m4();
	if (!sphere->matrix)
		return (free(sphere), NULL);
	sphere->matrix->col0 = assign_m4_col(1, 0, 0, 0);
	sphere->matrix->col1 = assign_m4_col(0, 1, 0, 0);
	sphere->matrix->col2 = assign_m4_col(0, 0, 1, 0);
	sphere->matrix->col3 = assign_m4_col(0, 0, 0, 1);
	return (sphere);
}

t_plane	*init_plane(void)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
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
	plane->rgb.r = 0;
	plane->rgb.g = 0;
	plane->rgb.b = 0;
	return (plane);
}

t_cylinder	*init_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
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
	cylinder->rgb.r = 0;
	cylinder->rgb.g = 0;
	cylinder->rgb.b = 0;
	return (cylinder);
}
