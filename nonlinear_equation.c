#include <stdio.h>
#include <math.h>
#include "model.h"
#include "nonlinear_equation.h"


double nonlinear_equation(double *radioactivity,
                          double *time,
                          int N,
                          double precision,
                          double left,
                          double right)
{
    double decay_time = 0;

    while(fabs(right - left) > precision)
    {
        decay_time = (right + left)/2;
        if (model(radioactivity, time, N, decay_time) *
                model(radioactivity, time, N, left) <= 0)
        {
            right = decay_time;
        }
        else if (model(radioactivity, time, N, decay_time) *
                    model(radioactivity, time, N, right) <= 0)
        {
            left = decay_time;
        }
    }
    return decay_time;
}
