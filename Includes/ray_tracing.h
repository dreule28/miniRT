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
}			t_ray;

// camera.c -- BEGIN
t_ray		*calculate_ray_for_pixel(t_camera *camera, double world_x,
				double world_y);
t_ray		*ray_for_pixel(t_camera *camera, double px, double py);
void		render(t_scene *scene);
t_m4		*init_view_transformation(t_scene *scene);
// camera.c -- BEGIN

// comp_to_list.c -- BEGIN
void		set_dot_product(t_obj_node *curr);
void		set_epsilon_offset(t_obj_node *curr);
bool		set_comp_to_obj(t_obj_node *curr, t_ray *ray);
// comp_to_list.c -- END

// intersec_to_list.c -- BEGIN
double		*intersect_shape(t_obj_node *curr, t_ray *ray);
bool		intersec_to_obj(t_scene *scene, t_obj_node *curr, t_ray *ray);
t_obj_list	*intersect_to_list(t_scene *scene, t_ray *ray);
t_obj_list	*intersect_to_list(t_scene *scene, t_ray *ray);
double		discri(t_ray *ray, t_sphere *sphere, double *a, double *b);
// intersec_to_list.c -- END

//intersect_obj.c -- BEGIN
double		*intersect_sphere(t_ray *ray, t_sphere *sphere);
double		*intersect_plane(t_ray *ray, t_plane *plane);
//intersect_obj.c -- END

// lighting.c -- BEGIN
t_rgb		*calculate_lighting_components(t_material material, t_light *light,
	double light_dot_normal, t_computations *comps);
t_rgb		calculate_specular(t_scene *scene, t_tuples *lightv, t_tuples *eyev,
	t_tuples *normalv);
t_material	get_obj_mat(t_scene *scene);
t_rgb		*ambient_comp(t_tuples **lightv, t_material material,
	t_light *light, t_computations *comps);
t_rgb		*lighting(t_scene *scene, t_computations *comps, t_light *light);
// lighting.c -- END

// local_normal_at.c -- BEGIN
t_tuples	*local_normal_at(t_obj_node *curr, t_tuples *object_point);
t_tuples	*local_sphere(t_obj_node *curr, t_tuples *object_point);
t_tuples	*local_plane(t_obj_node *curr, t_tuples *object_point);
// local_normal_at.c -- END

// patterns.c -- BEGIN
t_pattern   *stripe_pattern(t_rgb *color1, t_rgb *color2);
t_rgb	*stripe_at(t_pattern *pattern, t_tuples *point);
t_rgb	*stripe_at_object(t_pattern *pattern, t_m4 *matrix, t_tuples *world_point);
void    set_pattern_transform(t_pattern *pattern, t_m4 *transformation);
t_pattern *test_pattern(void);
// patterns.c -- END

// rays.c -- BEGIN
void		free_ray(t_ray *ray);
t_ray		*init_ray(t_tuples *origin, t_tuples *direction);
t_tuples	*ray_position(t_ray *ray, double time);
t_ray		*transform_ray(t_ray *ray, t_m4 *m4);
void		set_transform(t_obj_node *curr, t_m4 *translation_matrix);
// rays.c -- END

// reflection.c -- BEGIN
t_tuples	*reflect(t_tuples *in, t_tuples *normal);
t_light		*point_light(t_tuples position, t_rgb intensity);
t_material	get_material(void);
t_material	get_material_from_comps(t_computations *comps, t_scene *scene);
t_rgb	*shade_hit(t_scene *scene, t_computations *, t_light *curr, int remaining);
t_rgb	*reflected_color(t_scene *scene, t_computations *comps, int remaining);
// reflection.c -- END

// shadows.c -- BEGIN
t_ray	*get_shadow_ray(t_scene *scene, t_tuples *point, double *distance);
double		*get_transformed_intersection(t_obj_node *curr, t_ray *ray);
bool		check_shadow_intersection(double *t, double distance,double *min_t);
bool		check_objects_for_shadow(t_scene *scene, t_ray *ray,double distance);
bool		is_shadowed(t_scene *scene, t_tuples *point);
// shadows.c -- END

// sort_obj_list.c -- BEGIN
bool		should_swap_nodes(t_obj_node *curr, t_obj_node *next);
void		swap_nodes(t_obj_list *obj_list, t_obj_node *prev,
				t_obj_node *curr, t_obj_node *next);
void		swap_pointers(t_obj_node **curr, t_obj_node **prev);
t_obj_list	*sort_obj_list(t_obj_list *obj_list);
// sort_obj_list.c -- END

// surface_normals.c -- BEGIN
void		free_tuple(t_tuples *tuple);
t_tuples	*normal_at(t_obj_node *curr, t_tuples *world_point);
// surface_normals.c -- END

// view_tranformation.c -- BEGIN
t_m4		*view_transformation(t_tuples *from, t_tuples *to, t_tuples *up);
t_m4		*create_view_matrix(t_tuples *left, t_tuples *forward,
				t_tuples *true_up);
// view_tranformation.c -- END
#endif