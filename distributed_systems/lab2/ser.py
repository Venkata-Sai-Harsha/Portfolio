import cv2
import socket
import threading

# Open the video file
cap = cv2.VideoCapture('reel.mp4')

# Create window for server-side display
cv2.namedWindow('Server Video Stream', cv2.WINDOW_NORMAL)

# Set up server socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 9999))
server_socket.listen(5)

clients = []

def handle_client(client_socket):
    cap.set(cv2.CAP_PROP_POS_FRAMES, 0)  # Seek to the beginning of the video
    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break

        # Convert frame to bytes
        _, img_encoded = cv2.imencode('.jpg', frame)
        img_bytes = img_encoded.tobytes()

        # Send frame bytes to client
        client_socket.sendall(len(img_bytes).to_bytes(4, byteorder='big'))
        client_socket.sendall(img_bytes)

    client_socket.close()

while True:
    client_socket, addr = server_socket.accept()
    clients.append(client_socket)
    print(f"Connected to {addr}")

    # Start a new thread to handle the client
    client_thread = threading.Thread(target=handle_client, args=(client_socket,))
    client_thread.start()

# Release resources
cap.release()
for client_socket in clients:
    client_socket.close()
server_socket.close()
cv2.destroyAllWindows()