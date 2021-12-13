#include <iostream>
#include "asio.h"
#include "cfile.h"
#include "unstd.h"
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


}