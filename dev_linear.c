#include <stdio.h>
#include <math.h>
#include "dev_linear.h"

double dev_linear(double *radioactivity,
                  double *time,
                  int M,
                  double decay_rate)
{
    double dev = 0, sum = 0;

    for (int i = 0; i < M; i++)
        sum += pow(radioactivity[i] - (1 - time[i] / decay_rate), 2);
    dev = sqrt(sum) / M;
    return dev;
}
