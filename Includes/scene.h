#ifndef SCENE_H
# define SCENE_H

# include "custom_math.h"
# include "objects.h"

typedef struct s_ambi_light
{
	double			ratio;
	t_rgb			rgb;
}					t_ambi_light;

typedef	struct s_movement
{
	bool key_w;
    bool key_s;
    bool key_a;
    bool key_d;
}					t_movement;

typedef struct s_camera
{
	t_tuples		pos;
	t_tuples		orientation_vector;
	int				fov;
	// t_movement		movement;
}					t_camera;

typedef struct s_light
{
	t_tuples		pos;
	double			brightness;
	t_rgb			rgb;
	struct s_light	*next;
}					t_light;

typedef struct s_light_list
{
	t_light	*head;
	t_light	*tail;
	ssize_t	size;
}			t_light_list;

typedef struct s_scene
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_ambi_light	ambi_light;
	t_camera		camera;
	t_light_list	*light_list;
	t_obj_list		*obj_list;
}					t_scene;

#endif