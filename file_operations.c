#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"

void save_performance(const Athlete *athlete) {
    char filename[MAX_NAME_LENGTH + 4];// + 4 du ".txt"
   // snprintf(filename, sizeof(filename), "%s.txt", athlete->name);
       strcpy(filename, athlete->name); // Copie du nom de l'athlete dans filename
    strcat(filename, ".txt"); // Concat�nation de l'extension .txt
       FILE *file = fopen(filename, "a");// append c'est a dire mise a jour

    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    Performance p = athlete->performances[athlete->performance_count - 1];
    fprintf(file, "%s,%s,%.2f,%d\n", p.date, p.event, p.time, p.relay_position);// ecriture dans le fichier
    fclose(file);// fermer le fichier
}

void load_athlete(Athlete *athlete, const char *name) {// charge les donnees a partir du fichier en question et sauvegarde ces donnees dans une variable athlete
    char filename[MAX_NAME_LENGTH + 4];// correspond au nom du fichier texte a ouvrir
    snprintf(filename, sizeof(filename), "%s.txt", name);
    FILE *file = fopen(filename, "r"); // ouverture en mode lecture (read)

    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    strcpy(athlete->name, name);
    athlete->performance_count = 0;
    while (fscanf(file, "%10[^,],%19[^,],%lf,%d\n", athlete->performances[athlete->performance_count].date,
                  athlete->performances[athlete->performance_count].event,
                  &athlete->performances[athlete->performance_count].time,
                  &athlete->performances[athlete->performance_count].relay_position) != EOF) {
        athlete->performance_count++;
    }

    fclose(file);
}

void list_athletes() {
    system("ls *.txt | sed 's/\\.txt$//'"); // Only works on Unix-like systems
}
