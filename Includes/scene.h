#ifndef SCENE_H
# define SCENE_H

# include "custom_math.h"
# include "objects.h"

/* Ambient lighting affecting entire scene uniformly */
typedef struct s_ambi_light
{
	double			ratio;		/* Intensity ratio (0.0 - 1.0) */
	t_rgb			rgb;		/* Color of ambient light */
}					t_ambi_light;

typedef struct s_light
{
	t_tuples		pos;		/* Position of light source */
	double			intensity;	/* Brightness intensity (0.0 - 1.0) */
	t_rgb			rgb;		/* Color of the light */
	struct s_light	*next;		/* Pointer to next light in list */
}					t_light;

/* Linked list containing all light sources */
typedef struct s_light_list
{
	t_light	*head;		/* First light in the list */
	t_light	*tail;		/* Last light in the list */
	ssize_t	size;		/* Number of lights in the list */
}			t_light_list;

/* Virtual camera defining viewpoint and perspective */
typedef struct s_camera
{
	t_tuples		pos;				/* Camera position in 3D space */
	t_tuples		orientation_vector;	/* Direction camera is facing */
	double			fov;				/* Field of view in degrees */
	double			hsize;
	double			vsize;
	t_m4			matrix;
	double			pixel_size;
	double			half_width;
	double			half_height;
}					t_camera;

/* Complete scene containing all rendering elements */
typedef struct s_scene
{
	mlx_t			*mlx;			/* MLX graphics library instance */
	mlx_image_t		*img;			/* Image buffer for rendering */
	t_ambi_light	ambi_light;		/* Ambient lighting settings */
	t_camera		camera;			/* Camera configuration */
	t_light_list	*light_list;	/* List of all light sources */
	t_obj_list		*obj_list;		/* List of all 3D objects */
}					t_scene;

#endif