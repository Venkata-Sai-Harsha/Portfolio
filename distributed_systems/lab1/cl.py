import socket

HOST = '127.0.0.1'
PORT = 12345

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((HOST, PORT))

welcome_message = client_socket.recv(1024).decode()
print(welcome_message)

while True:
    message = input("Client: ")
    client_socket.send(message.encode())

    reply = client_socket.recv(1024).decode()
    print(f"Server: {reply}")

    if message.lower() == 'bye':
        break

client_socket.close()