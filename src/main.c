#include "mini_rt.h"


int	main(int argc, char **argv)
{
	t_scene	*scene;

	(void)argc;
	(void)argv;
	scene = ft_calloc(1, sizeof(t_scene));
	scene->current_r = 255;
    scene->current_g = 255;
    scene->current_b = 255;
	scene->brightness = 255;
    scene->mlx = NULL;
    // scene->img = NULL;
    // scene->obj_list = NULL;
    // scene->ambi_light = (t_ambi_light){0};
    // scene->camera = (t_camera){0};
    // scene->light = (t_light){0};
    
	if(!init_mlx_window(scene))
		return(1);
	write(2, "123123", 5);
	mlx_custom_hooks(scene);
	mlx_loop(scene->mlx);
	mlx_terminate(scene->mlx);
	// close_scene(scene);
	return (0);
}
