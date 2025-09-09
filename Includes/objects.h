/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:09:03 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 15:09:04 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "custom_math.h"
# include <unistd.h>
# include "matrices.h"

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CUBE,
	TRIANGLE,
	CONE
}	t_obj_type;

typedef enum e_pattern_type
{
	STRIPE_PATTERN,
	GRADIENT_PATTERN,
	RING_PATTERN,
	CHECKERS_PATTERN
}	t_pattern_type;

typedef enum e_bump_type
{
	QUILT_BUMP,
}	t_bump_type;

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
	t_rgb		rgb;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	double		reflective;
	double		transparency;
	double		refractive_index;
	t_pattern	pattern;
	t_bump		bump;
}			t_material;

/* ========================================================================== */
/*                           3D OBJECT STRUCTURES                            */
/* ========================================================================== */

typedef struct s_sphere
{
	t_tuples	pos;
	double		radius;
	t_material	material;
}				t_sphere;

typedef struct s_plane
{
	t_tuples	pos;
	t_tuples	axis;
	t_material	material;
}				t_plane;

typedef struct s_cylinder
{
	t_tuples	pos;
	t_tuples	axis;
	double		radius;
	double		height;
	double		maximum;
	double		minimum;
	bool		closed;
	t_material	material;
}				t_cylinder;

typedef struct s_triangle
{
	t_tuples	p1;
	t_tuples	p2;
	t_tuples	p3;
	t_tuples	e1;
	t_tuples	e2;
	t_tuples	normal;
	t_material	material;
}				t_triangle;

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

typedef union u_obj_data
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_cube		*cube;
	t_triangle	*triangle;
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

typedef struct s_obj_node
{
	t_obj_type			type;
	t_obj_data			*data;
	double				t[2];
	bool				has_intersection;
	t_m4				matrix;
	t_computations		comp;
	struct s_obj_node	*next;
}						t_obj_node;

typedef struct s_obj_list
{
	t_obj_node	*head;
	t_obj_node	*tail;
	ssize_t		size;
}				t_obj_list;
#endif