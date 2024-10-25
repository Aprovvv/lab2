#include "precision_analysis.h"
#include "nonlinear_equation.h"
#include "linear_equation.h"
#include "dev_linear.h"
#include "dev_exp.h"

#include <stdio.h>

double precision_analysis (double *radioactivity,
                           double *time,
                           int N,
                           double precision,
                           double left,
                           double right)
{
    double decay_time, decay_rate, dexp, dlin;

    for (int i = 10; i <= N; i++)
    {
        decay_time = nonlinear_equation(radioactivity, time, i, precision, left, right);
        decay_rate = linear_equation(radioactivity, time, i);

        dexp = dev_exp(radioactivity, time, i, decay_time);
        dlin = dev_linear(radioactivity, time, i, decay_rate);

        if (2*dexp <= dlin)
            return time[i];
    }

    return 0;
}
