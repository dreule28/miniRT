#include "mini_rt.h"

t_sphere_node	*init_sphere(t_sphere_node *sphere)
{
	sphere->pos.x = 0;
	sphere->pos.y = 0;
	sphere->pos.z = 0;
	sphere->pos.w = 0;
	sphere->radius = 0;
	sphere->rgb.r = 0;
	sphere->rgb.g = 0;
	sphere->rgb.b = 0;
	return (sphere);
}

t_plane_node	*init_plane(t_plane_node *plane)
{
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

t_cylinder_node	*init_cylinder(t_cylinder_node *cylinder)
{
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
