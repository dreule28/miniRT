#ifndef RAY_TRACING_H
# define RAY_TRACING_H

typedef struct s_projectile
{
	t_tuples	*position;
	t_tuples	*velocity;
}				t_projectile;

typedef struct s_environment
{
	t_tuples	*gravity;
	t_tuples	*wind;
}				t_environment;

typedef struct s_ray
{
	t_tuples	*origin;
	t_tuples	*direction;
}				t_ray;


// rays.c -- BEGIN
void		free_ray(t_ray *ray);
t_ray		*init_ray(t_tuples *origin, t_tuples *direction);
t_tuples	*ray_position(t_ray *ray, double time);
// rays.c -- END


#endif