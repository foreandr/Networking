import socket

'''CONSTANTS '''
SERVER_IP = '127.0.0.1'  # not using here
PORT = 9001
QUEUE_SIZE = 5  # for high traffic
header_size = 10

'''CREATE AND OPEN SOCKET'''
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # sits at an ip at a port
s.connect((SERVER_IP, PORT))


while True:
    full_msg = ''
    new_msg = True
    while True:
        msg = s.recv(16)
        if new_msg:
            print("new msg len:", msg[:header_size])
            msglen = len(msg[:header_size])
            #msg.replace(b" ", b"") # ERROR
            #msglen = float(msg[:header_size])# ERROR
            #msglen = int(msg[:header_size])  # ERROR
            new_msg = False

        print(f"full message length: {msglen}")

        full_msg += msg.decode("utf-8")

        print(len(full_msg))


        if len(full_msg)-header_size == msglen:
            print("full msg recvd")
            print(full_msg[header_size:])
            new_msg = True