#ifndef MINI_RT_H
# define MINI_RT_H
# define WIDTH 500
# define HEIGHT 500
# define DBL_EPSILON 2.2204460492503131e-16
# define EPSILON 1e-5

//Includes -- BEGIN
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
// # include <float.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include "objects.h"
# include "scene.h"
# include "ray_tracing.h"
# include "custom_math.h"
# include "matrices.h"
# include "mlx_custom.h"

//parser-Folder -- BEGIN
//fill_elements.c -- BEGIN
void			skip_spaces_or_value(char **parsed_line, int value, int comma);
void			add_ambient(t_scene *scene, char *parsed_line);
void			calc_pixel_size(t_camera *camera);
void			add_camera(t_scene *scene, char *parsed_line);
void			add_light(t_light *light, char *parsed_line);
//fill_elements.c -- END

//fill_objects.c -- BEGIN
void			add_plane(t_obj_node *obj_node, char *parsed_line);
void			add_cylinder(t_obj_node *obj_node, char *parsed_line);
void			add_sphere(t_obj_node *obj_node, char *parsed_line);
//fill_objects.c -- END

//initialize_objects.c -- BEGIN
t_sphere		*init_sphere(void);
t_plane			*init_plane(void);
t_cylinder		*init_cylinder(void);
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

//inits.c -- BEGIN
bool			init_lists(t_obj_list **obj_list, t_light_list **light_list);
t_obj_data		*init_sphere_data(t_obj_data *data);
t_obj_data		*init_plane_data(t_obj_data *data);
t_obj_data		*init_cylinder_data(t_obj_data *data);
void			search_for_objects(t_scene *scene, char *parsed_line);
//inits.c -- END

//parser.c -- BEGIN
//parser-Folder -- END
//main.c -- BEGIN
void			free_obj_data(t_obj_data *data, int type);
void			free_obj_list(t_obj_list *obj_list);
void			free_light_list(t_light_list *light_list);
//main.c -- END
//Functions -- END

#endif