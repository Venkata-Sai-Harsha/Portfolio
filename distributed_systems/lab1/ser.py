import socket
import threading

def handle_client(conn, addr):
    print('Connected to', addr)
    conn.send('Thank you for connecting\n'.encode())
    while True:
        message = conn.recv(1024).decode().strip()
        if message.lower() == 'bye':
            print('Client', addr, 'disconnected.')
            conn.send('Goodbye!\n'.encode())
            break
        print('Client:', message)
        response = input('You: ')
        conn.send(response.encode())

    conn.close()

def start_server():
    s = socket.socket()
    port = 12345
    s.bind(('', port))
    s.listen(5)
    print('Server listening on port', port)

    while True:
        print('Waiting for connection...')
        conn, addr = s.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()

if __name__ == "__main__":
    start_server()