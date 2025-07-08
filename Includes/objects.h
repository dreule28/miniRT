#ifndef OBJECTS_H
# define OBJECTS_H

# include "custom_math.h"
# include <unistd.h>

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_sphere
{
	t_tuples	pos;
	double		radius;
	t_rgb		rgb;
}				t_sphere;

typedef struct s_plane
{
	t_tuples	pos;
	t_tuples	axis;
	t_rgb		rgb;
}				t_plane;

typedef struct s_cylinder
{
	t_tuples	pos;
	t_tuples	axis;
	double		radius;
	double		height;
	t_rgb		rgb;
}				t_cylinder;

typedef union u_obj_data
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}					t_obj_data;

typedef struct s_obj_node
{
	t_obj_type			type;
	t_obj_data			*data;
	double				*t;
	struct s_obj_node	*next;
}						t_obj_node;

typedef struct s_obj_list
{
	t_obj_node	*head;
	t_obj_node	*tail;
	ssize_t		size;
}				t_obj_list;
#endif