#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 
 MAX_LENGTH is the max size a desciption can have
 MAX_GIT_LENGH assure that the description and the git command, both fit on the command execute
*/
#define MAX_LENGTH 256
#define MAX_GIT_LENGHT 64

int help(char* progName){
	printf("Usage: %s <commit|change>\n", progName);
	printf("Usage: %s <checkout> [-p] branch_name\n", progName);
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
	char commande[MAX_LENGTH * 2 + MAX_GIT_LENGHT];

	commitInterface(titre, description);
	
	snprintf(commande, sizeof(commande), "git commit -m \"%s\" -m \"%s\"", titre, description);
	    
	system(commande);
	return 0;
}

int change() {
	char titre[MAX_LENGTH];
	char description[MAX_LENGTH];
	char commande[MAX_LENGTH * 2 + MAX_GIT_LENGHT];

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

int new(char param[]){
	char command[MAX_LENGTH];
	snprintf(command, sizeof(command), "git checkout -b %s", param);
	system(command);
	return 0;
}

int main(int argc, char *argv[]) {
	 if (argc < 2 || argc > 4) {
        help(argv[0]);
        return 1;
    }
    else if (argc == 2){
    	 if (strcmp(argv[1], "commit") ==0) {
	    	commit();
	    }
	    else if (strcmp(argv[1], "change") == 0) {
	        	change();
	    } 
	    else if (strcmp(argv[1], "checkout") == 0){
	    	checkout(argc-1, argv[2]);
	    }
	    else {
	    	help(argv[0]);
	    	return 1;
	    }
    }
    else if (argc == 3){
    	if (strcmp(argv[1], "checkout") == 0) {
    		if (strcmp(argv[2], "-b") == 0){
    			help(argv[0]);
    			return 1;
    		}
    		else {
    		checkout(argc-1, argv[2]);
    		}
    	}
    	else {
    		help(argv[0]);
    		return 1;
    	}
    }
    else if (argc == 4){
    	if (strcmp(argv[1], "checkout") == 0 && strcmp(argv[2], "-b") == 0){
    		new(argv[3]);
    	}
    	else {
    		help(argv[0]);
    		return 1;
    	}
    }

    return 0; 
}
