#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/* char * */ void getUserName() {

    char *username = getenv("USER");
    printf("%s >>> ", username);
    //return username;
}

char * getComputerName() {

    
}

int main(int argc, char *argv[]) {

    char *command = (char *) calloc(sizeof(char), 20);
    while(1) {

        
        getUserName();
        scanf("%s", command);
        if((strcmp(command, "exit") == 0)) {
            break;
        } else if((strcmp(command, "mycomputername") == 0)) {
            break;
        }
        printf("%s\n", command);
    }
    
	return 0;
}	
