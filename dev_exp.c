#include <math.h>
#include "dev_exp.h"

double dev_exp(double *radioactivity,
               double *time,
               int M,
               double decay_time)
{
    double dev = 0, sum = 0;

    for (int i = 0; i < M; i++)
        sum += pow(radioactivity[i] - exp(-time[i] / decay_time), 2);

    dev = sqrt(sum) / M;
    return dev;
}
