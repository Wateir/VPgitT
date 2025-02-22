#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int main() {
    char titre[MAX_LENGTH];
    char description[MAX_LENGTH];

    printf(" Title 	:\n");
    printf("  Description 	: ");
    printf("\033[0A");
    
    fgets(titre, MAX_LENGTH, stdin);
	printf("\033[18C");
    fgets(description, MAX_LENGTH, stdin);

    description[strcspn(description, "\n")] = 0;
    printf("\033[A\33[2K\r");
    printf("\033[A\33[2K\r");

    char commande[MAX_LENGTH * 2];
    
    printf("\033[0;32m==> \033[0m");fflush(stdout);
    
    snprintf(commande, sizeof(commande), "git commit -m \"%s\" -m \"%s\"", titre, description);
    
    system(commande);
    return 0;
}

