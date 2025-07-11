#ifndef OBJECTS_H
# define OBJECTS_H

# include "custom_math.h"
# include <unistd.h>

typedef struct s_m4	t_m4;

/* Enumeration of supported 3D object types */
typedef enum e_obj_type
{
	SPHERE,		/* Spherical object */
	PLANE,		/* Infinite plane */
	CYLINDER	/* Cylindrical object */
}	t_obj_type;

/* ========================================================================== */
/*                           3D OBJECT STRUCTURES                            */
/* ========================================================================== */

/* Sphere object with position, size, color and transformation */
typedef struct s_sphere
{
	t_tuples	pos;		/* Center position in 3D space */
	double		radius;		/* Radius of the sphere */
	t_rgb		rgb;		/* Color of the sphere */
	t_m4		*matrix;	/* Transformation matrix */
}				t_sphere;

/* Plane object with position, orientation and color */
typedef struct s_plane
{
	t_tuples	pos;		/* Point on the plane */
	t_tuples	axis;		/* Normal vector defining plane orientation */
	t_rgb		rgb;		/* Color of the plane */
}				t_plane;

/* Cylinder object with position, orientation, dimensions and color */
typedef struct s_cylinder
{
	t_tuples	pos;		/* Center position of cylinder base */
	t_tuples	axis;		/* Direction vector of cylinder axis */
	double		radius;		/* Radius of the cylinder */
	double		height;		/* Height of the cylinder */
	t_rgb		rgb;		/* Color of the cylinder */
}				t_cylinder;

/* ========================================================================== */
/*                           OBJECT DATA STRUCTURES                          */
/* ========================================================================== */

/* Union to store different object types efficiently */
typedef union u_obj_data
{
	t_sphere	*sphere;	/* Pointer to sphere data */
	t_plane		*plane;		/* Pointer to plane data */
	t_cylinder	*cylinder;	/* Pointer to cylinder data */
}					t_obj_data;

/* Node in linked list of objects */
typedef struct s_obj_node
{
	t_obj_type			type;		/* Type of object stored */
	t_obj_data			*data;		/* Pointer to object data */
	double				*t;			/* Intersection parameter values */
	struct s_obj_node	*next;		/* Pointer to next node */
}						t_obj_node;

/* Linked list containing all objects in the scene */
typedef struct s_obj_list
{
	t_obj_node	*head;		/* First node in the list */
	t_obj_node	*tail;		/* Last node in the list */
	ssize_t		size;		/* Number of objects in the list */
}				t_obj_list;
#endif