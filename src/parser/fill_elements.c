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
	normalize_rgb_triplet(&scene->ambi_light.rgb);
}

void	calc_pixel_size(t_camera *camera)
{
	double	half_view;
	double	aspect;

	half_view = tan(camera->fov / 2.0);
	aspect = camera->hsize / camera->vsize;
	if (aspect >= 1.0)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / camera->hsize;
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
	scene->camera.fov = radians(ft_atof(parsed_line));
	scene->camera.vsize = HEIGHT;
	scene->camera.hsize = WIDTH;
	init_view_transformation(&scene->camera.matrix, scene);
	scene->camera.half_height = 0;
	scene->camera.half_width = 0;
	calc_pixel_size(&scene->camera);
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
	light->intensity = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 0);
	skip_spaces_or_value(&parsed_line, 1, 0);
	light->rgb.r = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	light->rgb.g = ft_atof(parsed_line);
	skip_spaces_or_value(&parsed_line, 0, 1);
	light->rgb.b = ft_atof(parsed_line);
	normalize_rgb_triplet(&light->rgb);
}
