#ifndef SCENE_H
# define SCENE_H

# include "math.h"

typedef struct s_ambi_light
{
	double			ratio;
	t_rgb			rgb;
}					t_ambi_light;

typedef struct s_camera
{
	t_vector		view_point;
	t_vector		orientation_vector;
	int				fov;
}					t_camera;

typedef struct s_light
{
	t_vector		light_point;
	double			light_ratio;
	t_rgb			rgb;
}					t_light;

typedef struct s_scene
{
	t_ambi_light	ambi_light;
	t_camera		camera;
	t_light			light;
}					t_scene;

#endif