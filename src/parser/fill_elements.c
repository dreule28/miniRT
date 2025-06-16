#include "mini_rt.h"

void	skip_spaces_or_value(char **parsed_line, int value, int comma)
{
	if (comma)
	{
		while (**parsed_line && **parsed_line != ',')
			(*parsed_line)++;
		if (**parsed_line == ',')
			(*parsed_line)++;
	}
	else if (value)
	{
		while (**parsed_line && !ft_is_space(**parsed_line))
			(*parsed_line)++;
	}
	else
	{
		while (**parsed_line && ft_is_space(**parsed_line))
			(*parsed_line)++;
	}
}

void	add_ambient(t_scene *scene, char *parsed_line)
{
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	scene->ambi_light.ratio = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	scene->ambi_light.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->ambi_light.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->ambi_light.rgb.b = ft_atof(parsed_line);
}

void	add_camera(t_scene *scene, char *parsed_line)
{
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	scene->camera.pos.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->camera.pos.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->camera.pos.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	scene->camera.orientation_vector.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->camera.orientation_vector.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->camera.orientation_vector.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	scene->camera.fov = ft_atoi(parsed_line);
}

void	add_light(t_light *light, char *parsed_line)
{
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	light->pos.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	light->pos.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	light->pos.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	light->brightness = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	light->rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	light->rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	light->rgb.b = ft_atof(parsed_line);
}
