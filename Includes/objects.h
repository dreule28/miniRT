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
	CYLINDER
}	t_obj_type;

typedef struct s_material
{
	t_rgb	rgb; /* Color information for the material */
	double	ambient; /* Ambient lighting coefficient (0.0 to 1.0) */
	double	diffuse; /* Diffuse reflection coefficient (0.0 to 1.0) */
	double	specular; /* Specular reflection coefficient (0.0 to 1.0) */
	double	shininess; /* Shininess factor for specular highlights */
}			t_material;

/* ========================================================================== */
/*                           3D OBJECT STRUCTURES                            */
/* ========================================================================== */

/* Sphere object with position, size, color and transformation */
typedef struct s_sphere
{
	t_tuples	pos;		/* Center position in 3D space */
	double		radius;		/* Radius of the sphere */
	t_material	material;	/* Material of the object*/
}				t_sphere;

/* Plane object with position, orientation and color */
typedef struct s_plane
{
	t_tuples	pos;		/* Point on the plane */
	t_tuples	axis;		/* Normal vector defining plane orientation */
	t_material	material;	/* Material of the object*/
}				t_plane;

/* Cylinder object with position, orientation, dimensions and color */
typedef struct s_cylinder
{
	t_tuples	pos;		/* Center position of cylinder base */
	t_tuples	axis;		/* Direction vector of cylinder axis */
	double		radius;		/* Radius of the cylinder */
	double		height;		/* Height of the cylinder */
	t_material	material;	/* Material of the object*/
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

typedef struct s_computations
{
	t_tuples	*point;
	t_tuples	*eyev;
	t_tuples	*normalv;
	bool		inside;
}					t_computations;

/* Node in linked list of objects */
typedef struct s_obj_node
{
	t_obj_type			type;		/* Type of object stored */
	t_obj_data			*data;		/* Pointer to object data */
	double				*t;			/* Intersection parameter values */
	t_m4				*matrix;
	t_computations		*comp;
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