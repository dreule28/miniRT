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
	DEBUG_TRACE("Parsing ambient light from: %s", parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	scene->ambi_light.ratio = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	scene->ambi_light.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->ambi_light.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->ambi_light.rgb.b = ft_atof(parsed_line);
	DEBUG_INFO("Ambient light parsed - Ratio: %.2f, RGB: (%.3f, %.3f, %.3f)",
		scene->ambi_light.ratio,
		scene->ambi_light.rgb.r, scene->ambi_light.rgb.g, scene->ambi_light.rgb.b);
}

void	add_camera(t_scene *scene, char *parsed_line)
{
	DEBUG_TRACE("Parsing camera from: %s", parsed_line);
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
	DEBUG_INFO("Camera parsed - Position: (%.3f, %.3f, %.3f), Orientation: (%.3f, %.3f, %.3f), FOV: %d",
		scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z,
		scene->camera.orientation_vector.x, scene->camera.orientation_vector.y, scene->camera.orientation_vector.z,
		scene->camera.fov);
}

void	add_light(t_scene *scene, char *parsed_line)
{
	DEBUG_TRACE("Parsing light from: %s", parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	skip_spaces_or_value(&parsed_line, 0, 0);
	scene->light.pos.x = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->light.pos.y = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->light.pos.z = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 1, 0);
	scene->light.brightness = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	scene->light.rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->light.rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	scene->light.rgb.b = ft_atof(parsed_line);
	DEBUG_INFO("Light parsed - Position: (%.3f, %.3f, %.3f), Brightness: %.2f, RGB: (%.3f, %.3f, %.3f)",
		scene->light.pos.x, scene->light.pos.y, scene->light.pos.z,
		scene->light.brightness,
		scene->light.rgb.r, scene->light.rgb.g, scene->light.rgb.b);
}
