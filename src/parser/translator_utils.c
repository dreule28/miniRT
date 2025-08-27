#include "mini_rt.h"

bool	check_norm_vec(t_tuples *vec)
{
	double	mag;

	mag = magnitude_vector(vec);
	if(mag != 1)
	{
		printf("Error\nOrientation components must be in [-1,1]\n");
		return(false);
	}
	return(true);
}
