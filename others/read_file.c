// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main()
{
	FILE* ptr;
	char ch;
    //char input;

	ptr = fopen("test.txt", "r");

    while (ch != EOF) {
        ch = fgetc(ptr);
        if(ch == '\n') {
            getc(stdin);
            continue;
        }
        printf("%c", ch);
    } 
	
	fclose(ptr);
	return 0;
}
