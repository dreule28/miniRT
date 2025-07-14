#ifndef RAY_TRACING_H
# define RAY_TRACING_H

typedef struct s_m2	t_m2;
typedef struct s_m3	t_m3;
typedef struct s_m4	t_m4;

/* Physics simulation structure for projectile motion */
typedef struct s_projectile
{
	t_tuples	*position;		/* Current position in 3D space */
	t_tuples	*velocity;		/* Current velocity vector */
}				t_projectile;

/* Environmental forces affecting projectile motion */
typedef struct s_environment
{
	t_tuples	*gravity;		/* Gravitational force vector */
	t_tuples	*wind;			/* Wind force vector */
}				t_environment;

/* Ray structure for ray tracing calculations */
typedef struct s_ray
{
	t_tuples	*origin;		/* Starting point of the ray */
	t_tuples	*direction;		/* Direction vector of the ray */
}				t_ray;

// intersec_sphere.c -- BEGIN
bool		setup_intersec_sphere(t_scene *scene, t_obj_node *curr, t_ray *ray);
// intersec_sphere.c -- END

// intersec_to_list.c -- BEGIN
bool		set_intersection_to_obj(t_scene *scene, t_obj_node *curr, t_ray *ray);
// intersec_to_list.c -- END

// intersection.c -- BEGIN
double		discri(t_ray *ray, t_sphere *sphere, double *a, double *b);
double		*intersect_sphere(t_ray *ray, t_sphere *sphere);
t_obj_list	*intersect_to_list(t_scene *scene, t_ray *ray);
double		*hit_obj(t_scene *scene);
// intersection.c -- END

// rays.c -- BEGIN
void		free_ray(t_ray *ray);
t_ray		*init_ray(t_tuples *origin, t_tuples *direction);
t_tuples	*ray_position(t_ray *ray, double time);
t_ray		*transform_ray(t_ray *ray, t_m4 *m4);
void		set_transform(t_sphere *sphere, t_m4 *matrix);
// rays.c -- END

// reflection.c -- BEGIN
t_tuples	*reflect(t_tuples *in, t_tuples *normal);
// reflection.c -- END

// surface_normals.c -- BEGIN
void		free_tuple(t_tuples *tuple);
t_tuples	*get_world_normal(t_m4 *inverse, t_tuples *obj_point);
t_tuples	*normal_at(t_sphere *sphere, t_tuples *point);
// surface_normals.c -- END

#endif