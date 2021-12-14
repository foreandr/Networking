import socket
import myFunctions

'''CONSTANTS '''
header_size = 10
SERVER_IP = '2607:fea8:2d5f:4f00:b542:a699:de90:ecb4'  # not using here
PORT = 9001
QUEUE_SIZE = 5  # for high traffic
full_msg = ""

'''CREATE AND OPEN SOCKET'''
# HAD TO CHANGE AF_INET TO AF_INET6
s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)  # sits at an ip at a port
s.connect((SERVER_IP, PORT))

while True:
    msg = s.recv(8)  # how much data can I receive
    if (len(msg)) <= 0:
        break
    full_msg += msg.decode("utf-8")
    #print(msg.decode("utf-8"))

print(f"Full message: {full_msg}")
print(f"Length of full message: {len(full_msg)}")
print(f"MESSAGE: {full_msg[header_size:]}")