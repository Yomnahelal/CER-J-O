#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "athlete.h"

void save_performance(const Athlete *athlete);
void load_athlete(Athlete *athlete, const char *name);
void list_athletes();

#endif // FILE_OPERATIONS_H
