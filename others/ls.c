/*#include <stdio.h>
#include <stdlib.h>	//to use system()
#include <string.h> //to use strcpy()

int main()
{
	char *command;
	
	//executing ls command
	strcpy(command, "ls");
	system(command);
	
	//executing date command 
	/*strcpy(command, "date");
	system(command);
	
	return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>	//to use system()
#include <string.h> //to use strcpy()

int main()
{
	int num = system("ls");
	int num2 = system("hostname");
	printf("%d\n%d\n", num, num2);
	return 0;
}
