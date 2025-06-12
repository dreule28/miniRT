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

typedef struct s_sphere_node
{
	t_tuples				pos;
	double					diameter;
	t_rgb					rgb;
}							t_sphere_node;

typedef struct s_plane_node
{
	t_tuples				pos;
	t_tuples				axis;
	t_rgb					rgb;
}							t_plane_node;

typedef struct s_cylinder_node
{
	t_tuples				pos;
	t_tuples				axis;
	double					diameter;
	double					height;
	t_rgb					rgb;
}							t_cylinder_node;

typedef union u_obj_data
{
	t_sphere_node	sphere;
	t_plane_node	plane;
	t_cylinder_node	cylinder;
}					t_obj_data;

typedef struct s_obj_node
{
	int					type;
	t_obj_data			data;
	struct s_obj_node	*next;
}						t_obj_node;

typedef struct s_obj_list
{
	t_obj_node				*head;
	t_obj_node				*tail;
	ssize_t					size;
}							t_obj_list;

typedef struct				s_obj_node
{
	t_obj_type				type;
	t_obj_data				data;
	t_obj_node				*next;
}				t_obj_node;
#endif