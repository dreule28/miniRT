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

typedef struct s_axis_params
{
	double	xtmin;
	double	xtmax;
	double	ytmin;
	double	ytmax;
	double	ztmin;
	double	ztmax;
}	t_axis_params;

/* Ray structure for ray tracing calculations */
typedef struct s_ray
{
	t_tuples	origin;	/* Starting point of the ray */
	t_tuples	direction;	/* Direction vector of the ray */
}			t_ray;

// camera.c -- BEGIN
void		calculate_ray_for_pixel(t_ray *ray, t_m4 inv, double world_x,
				double world_y);
void		ray_for_pixel(t_ray *ray, t_camera *camera, t_m4 inv, double px,
				double py);
void		render(t_scene *scene);
void	init_view_transformation(t_m4 *matrix, t_scene *scene);
// camera.c -- BEGIN

// comp_to_list.c -- BEGIN
void		set_dot_product(t_obj_node *curr);
void		set_epsilon_offset(t_obj_node *curr);
bool		set_comp_to_obj(t_obj_node *curr, t_ray *ray);
// comp_to_list.c -- END

// cone_cal.c -- BEGIN
bool	cone_intersec_cal(t_obj_node *node, t_ray ray);
int		check_cone_height(t_obj_node *node, t_ray ray, t_cone cone);
bool	intersect_cone(t_obj_node *node, t_ray ray, t_cone cone);
void	local_cone(t_tuples *normal, t_obj_node curr, t_tuples p);
// cone_cal.c -- END

// cubes.c -- BEGIN
bool		local_intersect(t_obj_node *node, t_ray ray);
void		check_axis(double origin, double direction, double *tmax,
				double *tmin);
// cubes.c -- END

// cylinder_cal.c --BEGIN
bool		check_cap(t_ray ray, double t);
int			intersect_caps(t_ray ray, t_cylinder cylinder, double *out);
bool		cylinder_intersec_cal(t_obj_node *node, t_ray ray);
int	check_cylinder_height(t_obj_node *node, t_ray ray, t_cylinder cylinder);
bool	cylinder_cap_cal(t_obj_node *node, t_ray ray, t_cylinder cylinder);
// cylinder_cal.c --END

// intersec_to_list.c -- BEGIN
bool		intersect_shape(t_obj_node *curr, t_ray ray);
bool		intersec_to_obj(t_obj_node *curr, t_ray ray);
t_obj_list	*intersect_to_list(t_scene *scene, t_ray *ray);
// intersec_to_list.c -- END

//intersect_obj.c -- BEGIN
double		discri(t_ray ray, t_sphere sphere, double *a, double *b);
bool		intersect_sphere(t_obj_node *node, t_ray ray, t_sphere sphere);
bool		intersect_plane(t_obj_node *node, t_ray ray);
bool		intersect_cylinder(t_obj_node *node, t_ray ray, t_cylinder cylinder);
//intersect_obj.c -- END

// lighting.c -- BEGIN
void	calculate_lighting_components(t_rgb *result, t_material material, t_light light,
		double light_dot_normal);
void	calculate_specular(t_rgb *specular, t_scene *scene, t_tuples lightv,
			t_computations comps);
t_material	get_obj_mat(t_scene *scene);
void	ambient_comp(t_rgb *result, t_material material, t_light light);
void	lighting(t_rgb *res, t_scene *scene, t_computations comps,
			t_light light);
// lighting.c -- END

// local_normal_at.c -- BEGIN
void	local_normal_at(t_tuples *local_normal_at, t_obj_node curr,
				t_tuples object_point);
void	local_sphere(t_tuples *normal, t_tuples object_point);
void	local_plane(t_tuples *local_normal_at);
void	local_cylinder(t_tuples *normal, t_obj_node curr, t_tuples object_point);
void	local_cube(t_tuples *local_normal_at, t_tuples object_point);
// local_normal_at.c -- END

// init_patterns.c -- BEGIN
void	stripe_pattern(t_pattern *pattern, t_rgb color1, t_rgb color2);
void	gradient_pattern(t_pattern *pattern, t_rgb color1, t_rgb color2);
void	ring_pattern(t_pattern *pattern, t_rgb color1, t_rgb color2);
void	checkers_pattern(t_pattern *pattern, t_rgb color1, t_rgb color2);

// init_patterns.c -- END

// pattern_utils.c -- BEGIN
void		select_pattern(t_rgb *pattern_color, t_pattern pattern,
			t_tuples pattern_point);
void		pattern_at_shape(t_rgb *rgb, t_pattern pattern, t_obj_node shape,
				t_tuples world_point);
// pattern_utils.c -- END

// patterns.c -- BEGIN
void	stripe_at(t_rgb *color, t_pattern pattern, t_tuples point);
void	gradient_at(t_rgb *result, t_pattern pattern, t_tuples point);
void	ring_at(t_rgb *color, t_pattern pattern, t_tuples point);
void	checkers_at(t_rgb *color, t_pattern pattern, t_tuples point);
// patterns.c -- END

// rays.c -- BEGIN
void		free_ray(t_ray *ray);
void	init_ray(t_ray *ray, t_tuples origin, t_tuples direction);
void		ray_position(t_tuples *point, t_ray *ray, double time);
void	transform_ray(t_ray *new_ray, t_ray old_ray, t_m4 m4);
void		set_transform(t_obj_node *curr, t_m4 *translation_matrix);
// rays.c -- END

// reflection.c -- BEGIN
void		reflect(t_tuples *result, t_tuples in, t_tuples normal);
t_light		*point_light(t_tuples position, t_rgb intensity);
t_material	get_material(void);
t_rgb		*shade_hit(t_scene *scene, t_light curr, int remaining);
void		reflected_color(t_rgb *reflected, t_scene *scene,
				t_computations comps, int remaining);
// reflection.c -- END

// shadows.c -- BEGIN
void		get_shadow_ray(t_ray *ray, t_tuples point, double *distance,
				t_light curr);
bool		get_transformed_intersection(t_obj_node *curr, t_ray ray);
bool		check_shadow_intersection(t_obj_node *node, double dist, double *min_t);
bool		check_objects_for_shadow(t_scene *scene, t_ray ray,double distance);
bool		is_shadowed(t_scene *scene, t_tuples point, t_light curr);
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
void	normal_at(t_tuples *normal, t_obj_node curr, t_tuples world_point);
// surface_normals.c -- END

// utils.c -- BEGIN
t_material	get_material_from_comps(t_computations comps, t_obj_list *obj_list);
// utils.c -- END

// view_tranformation.c -- BEGIN
void	view_transformation(t_m4 *matrix, t_tuples from, t_tuples to, t_tuples up);
void	create_view_matrix(t_m4 *orientation, t_tuples left, t_tuples forward,
			t_tuples true_up);
// view_tranformation.c -- END

// bonus_scene.c -- BEGIN
void bonus_scene1(t_scene *scene);
void	bonus_scenes(t_scene *scene, char *str);
// bonus_scene.c -- END

// more_scene_objs.c -- BEGIN
void	p3_plane(t_scene *scene);
void	c1_cylinder(t_scene *scene);
void	c1_cube(t_scene *scene);
// more_scene_objs.c -- END

// scene_objs.c -- BEGIN
void	s1_sphere(t_scene *scene);
void	s2_sphere(t_scene *scene);
void	s3_sphere(t_scene *scene);
void	p1_plane(t_scene *scene);
void	p2_plane(t_scene *scene);
// scene_objs.c -- END

#endif