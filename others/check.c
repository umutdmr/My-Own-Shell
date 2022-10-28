#include <regex.h>
#include <stdlib.h>
#include <stdio.h>

int regexCheck(char *str, char * pattern)
{

    regex_t regex;
    int reti;

    regcomp(&regex, pattern/*"printfile[ ]*[a-z A-Z]*[.][a-z A-Z][ ]*\n$"*/, REG_EXTENDED);
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

int main(int argc, char const *argv[])
{

    /*regex_t regex;
    int reti;
    char msgbuf[100];
    fgets(msgbuf, 100, stdin);

    regcomp(&regex, "printfile[ ]*[a-z A-Z]*[.][a-z A-Z][ ]*\n$", REG_EXTENDED);
    reti = regexec(&regex, msgbuf, 0, NULL, 0);
    if (!reti)
    {
        puts("Match");
    }
    else if (reti == REG_NOMATCH)
    {
        puts("No match");
    }
    regfree(&regex);*/
    printf("%d\n" ,regexCheck("printfile myText.c  ", "printfile[ ]*[a-z A-Z]*[.][a-z A-Z][ ]*$"));

}
