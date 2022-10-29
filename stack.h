/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    char *commands[15];
    for(int i = 0; i < 15; i++) {

        commands[i] = (char *) calloc(sizeof(char), 2000);
    }
    commands[0] = "samgapngeaponheaponeagpoen";
    printf("%s\n", commands[0]);

    
    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{

    int maxSize;
    int top;
    char **items;
};

struct stack *new ()
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->maxSize = 15;
    ptr->top = -1;
    ptr->items = malloc(2000 * sizeof(char *));
    for (int i = 0; i < 15; i++)
    {
        ptr->items[i] = malloc((2000) * sizeof(char));
    }

    return ptr;
}

int isFull(struct stack *ptr)
{

    return ptr->top == ptr -> maxSize - 1;
}

int isEmpty(struct stack *ptr)
{

    return ptr->top == -1;
}

void push(struct stack *ptr, char *x)
{
    /*strcpy(ptr->items[ptr->top++], x);*/
    char * token = (char *) calloc(sizeof(char), strlen(x));
    //printf("%s\n", x);
    for (int j = 0; x[j] != '\0'; j++) {
        token[j] = x[j];
        /*printf("%c\n", token[j]);*/
    }
    /*ptr->items[++ptr->top] = token;*/
    strcpy(ptr->items[++ptr->top], token);
    free(token);
}

char * pop(struct stack *ptr)
{

    //ptr->top -= 1;
    return ptr->items[ptr->top--];
}

int checkTheStack(struct stack *ptr,  char * sequence) {

    for(int i = 0; i <= ptr ->top; i++) {
        if(strcmp(ptr->items[i], sequence) == 0) {
            return 1;
        }
    }
    return 0;
}

void allItems(struct stack *ptr) {

    for(int i = 0; i <= ptr ->top; i++) {
        printf("%s\n", ptr->items[i]);
    }
}