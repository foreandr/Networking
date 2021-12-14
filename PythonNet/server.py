'''
# Standard loopback interface
#(host, port, flowinfo, scopeid) for IPv6
# If your server receives a lot of connection requests simultaneously, increasing the backlog value may help by setting the maximum length of the queue for pending connections.
# blocks and waits for an incoming connection. When a client connects, it returns a new socket object representing the connection and a tuple holding the address of the client.
# bind() is used to associate the socket with a specific network interface and port number:
# Port to listen on (non-privileged ports are > 1023)
# There’s no need to call s.close(): if we use WITH
# “Unlike send(), sendall() continues to send data from bytes until either all data has been sent or an error occurs. None is returned on success.”
# select() allows you to check for I/O completion on more than one socket
# So you can call select() to see which sockets have I/O ready for reading and/or writing.

'''
import socket

HOST = '127.0.0.1'
PORT = 9002

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept() # gives us new socket object named conn
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024) # max data received at once
            if not data:
                break
            conn.sendall(data)
