#ifndef MINI_RT_H
# define MINI_RT_H
# define HEIGHT 1080
# define WIDTH 1920

//Includes -- BEGIN
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include "objects.h"
# include "scene.h"
# include "ray_tracing.h"
# include "custom_math.h"
//Includes -- END

//Structs -- BEGIN

//Structs -- END

//Functions -- BEGIN

//parser-Folder -- BEGIN
//fill_structs.c -- BEGIN
void		add_ambient(t_scene *scene, char *parsed_line);
void		add_camera(t_scene *scene, char *parsed_line);
void		add_light(t_scene *scene, char *parsed_line);
//fill_structs.c -- END

//list_and_nodes.c -- BEGIN
t_obj_list	*init_obj_list();
//list_and_nodes.c -- END

//parser.c -- BEGIN
bool		check_argc(int argc);
bool		check_argv(char **argv);
bool		check_elements(t_scene *scene, char *parsed_line);
bool		parser(t_scene *scene, int argc, char **argv);
//parser.c -- BEGIN
//parser-Folder -- END
//Functions -- END

#endif