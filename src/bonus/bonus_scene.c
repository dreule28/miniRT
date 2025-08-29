#include "mini_rt.h"

void	bonus_scene1(t_scene *scene)
{
	s1_sphere(scene);
	s2_sphere(scene);
	s3_sphere(scene);
	p1_plane(scene);
	p2_plane(scene);
	p3_plane(scene);
	c1_cylinder(scene);
	c1_cube(scene);
}

void	bonus_scenes(t_scene *scene, char *str)
{
	if(!ft_strcmp(str, "scenes/bonus.rt"))
		bonus_scene1(scene);
}
