import grpc
import calculator_pb2
import calculator_pb2_grpc

def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = calculator_pb2_grpc.CalculatorStub(channel)

        while True:
            print("\nMenu:")
            print("1. Addition")
            print("2. Subtraction")
            print("3. Multiplication")
            print("4. Division")
            print("5. Exit")
            choice = input("Enter your choice: ")

            if choice == '5':
                print("Exiting the calculator.")
                break

            num1 = float(input("Enter first number: "))
            num2 = float(input("Enter second number: "))

            if choice == '1':
                response = stub.Add(calculator_pb2.OperationRequest(number1=num1, number2=num2))
            elif choice == '2':
                response = stub.Subtract(calculator_pb2.OperationRequest(number1=num1, number2=num2))
            elif choice == '3':
                response = stub.Multiply(calculator_pb2.OperationRequest(number1=num1, number2=num2))
            elif choice == '4':
                response = stub.Divide(calculator_pb2.OperationRequest(number1=num1, number2=num2))
            else:
                print("Invalid choice. Please try again.")
                continue

            if response.error:
                print(f"Error: {response.error}")
            else:
                print(f"Result: {response.result}")

if __name__ == '__main__':
    run()
