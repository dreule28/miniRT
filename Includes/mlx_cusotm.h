#ifndef MLX_CUSTOM_H
# define MLX_CUSTOM_H

# include "objects.h"
# include "scene.h"
# include "../MLX42/include/MLX42/MLX42.h"

t_sphere	*ray_hits_sphere(t_scene *scene, t_ray *ray);

// src/mlx_src/ray_tracing_loop.c -- BEGIN
void	ray_tracing(t_scene *scene);
void	paint_pixel(t_scene *scene, t_ray *ray, int pixel_index);
t_ray	*setup_shooting_ray(t_tuples *ray_origin, double world_x, double world_y, double wall_z);
void	calculate_ray(t_scene *scene, t_tuples *window_cord, t_tuples *world_cord);
// src/mlx_src/ray_tracing_loop.c -- END

// src/mlx_src/mlx_utils.c -- BEGIN
bool	init_mlx_window(t_scene *scene);
void	mlx_custom_hooks(t_scene *scene);
int		get_rgba(int r, int g, int b, int a);
void	print_terminal_update(t_scene *scene);
// src/mlx_src/mlx_utils.c -- END

// src/mlx_src/mlx_hooks.c -- BEGIN
void	key_hook(mlx_key_data_t keydata, void *param);
void	mlx_custom_hooks(t_scene *scene);
void	update_camera(void *param);
void	cursor_hook(double xpos, double ypos, void *param);
void	scroll_hook(double xdelta, double ydelta, void *param);
// src/mlx_src/mlx_hooks.c -- END

#endif