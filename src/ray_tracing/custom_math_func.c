#include "mini_rt.h"

t_tuples *create_vector(double x ,double y ,double z)
{
	t_tuples *vector;

	vector = ft_calloc(1, sizeof(t_tuples));
	if(!vector)
		return(NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->w = VECTOR;
	return(vector);
}

t_tuples *create_point(double x ,double y ,double z)
{
	t_tuples *point;

	point = ft_calloc(1, sizeof(t_tuples));
	if(!point)
		return(NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = POINT;
	return(point);
}

t_rgb *create_rgb(double r ,double g ,double b)
{
	t_rgb *rgb;

	rgb = ft_calloc(1, sizeof(t_rgb));
	if(!rgb)
		return(NULL);
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return(rgb);
}

bool	ft_tupcmp(t_tuples *tuples1, t_tuples *tuples2)
{
	if(tuples1->w == tuples2->w)
		return(false);
	else if(tuples1->x == tuples2->x)
		return(false);
	else if(tuples1->y == tuples2->y)
		return(false);
	else if(tuples1->z == tuples2->z)
		return(false);
	return(true);
}

t_tuples	*tup_add(t_tuples *tuples1, t_tuples *tuples2)
{
	t_tuples *new_tuples;

	new_tuples = ft_calloc(1, sizeof(t_tuples));
	if(!new_tuples)
		return(NULL);
	new_tuples->x = tuples1->x + tuples2->x;
	new_tuples->y = tuples1->y + tuples2->y;
	new_tuples->z = tuples1->z + tuples2->z;
	new_tuples->w = tuples1->w +tuples2->w;
	return(new_tuples);
}