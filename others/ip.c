// C program to display hostname
// and IP address
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>



// Driver code
int main()
{
	char hostbuffer[256];
	char *IPbuffer;
	struct hostent *host_entry;
	int hostname;

	// To retrieve hostname
	/*hostname = */
	//checkHostName(hostname);
	//gethostname(hostbuffer, sizeof(hostbuffer));
	host_entry = gethostbyname("umutdmr");
	IPbuffer = inet_ntoa(*((struct in_addr*)
						host_entry->h_addr_list[0]));

	printf("Hostname: %s\n", hostbuffer);
	printf("Host IP: %s\n", IPbuffer);

	return 0;
}

