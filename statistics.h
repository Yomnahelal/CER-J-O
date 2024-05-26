#ifndef STATISTICS_H
#define STATISTICS_H

#include "athlete.h"

void calculate_statistics(const Athlete *athlete, const char *event, double *best, double *worst, double *average);

#endif // STATISTICS_H
