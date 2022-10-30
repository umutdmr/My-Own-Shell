
// "//" comments used for documentation.
// multiple line commments used for alternative solutions or wrong codes.
 


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <regex.h>
/*#include "stack.h"*/
#include "queue.h"


int regexCheck(char *str, char *pattern) //for checking whether printfile used for printing or writing.
{

    regex_t regex;
    int reti;

    regcomp(&regex, pattern /*"printfile[ ]*[a-z A-Z]*[.][a-z A-Z][ ]*\n$"*/, REG_EXTENDED);
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex);
    if (!reti)
    {
        return 1;
    }
    else if (reti == REG_NOMATCH)
    {
        return 0;
    }
}

void deleteAtTheEnd(char *str) // especially used for delete \n at the end of commands.
{
    str[strlen(str) - 1] = 0;
}

void getIPAdress() //to get ip address of the user.
{

    char *username = getenv("USER");
    char *IPAdress;
    struct hostent *host;

    host = gethostbyname(username);
    IPAdress = inet_ntoa(*((struct in_addr *)
                               host->h_addr_list[0]));

    printf("%s\n", IPAdress);
}

/* char * */ void getUserName() //similar solution from the ps.
{

    char *username = getenv("USER");
    printf("%s >>> ", username);
    /*return username;*/
}

int main(int argc, char *argv[])
{

    /*char * str = (char * ) calloc(sizeof(char),100);
    strcpy(str, getenv("pwd"));

    printf("%s\n", str);*/

    struct stack *pt = new();
    struct stack *pt2 = new();
    /*printf("%p\n", pt);*/

    char *command = (char *)calloc(sizeof(char), 2000);
    char *commandToPop = (char *)calloc(sizeof(char), 2000);
    char *commandToCheckIf = (char *)calloc(sizeof(char), 2000);
    char *fileName;
    char *fileToWrite;
    /*char *commandToCheck;*/
    while (1)
    {

        getUserName(); //<username> >>> 
        /*scanf*/ fgets(command, 2000, stdin);
        deleteAtTheEnd(command);
        //char * firstStrigOnTheCommand = strtok(command, " ");
        strcpy(commandToPop, command);
        strcpy(commandToCheckIf, command);
        char * firstCommand = strtok(commandToCheckIf, " ");
        /*printf("%s\n", commandToPop);*/

        if (strcmp(firstCommand, "listdir") == 0)
        {
            system("ls"); //help of built in commands.
        }
        else if (strcmp(firstCommand, "mycomputername") == 0)
        {
            system("hostname"); //help of built in commands.
        }
        else if (strcmp(firstCommand, "whatsmyip") == 0)
        {
            getIPAdress();
        }
        else if (strcmp(firstCommand, "printfile") == 0) // whether printfile (fileName) or printfile (fileName) > (newFileName)
        {
            /* printf("%s\n", command);S
            fileName = (char *)calloc(sizeof(char), 2000);*/

            if (regexCheck(command, "printfile[ ]*[a-z A-Z]*[.][a-z A-Z]*[ ]*$"))
            {
                char *token = strtok(command, " ");
                token = strtok(NULL, " "); // get (fileName) part
                fileName = (char *)calloc(sizeof(char), strlen(token)); //allocate exact length of the token.
                strcpy(fileName, token);
                /*deleteAtTheEnd(fileName);
                printf("%s\n", fileName);
                printf("open file\n");*/

                FILE *ptr;
                char ch;
                /*char input;*/

                ptr = fopen(fileName, "r");
                while (ch != EOF)
                {
                    ch = fgetc(ptr);
                    if (ch == '\n' || ch == EOF) // double check of EOF otherwise it prints a random character at the end.
                    {
                        getc(stdin); // waiting enter to continue
                        continue;
                    }
                    printf("%c", ch);
                }
                fclose(ptr); // close file.
            }
            else
            {
                /*fileToWrite = (char *)calloc(sizeof(char), 2000);*/
                char *token = strtok(command, " ");
                token = strtok(NULL, " ");
                fileName = (char *)calloc(sizeof(char), strlen(token));
                strcpy(fileName, token);
                
                token = strtok(NULL, " ");
                token = strtok(NULL, " ");
                fileToWrite = (char *)calloc(sizeof(char), strlen(token)); // get (newFileName) part
                strcpy(fileToWrite, token);
                /*printf("%s\n", fileName);
                printf("%s\n", fileToWrite);
                printf("write file\n");
                int size = 7 + strlen(fileName) + strlen(fileToWrite);
                char commmandToCat[size];
                printf("%s\n", commmandToCat);
                printf("%s\n", commmandToCat);
                int index = 0;
                commmandToCat[index++] = 'c';
                commmandToCat[index++] = 'a';
                commmandToCat[index++] = 't';
                commmandToCat[index++] = ' ';
                printf("%s\n", commmandToCat);
                int i = 0;
                printf("%s", fileName);
                for(; i < strlen(fileName); i++) {
                    commmandToCat[index++] = fileName[i];
                }
                printf("%s\n", commmandToCat);
                commmandToCat[index++] = ' ';
                commmandToCat[index++] = '>';
                commmandToCat[index++] = ' ';
                printf("%s\n", commmandToCat);
                i = 0;
                for(; i < strlen(fileToWrite); i++)  {
                    commmandToCat[index++] = fileToWrite[i];
                }
                printf("%s\n", commmandToCat);
                printf("%li\n", strlen(commmandToCat));
                printf("%d\n", size);
                system(commmandToCat);*/
                char * commmandToCat = (char * ) calloc(sizeof(char), 10 + strlen(fileName) + strlen(fileToWrite)); //allocate exact length of the proper cat command
                strcat(commmandToCat, "cat ");
                strcat(commmandToCat, fileName);
                strcat(commmandToCat, " > ");
                strcat(commmandToCat, fileToWrite);
                /*printf("%s\n", commmandToCat);*/
                system(commmandToCat); //help of built in commands.
            }
        } else if(strcmp(firstCommand, "hellotext") == 0) {

            /*system("$EDITOR");*/ // open default $EDITOR variable, which is vim in may machine
            /*system("gtk-launch $(xdg-mime query default text/plain)");*/ // to launch default gui text editor. it works on ubuntu but id do not sure it can run all linux-based systems.
            system("gedit");

        } else if (strcmp(firstCommand, "dididothat") == 0){ // means dididothat command is entered.

            /*char *token = strtok(command, " ");
            token = strtok(NULL, " ");
            token++; // delete first " element.
            deleteAtTheEnd(token); // delete last " element.
            commandToCheck = (char *)calloc(sizeof(char), strlen(token));
            strcpy(commandToCheck, token);
            printf("%s\n", commandToCheck);*/
            /*command += 12; //to remove dididothat " part.*/
            char * commandToCheck = (char *) calloc(sizeof(char), strlen(command));
            strcpy(commandToCheck, command);
            commandToCheck += 12; //to remove dididothat " part.
            deleteAtTheEnd(commandToCheck);
            /*printf("%s\n", commandToCheck);*/
            /*printf("%s\n", pt->items[0]);*/
            /*printf("%i\n", pt->top);*/
            if(checkTheStack(pt, commandToCheck)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            continue;

        } else if (strcmp(command, "exit") == 0) {
            break; //break the while loop. then free variables end return 0;
        }
        else {
            continue;
        }
        if(isFull(pt)) {
            deQueue(pt);
        }
        //push(pt, commandToPop);
        enQueue(pt, pt2, commandToPop);
        //allItems(pt);
        /*printf("pushed %s.\n", commandToPop);*/
        /*free(commandToPop);*/
        /*printf("%i\n", pt->top);*/
        /*printf("%s\n", command);*/
    }
    free(command);
    free(fileName);
    free(fileToWrite);
    free(commandToCheckIf);
    free(commandToPop);
    free(pt);
    return 0;
}
