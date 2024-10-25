#include <math.h>
#include <stdio.h>
#include "experiment.h"

int experiment (double *radioactivity,
                double *time,
                double start_time,
                double end_time,
                double step)
{
    int N = 0;
    for (double t = start_time; t < end_time; t += step)
    {
        time[N] = t;

        radioactivity[N] = 1 * pow (M_E, -(t / BETTA));

        N += 1;
    }

    return N;
}
