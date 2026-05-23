import grpc
from concurrent import futures
import file_service_pb2
import file_service_pb2_grpc
import os

class FileServiceServicer(file_service_pb2_grpc.FileServiceServicer):
    def __init__(self, storage_dir):
        self.storage_dir = storage_dir
        if not os.path.exists(storage_dir):
            os.makedirs(storage_dir)
    
    def UploadFile(self, request, context):
        file_path = os.path.join(self.storage_dir, request.filename)
        with open(file_path, 'wb') as f:
            f.write(request.content)
        return file_service_pb2.UploadResponse(message="File uploaded successfully")

    def DownloadFile(self, request, context):
        file_path = os.path.join(self.storage_dir, request.filename)
        if os.path.exists(file_path):
            with open(file_path, 'rb') as f:
                content = f.read()
            return file_service_pb2.DownloadResponse(filename=request.filename, content=content)
        else:
            context.set_code(grpc.StatusCode.NOT_FOUND)
            context.set_details('File not found')
            return file_service_pb2.DownloadResponse()

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    file_service_pb2_grpc.add_FileServiceServicer_to_server(FileServiceServicer(storage_dir='files'), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
