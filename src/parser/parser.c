#include "mini_rt.h"

bool	check_argc(int argc)
{
	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
		{
			ft_putstr_fd("Error\nMissing scene!\n",2 );
			return (false);
		}
		else
		{
			ft_putstr_fd("Error\nToo many Args!\n", 2);
			return (false);
		}
	}
	return (true);
}

bool	check_argv(char **argv)
{
	char	*path;

	path = argv[1];
	if (ft_strncmp(path, "scenes/", 7))
	{
		ft_putstr_fd("Error\nWrong path\n", 2);
		return (false);
	}
	return (true);
}

bool	check_elements(t_scene *scene, char *parsed_line)
{
	if (!ft_strncmp(parsed_line, "A", 1))
		add_ambient(scene, parsed_line);
	if (!ft_strncmp(parsed_line, "C", 1))
		add_camera(scene, parsed_line);
	if (!ft_strncmp(parsed_line, "L", 1))
		add_light(scene, parsed_line);
	// if (!ft_strncmp(parsed_line, "pl", 2))
	// 	add_plane(scene, parsed_line);
	// if (!ft_strncmp(parsed_line, "sp", 2))
	// 	add_sphere(scene, parsed_line);
	// if (!ft_strncmp(parsed_line, "cy", 2))
	// 	add_cylinder(scene, parsed_line);
	return (true);
}

bool	parser(t_scene *scene, int argc, char **argv)
{
	int			rt_file;
	char		*parsed_line;
	int			count_pl;
	int			count_sp;
	int			count_cy;
	t_obj_list	*obj_list;

	count_pl = 0;
	count_sp = 0;
	count_cy = 0;

	if (!check_argc(argc) || !check_argv(argv))
		return (false);
	rt_file = open(argv[1], O_RDONLY);
	if (rt_file == -1)
	return (false);
	parsed_line = get_next_line(rt_file);
	while (parsed_line)
	{
		if (!ft_strncmp(parsed_line, "#", 1))
		{
			free(parsed_line);
			parsed_line = get_next_line(rt_file);
			continue;
		}
		if (!ft_strncmp(parsed_line, "pl", 2))
			count_pl++;
		else if (!ft_strncmp(parsed_line, "sp", 2))
			count_sp++;
		else if (!ft_strncmp(parsed_line, "cy", 2))
			count_cy++;
		check_elements(scene, parsed_line);
		// printf("%s", parsed_line);
		free(parsed_line);
		parsed_line = get_next_line(rt_file);
	}
	obj_list = init_obj_list();
	printf("pl: %d\nsp: %d\ncy: %d\n", count_pl, count_sp, count_cy);
	printf("Ambient - Ratio: (%.1f), RGB: (%.1f,%.1f,%.1f)\n", scene->ambi_light.ratio, scene->ambi_light.rgb.r, scene->ambi_light.rgb.g, scene->ambi_light.rgb.b);
	printf("Camera - Viewpoint: (%.1f,%.1f,%.1f), Orientation: (%.1f,%.1f,%.1f), FOV: (%d)\n", scene->camera.view_point.x, scene->camera.view_point.y, scene->camera.view_point.z, scene->camera.orientation_vector.x, scene->camera.orientation_vector.y, scene->camera.orientation_vector.z, scene->camera.fov);
	printf("Light - Position: (%.1f,%.1f,%.1f), Brightness: (%.1f), RGB: (%.1f,%.1f,%.1f)\n", scene->light.light_point.x, scene->light.light_point.y, scene->light.light_point.z, scene->light.light_ratio, scene->light.rgb.r, scene->light.rgb.g, scene->light.rgb.b);
	return (true);
}
