#include <stdio.h>
#include <math.h>

double model(double* radioctivity, double* time, int N, double point)
{
    double sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += time[i] * exp(-time[i]/point) *
                    (radioctivity[i] - exp(-time[i]/point ));
    }
    return sum;
}
