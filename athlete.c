#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "athlete.h"
#include "file_operations.h"
#include "statistics.h"
#include "utils.h"
void add_performance2(char* d) {
//variables necessaires pour les ajouts des performances des atheletes qui ont fait une course relais
Athlete athlete;
    athlete.performance_count=0;
    char name[MAX_NAME_LENGTH];
//
// Nettoyer le tampon d'entree si necessaire dans le cas de la saisie d'une chaine avec fgets
int c;
    while ((c = getchar()) != '\n' && c != EOF);
//fin nettoyage
         printf("Enter le nom de l'athlete ");
                if (fgets(name, sizeof(name), stdin) != NULL) {
                    // Supprimez le caractere de nouvelle ligne s'il est present
                    size_t len = strlen(name);
                    if (len > 0 && name[len - 1] == '\n') {
                        name[len - 1] = '\0';
                    }
                    strncpy(athlete.name, name, MAX_NAME_LENGTH - 1);
                    athlete.name[MAX_NAME_LENGTH - 1] = '\0'; // Assurez-vous que la cha�ne se termine par un caractere nul
                }

                athlete.performance_count+=1;




    Performance p;
    strcpy(p.date, d);// par defaut on mets la date deja saisie lors de la saisit du premier athlete de la course Relais

    strcpy(p.event, "Relais");// par defaut on mets Relais, il n'a pas le droit de changer


    printf("Entrer le temps: ");
    scanf("%lf", &p.time);
    do
    {printf("Entrer la position: ");
    scanf("%d", &p.relay_position);
    }while(p.relay_position<2 || p.relay_position>4);// verifier si la position est bien entre 2 et 4

    athlete.performances[athlete.performance_count] = p;
    athlete.performance_count++;
    save_performance(&athlete);
}
void add_performance(Athlete *athlete) {

    Performance p;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", p.date);

    //controle ici la saisie
    do
    {
        
        printf("Entrer l epreuve:100M/400M/5000/Marathon/Relais ");
        scanf("%19s", p.event);
    }while(strcmp(p.event, "100M") != 0 && strcmp(p.event, "400M") != 0 &&
            strcmp(p.event, "5000") != 0 && strcmp(p.event, "Marathon") != 0 &&
            strcmp(p.event, "Relais") != 0);

    printf("Enter time: ");
    scanf("%lf", &p.time);

    if (strcmp(p.event,"Relais")==0)
    {printf("Entrer la position: ");
    scanf("%d", &p.relay_position);
    }else//(-1 si l'epreuve est differente du relais)
    p.relay_position=-1;

    athlete->performances[athlete->performance_count] = p;
    athlete->performance_count++;
    save_performance(athlete);

    if (p.relay_position!=-1)
    {for (int j=0;j<3;j++)// ici on va demander a l'utilisateur de saisir 3 autres performances
        add_performance2(p.date);

    }
/*    if (p.relay_position!=-1 && nb<4)
    {nb++;
// Nettoyer le tampon d'entree si necessaire
int c;
    while ((c = getchar()) != '\n' && c != EOF);
//fin nettoyage
         printf("Enter le nom de l'athlete suivant N�: %d ",nb);
                if (fgets(nameR, sizeof(nameR), stdin) != NULL) {
                    // Supprimez le caractere de nouvelle ligne s'il est present
                    size_t len = strlen(nameR);
                    if (len > 0 && nameR[len - 1] == '\n') {
                        nameR[len - 1] = '\0';
                    }
                    strncpy(athleteR.name, nameR, MAX_NAME_LENGTH - 1);
                    athleteR.name[MAX_NAME_LENGTH - 1] = '\0'; // Assurez-vous que la cha�ne se termine par un caract�re nul
                }

                athleteR.performance_count+=1;
                add_performance(&athleteR,nb);
                printf("Performance ajoutee avec Succes\n");
    }//fin if
*/
}

void view_performance(const Athlete *athlete) {
    for (int i = 0; i < athlete->performance_count; i++) {
        Performance p = athlete->performances[i];
        if (p.relay_position!=-1)
        printf("%s %s %.2f secondes %d\n", p.date, p.event, p.time, p.relay_position);
        else
        printf("%s %s %.2f secondes\n", p.date, p.event, p.time);

    }
}

void show_statistics(const Athlete *athlete) {
    double best, worst, average;
    char event[MAX_EVENT_LENGTH];
    printf("Enter event for statistics: ");
    scanf("%19s", event);
    calculate_statistics(athlete, event, &best, &worst, &average);
    printf("Best time: %.2f\n", best);
    printf("Worst time: %.2f\n", worst);
    printf("Average time: %.2f\n", average);
}
