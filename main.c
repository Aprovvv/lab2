#include <stdio.h>
#include <math.h>

#include "experiment.h"
#include "linear_equation.h"
#include "add_noise.h"
#include "model.h"
#include "nonlinear_equation.h"
#include "precision_analysis.h"

#define SIZE 100
#define precision 0.0001

int main(void)
{
    double start_time, end_time, step, left_board, right_board;
    double decay_time, decay_rate, time_diff;
    double radioactivity[SIZE] = {0};
    double time[SIZE] = {0};
    int N;

    printf("Enter start_time:\n");
    scanf("%lf", &start_time);
    printf("Enter end_time:\n");
    scanf("%lf", &end_time);
    printf("Enter step:\n");
    scanf("%lf", &step);
    printf("Enter inteval:\n");
    scanf("%lf%lf", &left_board, &right_board);

    N = experiment(radioactivity, time, start_time, end_time, step);
    add_noise(radioactivity, N);
    decay_time = nonlinear_equation(radioactivity, time, N,
                                    precision, left_board, right_board);
    decay_rate = linear_equation(radioactivity, time, N);
    time_diff = precision_analysis(radioactivity, time, N,
                                    precision, left_board, right_board);

    fprintf(stderr, "decay_time: %.3f\n", decay_time);
    fprintf(stderr, "decay_rate: %.3f\n", decay_rate);
    fprintf(stderr, "time_difference: %lg\n", time_diff);

    return 0;
}
