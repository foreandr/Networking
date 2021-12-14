import socket

SERVER_IP = '127.0.0.1'  # not using here
PORT = 9002
QUEUE_SIZE = 5  # for high traffic

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # sits at an ip at a port

s.connect((SERVER_IP, PORT))


full_msg = ""
while True:
    msg = s.recv(8)  # how much data can I receive
    if (len(msg)) <= 0:
        break
    full_msg += msg.decode("utf-8")
    #print(msg.decode("utf-8"))

print(full_msg)