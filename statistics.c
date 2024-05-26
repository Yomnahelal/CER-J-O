#include <float.h>
#include "statistics.h"

void calculate_statistics(const Athlete *athlete, const char *event, double *best, double *worst, double *average) {
    double sum = 0;
    int count = 0;
    *best = DBL_MAX;
    *worst = 0;

    for (int i = 0; i < athlete->performance_count; i++) {
        Performance p = athlete->performances[i];
        if (strcmp(p.event, event) == 0) {
            if (p.time < *best) {
                *best = p.time;
            }
            if (p.time > *worst) {
                *worst = p.time;
            }
            sum += p.time;
            count++;
        }
    }

    if (count > 0) {
        *average = sum / count;
    } else {
        *average = 0;
    }
}
