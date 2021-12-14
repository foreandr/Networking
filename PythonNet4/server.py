import socket

HOST = '127.0.0.1'  # not using here
PORT = 9002
QUEUE_SIZE = 5  # for high traffic

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # sits at an ip at a port
s.bind((socket.gethostname(), 9002))
s.listen(QUEUE_SIZE)
print("Waiting for connection")

while True:
    client_socket, address = s.accept()  # address = where are they coming from
    print(f"connection from {address} as been established")
    client_socket.send(bytes("Welcome to server", "utf-8"))  # send information to them
