import grpc
from concurrent import futures
import calculator_pb2
import calculator_pb2_grpc

class CalculatorServicer(calculator_pb2_grpc.CalculatorServicer):
    def Add(self, request, context):
        result = request.number1 + request.number2
        return calculator_pb2.OperationResponse(result=result)

    def Subtract(self, request, context):
        result = request.number1 - request.number2
        return calculator_pb2.OperationResponse(result=result)

    def Multiply(self, request, context):
        result = request.number1 * request.number2
        return calculator_pb2.OperationResponse(result=result)

    def Divide(self, request, context):
        if request.number2 == 0:
            return calculator_pb2.OperationResponse(error="Division by zero is undefined")
        result = request.number1 / request.number2
        return calculator_pb2.OperationResponse(result=result)

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    calculator_pb2_grpc.add_CalculatorServicer_to_server(CalculatorServicer(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    print("Server started on port 50051")
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
