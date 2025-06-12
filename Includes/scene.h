#ifndef SCENE_H
# define SCENE_H

# include "custom_math.h"
# include "objects.h"
typedef struct s_ambi_light
{
	double			ratio;
	t_rgb			rgb;
}					t_ambi_light;

typedef struct s_camera
{
	t_tuples		view_point;
	t_tuples		orientation_vector;
	int				fov;
}					t_camera;

typedef struct s_light
{
	t_tuples		light_point;
	double			light_ratio;
	t_rgb			rgb;
}					t_light;

typedef struct s_scene
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_ambi_light	ambi_light;
	t_camera		camera;
	t_light			light;
	t_obj_list		*obj_list;
}					t_scene;

#endif