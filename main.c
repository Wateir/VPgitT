#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int help(char* progName){
	printf("Usage: %s <commit|change>\n", progName);
	printf("Usage: %s <switch> [branch name]\n", progName);
	return 0;
}

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
	return 0;
}

int change() {
	char titre[MAX_LENGTH];
	char description[MAX_LENGTH];
	char commande[MAX_LENGTH * 2];

	commitInterface(titre, description);
	
	snprintf(commande, sizeof(commande), "git commit --amend -m \"%s\" -m \"%s\"", titre, description);
	    
	system(commande);
	return 0;
}

int checkout(int numberOfArg, char param[]){
	char command[MAX_LENGTH];
	if (numberOfArg == 1){
		snprintf(command, sizeof(command), "git branch --sort=-committerdate | grep -v \"^\\*\" | fzf --reverse --height 10 | xargs -r git switch");

		system(command);
	}
	else{
		snprintf(command, sizeof(command), "git switch %s", param);
	}
	return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        help(argv[0]);
        return 1;
    }
	if (strcmp(argv[1], "checkout") && argc != 2){
		help(argv[0]);
		return 1;
	}
	
    if (strcmp(argv[1], "commit") == 0) {
        commit();
    }
    else if (strcmp(argv[1], "change") == 0) {
    	change();
    } 
    else if (strcmp(argv[1], "checkout") ==0) {
    	checkout(argc-1, argv[2]);
    }
	else {
        help(argv[0]);
        return 1;
    }

    return 0;
}
