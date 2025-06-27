#include "mini_rt.h"

/*calculates the determenant of an 2x2 matrix*/
double	m_dmt(t_m2 *m2)
{
	double	x;
	double	y;
	double	result;

	x = m2->col0->x * m2->col1->y;
	y = m2->col0->y * m2->col1->x;
	result = x - y;
	return (result);
}

double	m3_dmt(t_m3 *m3)
{
	double	result;
	double	x;
	double	y;
	double	z;

	x = m3->col0->x * m3_cofactor(m3, 0, 0);
	y = m3->col1->x * m3_cofactor(m3, 1, 0);
	z = m3->col2->x * m3_cofactor(m3, 2, 0);
	result = x + y + z;
	return (result);
}

double m4_dmt(t_m4 *m4)
{
    double result;
    double x;
    double y;
    double z;
    double w;

    printf("\n=== 4x4 Matrix Determinant Calculation ===\n");
    printf("Matrix:\n");
    printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->x, m4->col1->x, m4->col2->x, m4->col3->x);
    printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->y, m4->col1->y, m4->col2->y, m4->col3->y);
    printf("[%.2f  %.2f  %.2f  %.2f]\n", m4->col0->z, m4->col1->z, m4->col2->z, m4->col3->z);
    printf("[%.2d  %.2d  %.2d  %.2d]\n", m4->col0->w, m4->col1->w, m4->col2->w, m4->col3->w);

    printf("\nCofactor calculations:\n");
    printf("cofactor(0,0) = %.2f\n", m4_cofactor(m4, 0, 0));
    printf("cofactor(1,0) = %.2f\n", m4_cofactor(m4, 1, 0));
    printf("cofactor(2,0) = %.2f\n", m4_cofactor(m4, 2, 0));
    printf("cofactor(3,0) = %.2f\n", m4_cofactor(m4, 3, 0));

    x = m4->col0->x * m4_cofactor(m4, 0, 0);
    y = m4->col1->x * m4_cofactor(m4, 1, 0);
    z = m4->col2->x * m4_cofactor(m4, 2, 0);
    w = m4->col3->x * m4_cofactor(m4, 3, 0);

    printf("\nTerms:\n");
    printf("x = %.2f * %.2f = %.2f\n", m4->col0->x, m4_cofactor(m4, 0, 0), x);
    printf("y = %.2f * %.2f = %.2f\n", m4->col1->x, m4_cofactor(m4, 1, 0), y);
    printf("z = %.2f * %.2f = %.2f\n", m4->col2->x, m4_cofactor(m4, 2, 0), z);
    printf("w = %.2f * %.2f = %.2f\n", m4->col3->x, m4_cofactor(m4, 3, 0), w);

    result = x + y + z + w;
    printf("\nFinal result: %.2f + %.2f + %.2f + %.2f = %.2f\n", x, y, z, w, result);
    return (result);
}
