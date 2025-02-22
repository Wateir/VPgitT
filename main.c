#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256


int commitInterface(char* titre, char* description) {

    printf(" Title 	:\n");
    printf("  Description 	: ");
    printf("\033[0A");
    
    fgets(titre, MAX_LENGTH, stdin);
	printf("\033[18C");
    fgets(description, MAX_LENGTH, stdin);

    description[strcspn(description, "\n")] = 0;
    printf("\033[A\33[2K\r");
    printf("\033[A\33[2K\r");

    
    printf("\033[0;32m==> \033[0m");fflush(stdout);
    
	return 0;
}
int commit() {
	char titre[MAX_LENGTH];
	char description[MAX_LENGTH];
	char commande[MAX_LENGTH * 2];

	commitInterface(titre, description);
	
	snprintf(commande, sizeof(commande), "git commit -m \"%s\" -m \"%s\"", titre, description);
	    
	system(commande);

}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <commit|change>\n", argv[0]);
        return 1;
    }

    // Comparaison des arguments
    if (strcmp(argv[1], "commit") == 0) {
        commit();
    } else if (strcmp(argv[1], "change") == 0) {
        printf("L'argument est 'change'.\n");
    } else {
        printf("Argument invalide. Utilisez 'commit' ou 'change'.\n");
        return 1;
    }

    return 0;
}
