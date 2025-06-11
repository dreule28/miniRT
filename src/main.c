#include "mini_rt.h"


int	main(int argc, char **argv)
{
	t_scene	*scene;

	(void)argc;
	(void)argv;
	scene = ft_calloc(1, sizeof(t_scene));
	scene->mlx = NULL;
	if(!init_mlx_window(scene))
		return(1);
	mlx_custom_hooks(scene);
	mlx_loop(scene->mlx);
	mlx_terminate(scene->mlx);
	// close_scene(scene);
	return (0);
}
