#include <iostream>
#include <boost/asio.hpp>
#include "encryption2.h"
using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

constexpr auto FOREIGN_IP_ADDRESS = "2607:fea8:2d5f:4f00:bc91:7044:66a3:a23f";
int main() {
    boost::asio::io_service io_service;
    //socket creation
    tcp::socket socket(io_service);
    
    //connection
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string(FOREIGN_IP_ADDRESS), 9002)); //foreign IP address OR IS IT MINE?
    
    // request/message from client                                                                                       
    string msg = "Hello from Client!\n";
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg), error);
    if (!error) {
        cout << "Client sent hello message!" << endl;
    }
    else {
        cout << "send failed: " << error.message() << endl;
    }

    // getting response from server
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
    if (error && error != boost::asio::error::eof) {
        cout << "receive failed: " << error.message() << endl;
    }
    else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        cout << "Data recieved from server: "<< data << endl;

    }
    return 0;
}


