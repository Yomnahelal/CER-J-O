#ifndef ATHLETE_H
#define ATHLETE_H

#define MAX_NAME_LENGTH 100
#define MAX_EVENT_LENGTH 20

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char event[MAX_EVENT_LENGTH];
    double time;
    int relay_position; // -1 for non-relay events
} Performance;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Performance performances[100]; // Fixed size for simplicity, can be dynamic
    int performance_count;
} Athlete;

void add_performance(Athlete *athlete);
void add_performance2(char *d);
void view_performance(const Athlete *athlete);
void show_statistics(const Athlete *athlete);

#endif // ATHLETE_H
