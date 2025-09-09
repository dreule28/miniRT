/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:13:52 by dreule            #+#    #+#             */
/*   Updated: 2025/09/09 15:14:30 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "custom_math.h"
# include "objects.h"

typedef struct s_ambi_light
{
	double			ratio;
	t_rgb			rgb;
}					t_ambi_light;

typedef struct s_light
{
	t_tuples		pos;
	double			intensity;
	t_rgb			rgb;
	struct s_light	*next;
}					t_light;

typedef struct s_light_list
{
	t_light	*head;
	t_light	*tail;
	ssize_t	size;
}			t_light_list;

typedef struct s_camera
{
	t_tuples		pos;
	t_tuples		orientation_vector;
	double			fov;
	double			hsize;
	double			vsize;
	t_m4			matrix;
	double			pixel_size;
	double			half_width;
	double			half_height;
}					t_camera;

typedef struct s_scene
{
	int				syntax_count;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_ambi_light	ambi_light;
	t_camera		camera;
	t_light_list	*light_list;
	t_obj_list		*obj_list;
}					t_scene;

#endif