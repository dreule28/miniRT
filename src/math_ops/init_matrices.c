#include "mini_rt.h"

t_m4	*init_m4(void)
{
	t_m4 *m4;

	m4 = ft_calloc(1, sizeof(t_m4));
	if(!m4)
		return(NULL);
	m4->row1 = NULL;
	m4->row2 = NULL;
	m4->row3 = NULL;
	m4->row4 = NULL;
	return(m4);
}

t_m3	*init_m3(void)
{
	t_m3 *m3;

	m3 = ft_calloc(1, sizeof(t_m3));
	if(!m3)
		return(NULL);
	m3->row1 = NULL;
	m3->row2 = NULL;
	m3->row3 = NULL;
	return(m3);
}
t_m2	*init_m2(void)
{
	t_m2 *m2;

	m2 = ft_calloc(1, sizeof(t_m2));
	if(!m2)
		return(NULL);
	m2->row1 = NULL;
	m2->row2 = NULL;
	return(m2);
}
