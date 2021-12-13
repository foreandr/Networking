#include <iostream>
#include <boost/asio.hpp>
#include "encryption.h"
/* SOCKET IS
* IP ADDRESS & PORT NUMBER / APPLICATION NUMBER / PROTOCOL NUMBER
* CONNECTION ORIENTED? - care for reply or not
* 
*    tcp 53 & udp 53 different
     
     datagram sockets
     stream sockets
     raw sockets

     socket pair - SOURCE/DEST IP, SOURCE DEST PORT

     COMMON SYS CALLS
        - SOCKET, BIND CONNECT, LISTEN, ACCEPT, READ WRITE, CLOSE

*/
using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

string read_(tcp::socket& socket);
void send_(tcp::socket& socket, const string& message);

//SERVER
int main() {

    boost::asio::io_service io_service;
    //listen for new connection
    tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v6(), 9002)); // port num //ipv6 in particular
    tcp::socket socket_(io_service);//socket creation 
    
    //waiting for connection
    cout << "Waiting for connection...\n";
    acceptor_.accept(socket_); // listening for connections

    //read operation
    string message = read_(socket_); // message coming from the user
    cout << lenCeaserDecrypt(message) << endl; // decrypt the message

    //write operation
    send_(socket_, "Hello From Server!");
    return 0;

}
string read_(tcp::socket& socket) {
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}
void send_(tcp::socket& socket, const string& message) {
    const string msg = message + "\n";
    boost::asio::write(socket, boost::asio::buffer(message));
}