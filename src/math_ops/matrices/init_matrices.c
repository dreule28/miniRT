#include "mini_rt.h"

t_m2	*init_m2(void)
{
	t_m2	*m2;

	m2 = ft_calloc(1, sizeof(t_m2));
	if (!m2)
		return (NULL);
	m2->head = NULL;
	m2->tail = NULL;
	m2->size = 0;
	return (m2);
}

t_m3	*init_m3(void)
{
	t_m3	*m3;

	m3 = ft_calloc(1, sizeof(t_m3));
	if (!m3)
		return (NULL);
	m3->head = NULL;
	m3->tail = NULL;
	m3->size = 0;
	return (m3);
}

t_m4	*init_m4(void)
{
	t_m4	*m4;

	m4 = ft_calloc(1, sizeof(t_m4));
	if (!m4)
		return (NULL);
	m4->head = NULL;
	m4->tail = NULL;
	m4->size = 0;
	return (m4);
}
