#include <stdio.h>
#include <assert.h>
#include "linear_equation.h"

double linear_equation (double *radioactivity, double *time, int N)
{
    double a = 0, b = 0;

    for (int i = 0; i < N; i++)
    {
        a += time[i] * time[i];
        b += time[i] * (1 - radioactivity[i]);
    }

    assert(a != 0);
    assert(b != 0);

    return a / b;
}
