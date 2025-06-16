#ifndef MINI_RT_H
# define MINI_RT_H
# define HEIGHT 1080
# define WIDTH 1920

//Includes -- BEGIN
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include "objects.h"
# include "scene.h"
# include "ray_tracing.h"
# include "custom_math.h"
# include "debug.h"
//Includes -- END

//Structs -- BEGIN

//Structs -- END

//Functions -- BEGIN

//parser-Folder -- BEGIN
//fill_elements.c -- BEGIN
void			skip_spaces_or_value(char **parsed_line, int value, int comma);
void			add_ambient(t_scene *scene, char *parsed_line);
void			add_camera(t_scene *scene, char *parsed_line);
void			add_light(t_light *light, char *parsed_line);
//fill_elements.c -- END

//fill_objects.c -- BEGIN
void			add_plane(t_obj_node *obj_node, char *parsed_line);
void			add_cylinder(t_obj_node *obj_node, char *parsed_line);
void			add_sphere(t_obj_node *obj_node, char *parsed_line);
//fill_objects.c -- END

//initialize_objects.c -- BEGIN
t_sphere_node	*init_sphere(t_sphere_node *sphere);
t_plane_node	*init_plane(t_plane_node *plane);
t_cylinder_node	*init_cylinder(t_cylinder_node *cylinder);
//initialize_objects.c -- END

//list_and_nodes.c -- BEGIN
t_obj_list		*init_obj_list(void);
t_obj_node		*add_obj_node(t_obj_list *obj_list, int obj_type);
t_obj_data		*init_obj_data(int obj_type);
t_light_list	*init_light_list(void);
t_light			*add_light_node(t_light_list *light_list, char *parsed_line);
//list_and_nodes.c -- END

//parser.c -- BEGIN
bool			check_argc(int argc);
bool			check_argv(char **argv);
bool			check_elements(t_scene *scene, char *parsed_line);
bool			validate_file(char **argv);
bool			parser(t_scene *scene, int argc, char **argv);

//utils.c -- BEGIN
bool			init_lists(t_obj_list **obj_list, t_light_list **light_list);
t_obj_data		*init_sphere_data(t_obj_data *data);
t_obj_data		*init_plane_data(t_obj_data *data);
t_obj_data		*init_cylinder_data(t_obj_data *data);
//utils.c -- END
//parser.c -- BEGIN
//parser-Folder -- END
//Functions -- END

#endif