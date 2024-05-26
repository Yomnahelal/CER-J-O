#include <stdio.h>
#include <stdlib.h>

void clear_screen() {
    // System-specific command to clear the screen
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}
