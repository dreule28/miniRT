
// ray_tracing/ray_tracing.c
void	ray_tracing(void *param);


// ray_tracing/mlx_functions.c
bool	init_mlx_window(t_scene *scene);
uint32_t create_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void	mlx_custom_hooks(t_scene *scene);

// ray_tracing/keyboard_hooks.c
void	key_hook(mlx_key_data_t keydata, void *param);
void	scroll_hook(double xdelta, double ydelta, void *param);