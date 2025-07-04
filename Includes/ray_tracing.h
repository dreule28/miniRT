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

// ray_tracing/ray_tracing.c
void			ray_tracing(void *param);

// ray_tracing/custom_mlx_functions.c
bool			init_mlx_window(t_scene *scene);
int				get_rgba(int r, int g, int b, int a);
void			mlx_custom_hooks(t_scene *scene);

// ray_tracing/keyboard_hooks.c
void			key_hook(mlx_key_data_t keydata, void *param);
void			scroll_hook(double xdelta, double ydelta, void *param);

// ray_tracing/projectile.c
t_projectile	*create_projectile(t_tuples *position, t_tuples *velocity);
t_environment	*create_environment(t_tuples *gravity, t_tuples *wind);
t_projectile	*tick(t_environment *env, t_projectile *proj);

#endif