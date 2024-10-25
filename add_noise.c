#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "add_noise.h"

void add_noise (double *radioactivity, int N)
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        double n = rand () % 200001;
        radioactivity[i] += ((n / 100000 - 1) * 0.05);
    }
}
