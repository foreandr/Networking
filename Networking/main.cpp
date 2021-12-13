#include <iostream>
#include <stdio.h>
#include <sys/types.h>
//#include <socketapi.h>
#include <Ws2tcpip.h> // NO IDEA
#include <winsock2.h>

//using namespace std;
//using namespace boost::asio;

// TCP PARTICULAR
#include <winsock2.h> // socket related | INET things
int main() {
	
	// cREATE ONE SIDE OF DATA COMMUNCIATION
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET; // internet type
	server_address.sin_port = htons(9002); // CHOOSE 
	server_address.sin_addr.s_addr = INADDR_ANY; // equivalent to 0.0.0.0 home 

	int connection_status = connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address)); // returns an int // weird cast
	
	if (connection_status == -1) {
		std::cout << "There was an error making a connection to the socket";
		// RIGHT AFTER THIS RUNS IS WHERE THE BUG OCCURS
		
	}
	
	//recieve data from server into this variable
	//char server_response[256];
	//recv(network_socket, server_response, sizeof(server_response), 0);
	//std::cout << "The server sent the data " << server_response;

	_close(network_socket);

}