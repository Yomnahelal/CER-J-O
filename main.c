#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "athlete.h"
#include "file_operations.h"
#include "utils.h"

int main() {
    int choice;
    Athlete athlete;
    athlete.performance_count=0;// initialisation de cette variable
    char name[MAX_NAME_LENGTH];//chaine de caract�re de taille 100

    while (1) {
        //clear_screen();
        printf("Veuillez choisir une option\n");
        printf("1. Add Performance\n");
        printf("2. View Performance\n");
        printf("3. Show Statistics\n");
        printf("4. List Athletes\n");
        printf("5. Afficher historique Athlete\n");
        printf("6. Exit\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Entrer le nom de l'athlete: ");
                if (fgets(name, sizeof(name), stdin) != NULL) {
                    // Supprimez le caract�re de nouvelle ligne s'il est pr�sent
                    size_t len = strlen(name);
                    if (len > 0 && name[len - 1] == '\n') {
                        name[len - 1] = '\0';
                    }
                    strncpy(athlete.name, name, MAX_NAME_LENGTH - 1);//pour copier la chaine name dans le champ name de la variable athlete de type structure
                    athlete.name[MAX_NAME_LENGTH - 1] = '\0'; // Assurez-vous que la cha�ne se termine par un caract�re nul
                    // ou simplement strcpy(athlete.name, name); au lieu des 2 pr�c�dentes instructions
                }

               // athlete.performance_count+=1;
                add_performance(&athlete);
                printf("Performance ajoutee avec Succes\n");

                break;
            case 2:
               //inutile sauf si on va cr�er une fonction pour afficher toutes les performances selon le choix du user (5 choix)

                view_performance(&athlete);
                break;
            case 3:
                show_statistics(&athlete);
                break;
            case 4:
                list_athletes();
                break;
            case 5:
                printf("Entrer le nom de l'athlete � afficher: ");
                if (fgets(name, sizeof(name), stdin) != NULL) {
                    // Remove the newline character if present
                    size_t len = strlen(name);
                    if (len > 0 && name[len - 1] == '\n') {
                        name[len - 1] = '\0';
                    }
                    load_athlete(&athlete, name);//lire les donn�es du fichier texte
                    view_performance(&athlete);//Affichage des donn�es
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("Cliquer sur entrer pour continuer...");
        getchar(); // Wait for Enter key
    }

    return 0;
}
