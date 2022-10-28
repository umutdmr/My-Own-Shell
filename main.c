#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <regex.h>

int regexCheck(char *str, char *pattern)
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

void deleteEscapeCharacterAtTheEnd(char *str)
{
    str[strlen(str) - 1] = 0;
}

void getIPAdress()
{

    char *username = getenv("USER");
    char *IPAdress;
    struct hostent *host;

    host = gethostbyname(username);
    IPAdress = inet_ntoa(*((struct in_addr *)
                               host->h_addr_list[0]));

    printf("%s\n", IPAdress);
}

/* char * */ void getUserName()
{

    char *username = getenv("USER");
    printf("%s >>> ", username);
    // return username;
}

int main(int argc, char *argv[])
{

    /*char * str = (char * ) calloc(sizeof(char),100);
    strcpy(str, getenv("pwd"));

    printf("%s\n", str);*/

    char *command = (char *)calloc(sizeof(char), 2000);
    char *fileName;
    char *fileToWrite;
    while (1)
    {

        getUserName();
        /*scanf*/ fgets(command, 2000, stdin);
        deleteEscapeCharacterAtTheEnd(command);

        if (strcmp(command, "listdir") == 0)
        {
            system("ls");
        }
        else if (strcmp(command, "mycomputername") == 0)
        {
            system("hostname");
        }
        else if (strcmp(command, "whatsmyip") == 0)
        {
            getIPAdress();
        }
        else if (command[0] == 'p')
        {
            // printf("%s\n", command);S
            //fileName = (char *)calloc(sizeof(char), 2000);

            if (regexCheck(command, "printfile[ ]*[a-z A-Z]*[.][a-z A-Z]*[ ]*$"))
            {
                char *token = strtok(command, " ");
                token = strtok(NULL, " ");
                fileName = (char *)calloc(sizeof(char), strlen(token));
                strcpy(fileName, token);
                // deleteEscapeCharacterAtTheEnd(fileName);
                //printf("%s\n", fileName);
                //printf("open file\n");

                FILE *ptr;
                char ch;
                // char input;

                ptr = fopen(fileName, "r");
                while (ch != EOF)
                {
                    ch = fgetc(ptr);
                    if (ch == '\n' || ch == EOF)
                    {
                        getc(stdin);
                        continue;
                    }
                    printf("%c", ch);
                }
                fclose(ptr);
            }
            else
            {
                //fileToWrite = (char *)calloc(sizeof(char), 2000);
                char *token = strtok(command, " ");
                token = strtok(NULL, " ");
                fileName = (char *)calloc(sizeof(char), strlen(token));
                strcpy(fileName, token);
                
                token = strtok(NULL, " ");
                token = strtok(NULL, " ");
                fileToWrite = (char *)calloc(sizeof(char), strlen(token));
                strcpy(fileToWrite, token);
                /*printf("%s\n", fileName);
                printf("%s\n", fileToWrite);
                printf("write file\n");*/
                /*int size = 7 + strlen(fileName) + strlen(fileToWrite);
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
                //printf("%s", fileName);
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
                printf("%d\n", size);*/
                //system(commmandToCat);
                char * commmandToCat = (char * ) calloc(sizeof(char), 10 + strlen(fileName) + strlen(fileToWrite));
                strcat(commmandToCat, "cat ");
                strcat(commmandToCat, fileName);
                strcat(commmandToCat, " > ");
                strcat(commmandToCat, fileToWrite);
                //printf("%s\n", commmandToCat);
                system(commmandToCat);
            }
        } else if(strcmp(command, "hellotext") == 0) {

            system("gtk-launch $(xdg-mime query default text/plain)");

        } else if (strcmp(command, "exit") == 0)
        {
            break;
        }
        // printf("%s\n", command);
    }
    free(command);
    free(fileName);
    free(fileToWrite);
    return 0;
}
