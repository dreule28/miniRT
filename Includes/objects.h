#ifndef OBJECTS_H
# define OBJECTS_H

# include "custom_math.h"
# include <unistd.h>
# include "matrices.h"


/* Enumeration of supported 3D object types */
typedef enum e_obj_type
{
	SPHERE,		/* Spherical object */
	PLANE,		/* Infinite plane */
	CYLINDER,
	CUBE,
	CONE
}	t_obj_type;

typedef enum e_pattern_type
{
	STRIPE_PATTERN,
	GRADIENT_PATTERN,
	RING_PATTERN,
	CHECKERS_PATTERN
} t_pattern_type;

typedef enum e_bump_type
{
	SINE_BUMP,
	QUILT_BUMP,
	CHECKERS_BUMP,
	WAVE_BUMP
} t_bump_type;


typedef struct s_pattern
{
	t_rgb			color1;
	t_rgb			color2;
	t_m4			transform;
	t_pattern_type	type;
	bool			has_pattern;
}					t_pattern;

typedef struct s_bump
{
	t_m4			transform;
	t_bump_type		type;
	double			amplitude;
	bool			has_bump;
}					t_bump;

typedef struct s_material
{
	t_rgb		rgb; /* Color information for the material */
	double		ambient; /* Ambient lighting coefficient (0.0 to 1.0) */
	double		diffuse; /* Diffuse reflection coefficient (0.0 to 1.0) */
	double		specular; /* Specular reflection coefficient (0.0 to 1.0) */
	double		shininess; /* Shininess factor for specular highlights */
	double		reflective;
	double		transparency;
	double		refractive_index;
	t_pattern	pattern;
	t_bump		bump;
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
	double		maximum;
	double		minimum;
	bool		closed;
	t_material	material;	/* Material of the object*/
}				t_cylinder;

typedef struct s_cube
{
	t_tuples	pos;
	t_tuples	orientation;
	t_material	material;
	t_tuples	scale;
}				t_cube;

typedef struct s_cone
{
	t_tuples	pos;
	t_tuples	axis;
	double		radius;
	double		height;
	double		maximum;
	double		minimum;
	bool		closed;
	t_material	material;
}				t_cone;


/* ========================================================================== */
/*                           OBJECT DATA STRUCTURES                          */
/* ========================================================================== */

/* Union to store different object types efficiently */
typedef union u_obj_data
{
	t_sphere	*sphere;	/* Pointer to sphere data */
	t_plane		*plane;		/* Pointer to plane data */
	t_cylinder	*cylinder;	/* Pointer to cylinder data */
	t_cube		*cube;
	t_cone		*cone;
}					t_obj_data;

typedef struct s_computations
{
	t_tuples	point;
	t_tuples	eyev;
	t_tuples	normalv;
	t_tuples	over_point;
	t_tuples	reflectv;
	t_tuples	under_point;
	bool		inside;
	bool		in_shadow;
	double		n1;
	double		n2;
}					t_computations;

/* Node in linked list of objects */
typedef struct s_obj_node
{
	t_obj_type			type;		/* Type of object stored */
	t_obj_data			*data;		/* Pointer to object data */
	double				t[2];			/* Intersection parameter values */
	bool				has_intersection;
	t_m4				matrix;
	t_computations		comp;
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