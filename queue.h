#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void enQueue(struct stack *s1, struct stack *s2, char *str)
{
    // Move all elements from s1 to s2
    while (isEmpty(s1) != 1)
    {
        push(s2, pop(s1));
    }
    
    push(s1, str);
    // Push everything back to s1
    while (isEmpty(s2) != 1)
    {

        push(s1, pop(s2));
    }
}

void deQueue(struct stack *s1)
{

    pop(s1);
}
