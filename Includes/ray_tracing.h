#ifndef RAY_TRACING_H
# define RAY_TRACING_H

typedef struct s_m2	t_m2;
typedef struct s_m3	t_m3;
typedef struct s_m4	t_m4;

typedef struct s_render_params
{
	double	pixel_size;
	double	half;
	double	wall_z;
}			t_render_params;

/* Physics simulation structure for projectile motion*/
typedef struct s_projectile
{
	t_tuples	*position; /* Current position in 3D space */
	t_tuples	*velocity; /* Current velocity vector */
}			t_projectile;

/* Environmental forces affecting projectile motion */
typedef struct s_environment
{
	t_tuples	*gravity;	/* Gravitational force vector */
	t_tuples	*wind;		/* Wind force vector */
}			t_environment;

/* Ray structure for ray tracing calculations */
typedef struct s_ray
{
	t_tuples	*origin;	/* Starting point of the ray */
	t_tuples	*direction;	/* Direction vector of the ray */
}					t_ray;

// comp_to_list.c -- BEGIN
bool	set_comp_to_obj(t_obj_node *curr, t_ray *ray);
// comp_to_list.c -- END

// intersec_sphere.c -- BEGIN
bool		setup_intersec_sphere(t_scene *scene, t_obj_node *curr,
				t_ray *ray);
// intersec_sphere.c -- END

// intersec_to_list.c -- BEGIN
bool		set_intersection_to_obj(t_scene *scene, t_obj_node *curr,
				t_ray *ray);
// intersec_to_list.c -- END

// intersection.c -- BEGIN
double		discri(t_ray *ray, t_sphere *sphere, double *a, double *b);
double		*intersect_sphere(t_ray *ray, t_sphere *sphere);
t_obj_list	*sort_obj_list(t_obj_list *obj_list);
t_obj_list	*intersect_to_list(t_scene *scene, t_ray *ray);
double		*hit_obj(t_scene *scene);
// intersection.c -- END

// lighting.c -- BEGIN
t_rgb		*calculate_lighting_components(t_material material, t_light *light,
				double light_dot_normal);
t_rgb		calculate_specular(t_scene *scene, t_tuples *lightv, t_tuples *eyev,
				t_tuples *normalv);
t_rgb		*lighting(t_scene *scene, t_computations *comps, t_light *light);
t_rgb		shade_hit(t_scene *scene, t_computations *comps);
// lighting.c -- END

// rays.c -- BEGIN
void		free_ray(t_ray *ray);
t_ray		*init_ray(t_tuples *origin, t_tuples *direction);
t_tuples	*ray_position(t_ray *ray, double time);
t_ray		*transform_ray(t_ray *ray, t_m4 *m4);
void		set_transform(t_sphere *sphere, t_m4 *matrix);
// rays.c -- END

// reflection.c -- BEGIN
t_tuples	*reflect(t_tuples *in, t_tuples *normal);
t_light		*point_light(t_tuples position, t_rgb intensity);
t_material	get_material(void);
// reflection.c -- END

// sort_obj_list.c -- BEGIN
bool		should_swap_nodes(t_obj_node *curr, t_obj_node *next);
void		swap_nodes(t_obj_list *obj_list, t_obj_node *prev,
				t_obj_node *curr, t_obj_node *next);
void		swap_pointers(t_obj_node **curr, t_obj_node **prev);
t_obj_list	*sort_obj_list(t_obj_list *obj_list);
// sort_obj_list.c -- END

// surface_normals.c -- BEGIN
void		free_tuple(t_tuples *tuple);
t_tuples	*get_world_normal(t_m4 *inverse, t_tuples *obj_point);
t_tuples	*normal_at(t_sphere *sphere, t_tuples *point);
// surface_normals.c -- END

#endif