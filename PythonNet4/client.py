import socket

SERVER_IP = '127.0.0.1'  # not using here
PORT = 9002
QUEUE_SIZE = 5  # for high traffic

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # sits at an ip at a port

s.connect((SERVER_IP, PORT))

msg = s.recv(1024) # how much data can I recieve