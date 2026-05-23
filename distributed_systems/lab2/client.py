import cv2
import socket
import numpy as np

# Create window for client-side display
cv2.namedWindow('Client Video Stream', cv2.WINDOW_NORMAL)

# Set up client socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 9999))

while True:
    # Receive frame size
    frame_size = int.from_bytes(client_socket.recv(4), byteorder='big')

    # Receive frame bytes
    img_bytes = b''
    while len(img_bytes) < frame_size:
        packet = client_socket.recv(frame_size - len(img_bytes))
        if not packet:
            break
        img_bytes += packet

    # Convert bytes to image
    nparr = np.frombuffer(img_bytes, np.uint8)
    frame = cv2.imdecode(nparr, cv2.IMREAD_COLOR)

    # Display frame on client window
    cv2.imshow('Client Video Stream', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release resources
cv2.destroyAllWindows()
client_socket.close()