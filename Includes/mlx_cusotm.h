#ifndef MLX_CUSTOM_H
# define MLX_CUSTOM_H

# include "objects.h"
# include "scene.h"
# include "../MLX42/include/MLX42/MLX42.h"

bool	init_mlx_window(t_scene *scene);
void	mlx_custom_hooks(t_scene *scene);
uint32_t create_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void	key_hook(mlx_key_data_t keydata, void *param);
void	ray_tracing(void *param);
bool	ray_hits_sphere(t_scene *scene, t_ray *ray);

#endif