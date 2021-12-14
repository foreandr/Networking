'''
couldnt get it to work, something wrong with client line 21
'''
import socket

'''CONSTANTS '''
header_size = 10
HOST = '127.0.0.1'  # not using here
PORT = 9001
QUEUE_SIZE = 5  # for high traffic

'''CREATE AND OPEN SOCKET'''
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # sits at an ip at a port
s.bind((HOST, PORT))
s.listen(QUEUE_SIZE)
print("Waiting for connection...")


while True:
    client_socket, address = s.accept()  # address = where are they coming from
    print(f"connection from {address} as been established")
    message_out_from_server = "Welcome to server"
    message_out_from_server = f'{len(message_out_from_server):<{header_size}}' + message_out_from_server

    client_socket.send(bytes("Welcome to server", "utf-8"))  # send information to them
    client_socket.close()
