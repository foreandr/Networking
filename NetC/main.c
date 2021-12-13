#include <stdio.h> // input output
#include <stdlib.h>

#include <ws2def.h>
//#include <wsipv6ok.h> // ?
//#include <winsock.h>
//#include <sys/types.h>
#include <winsock2.h>
//#include <Ws2tcpip.h> // NO IDEA
int main() {
	printf("Hello world");

	// cREATE ONE SIDE OF DATA COMMUNCIATION
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET; // internet type
	server_address.sin_port = htons(9002); // CHOOSE 
	server_address.sin_addr.s_addr = INADDR_ANY; // equivalent to 0.0.0.0 home 

	int connection_status = connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address)); // returns an int // weird cast
	if (connection_status == -1) {
		printf("There was an error making a connection to the socketl");
	}

	//recieve data from server into this variable
	char server_response[256];
	recv(network_socket, server_response, sizeof(server_response), 0);

	//
	printf("The server sent the data %c*", server_response);

	_close(network_socket); //HAD TO changed form close to _close
}