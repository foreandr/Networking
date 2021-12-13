/*ASYNCRONOUS INPUT OUTPUT
/*Specify networkign scheme*/
#ifdef _WIN32
#define _WIN32_WINNT 0XA00
#endif
#include <iostream>

#define ASIO_STANDALONE
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ts/internet.hpp>
//typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
using namespace boost::asio;
namespace std {
	boost::asio::io_context context;
	boost::system::error_code error_code;

	// Get address of somewhere we want to connect
	string ipAdressOfSite = "2607:fea8:2d5f:4f00:8cc4:5148:9ebf:17fe";
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address(ipAdressOfSite), 80); // No error code

	// Create networking socket
	boost::asio::ip::tcp::socket socket(context);

	//tell socket to try and connect 
	//socket.connect(endpoint);

	io_service service;

	ip::tcp::endpoint ep(ip::tcp::v4(), 2001); // ENDPOINT
	ip::tcp::acceptor acc(service, ep); // NO IDEA
	/*
	while (true) {
		socket_ptr sock(new ip::tcp::socket(service));
		acc.accept(*sock);
	}*/
}/*
void client_session(socket_ptr sock) {
	while (true) {
		char data[512];
		size_t len = sock->read_some(buffer(data));
		if (len > 0)
			write(*sock, buffer("ok", 2));
	}
}
*/

