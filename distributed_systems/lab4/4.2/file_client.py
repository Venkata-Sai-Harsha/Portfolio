import grpc
import file_service_pb2
import file_service_pb2_grpc

def upload_file(stub, filename):
    with open(filename, 'rb') as f:
        content = f.read()
    response = stub.UploadFile(file_service_pb2.UploadRequest(filename=filename, content=content))
    print(response.message)

def download_file(stub, filename):
    response = stub.DownloadFile(file_service_pb2.DownloadRequest(filename=filename))
    if response.content:
        with open("downloaded_" + response.filename, 'wb') as f:
            f.write(response.content)
        print(f"File {response.filename} downloaded successfully")
    else:
        print("File not found")

def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = file_service_pb2_grpc.FileServiceStub(channel)
        
        # Upload a file
        upload_file(stub, 'example.txt')
        
        # Download the file
        download_file(stub, 'example.txt')

if __name__ == '__main__':
    run()
