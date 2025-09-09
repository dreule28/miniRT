#include "mini_rt.h"

bool	check_argc(int argc)
{
	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
		{
			ft_putstr_fd("Error\nMissing scene!\n", 2);
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
	{
		add_ambient(scene, parsed_line);
		scene->syntax_count++;
	}
	if (!ft_strncmp(parsed_line, "C", 1))
	{
		add_camera(scene, parsed_line);
		scene->syntax_count++;
	}
	if (!ft_strncmp(parsed_line, "L", 1))
		add_light_node(scene->light_list, parsed_line);
	return (true);
}

bool	validate_file(char **argv)
{
	int	i;
	int	last_slash;
	int	last_dot;

	i = 0;
	last_slash = -1;
	last_dot = -1;
	while (argv[1][i])
	{
		if (argv[1][i] == '/')
			last_slash = i;
		if (argv[1][i] == '.')
			last_dot = i;
		i++;
	}
	if (ft_strncmp(&argv[1][i - 3], ".rt", 3))
		return (ft_putstr_fd("Error\nWrong file type\n", 2), false);
	if (last_dot - last_slash <= 1)
		return (ft_putstr_fd("Error\nInvalid filename\n", 2), false);
	return (true);
}

bool	parser(t_scene *scene, int argc, char **argv)
{
	int		rt_file;
	char	*parsed_line;

	if (!check_argc(argc) || !check_argv(argv) || !validate_file(argv))
		return (false);
	rt_file = open(argv[1], O_RDONLY);
	if (rt_file == -1)
		return (false);
	if (!init_lists(&scene->obj_list, &scene->light_list))
		return (close(rt_file), false);
	parsed_line = get_next_line(rt_file);
	while (parsed_line)
	{
		if (!ft_strncmp(parsed_line, "#", 1))
		{
			free(parsed_line);
			parsed_line = get_next_line(rt_file);
			continue ;
		}
		search_for_objects(scene, parsed_line);
		check_elements(scene, parsed_line);
		free(parsed_line);
		parsed_line = get_next_line(rt_file);
	}
	return (close(rt_file), true);
}
