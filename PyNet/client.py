import socket
import myFunctions

'''CONSTANTS '''
header_size = 10
SERVER_IP = '127.0.0.1'  # not using here
PORT = 9001
QUEUE_SIZE = 5  # for high traffic
full_msg = ""

'''CREATE AND OPEN SOCKET'''
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # sits at an ip at a port
s.connect((SERVER_IP, PORT))

while True:
    msg = s.recv(8)  # how much data can I receive
    if (len(msg)) <= 0:
        break
    full_msg += msg.decode("utf-8")
    #print(msg.decode("utf-8"))

print(full_msg)
print(len(full_msg))
print(full_msg[header_size:])