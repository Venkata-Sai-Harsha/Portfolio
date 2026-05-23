import cv2
import socket

# Open the video file
cap = cv2.VideoCapture('reel.mp4')

# Create window for server-side display
cv2.namedWindow('Server Video Stream', cv2.WINDOW_NORMAL)

# Set up server socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 9999))
server_socket.listen(5)

# Accept client connection
client_socket, addr = server_socket.accept()

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

    # Display frame on server window
    cv2.imshow('Server Video Stream', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release resources
cap.release()
client_socket.close()
server_socket.close()
cv2.destroyAllWindows()