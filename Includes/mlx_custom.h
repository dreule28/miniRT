#ifndef MLX_CUSTOM_H
# define MLX_CUSTOM_H

# include "objects.h"
# include "scene.h"
# include "ray_tracing.h"
# include "../MLX42/include/MLX42/MLX42.h"

// src/mlx_src/mlx_hooks.c -- BEGIN
void	key_hook(mlx_key_data_t keydata, void *param);
// src/mlx_src/mlx_hooks.c -- END

// src/mlx_src/mlx_utils.c -- BEGIN
bool	init_mlx_window(t_scene *scene);
int		get_rgba(int r, int g, int b, int a);
// src/mlx_src/mlx_utils.c -- END

// paint_pixle.c -- BEGIN
void	apply_lighting(t_scene *scene, int pixel_index);
void	paint_pixel(t_scene *scene, t_ray *ray, int pixel_index);
// paint_pixle.c -- END

// src/mlx_src/ray_tracing_loop.c -- BEGIN
void	render_rows(t_scene *scene, t_tuples *origin, t_render_params *params);
void	render_columns(t_scene *scene, t_tuples *origin, int y,
			t_render_params *params);
void	ray_tracing(t_scene *scene);
t_ray	*setup_shooting_ray(t_tuples *ray_origin, double world_x,
			double world_y, double wall_z);
void	calculate_ray(t_scene *scene, t_tuples *window_cord,
			t_tuples *world_cord);
// src/mlx_src/ray_tracing_loop.c -- END

#endif