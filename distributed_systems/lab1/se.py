import socket

HOST = ''
PORT = 12345

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST, PORT))
server_socket.listen()

print(f"Server is listening on {HOST}:{PORT}")

while True:
    client_socket, client_address = server_socket.accept()
    print(f"Connection from {client_address}")

    client_socket.send("Welcome to the chat server!".encode())

    while True:
        message = client_socket.recv(1024).decode()
        if not message:
            break

        print(f"Client ({client_address}): {message}")

        reply = input("Server: ")
        client_socket.send(reply.encode())

    print(f"Connection from {client_address} closed.")
    client_socket.close()