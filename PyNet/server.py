import selectors
import socket
import myFunctions

'''CONSTANTS '''
header_size = 10
#HOST = '2607:fea8:2d5f:4f00:b542:a699:de90:ecb4'  # not using here
PORT = 9001
QUEUE_SIZE = 5  # for high traffic

'''CREATE AND OPEN SOCKET'''
# HAD TO CHANGE AF_INET TO AF_INET6
s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)  # sits at an ip at a port
s.bind(("", PORT)) # i CAN REMOVE THE HOST HERE FOR SOME REASON??
s.listen(QUEUE_SIZE)
print("Waiting for connection...")

while True:
    client_socket, address = s.accept()  # address = where are they coming from
    print(f"connection from {address} as been established")
    message_out_from_server = "Welcome to server"
    message_out_from_server = f'{len(message_out_from_server):<{header_size}}' + message_out_from_server

    client_socket.send(bytes(message_out_from_server, "utf-8"))  # send information to them
    client_socket.close() # close the client