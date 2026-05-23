import socket

def start_client():
    s = socket.socket()
    port = 12345
    host = input("Enter server IP: ")
    s.connect((host, port))
    print(s.recv(1024).decode())

    while True:
        message = input('You: ')
        s.send((message + '\n').encode())
        if message.lower() == 'bye':
            print('You disconnected from the server.')
            break
        response = s.recv(1024).decode().strip()
        print('Server:', response)
        if response.lower() == 'bye':
            print('Server disconnected.')
            break

    s.close()

if __name__ == "__main__":
    start_client()