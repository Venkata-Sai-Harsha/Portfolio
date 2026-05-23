def display_board(board):
    for row in board:
        print(row)

def create_board():
    board = []
    for i in range(8):
        row = []
        for j in range(8):
            if (i + j) % 2 == 0:
                row.append("W")
            else:
                row.append("B")
        board.append(row)
    return board

def get_input():
    while True:
        input_str = input("Enter your move: ")
        if len(input_str) != 4 or not input_str[0].isalpha() or not input_str[1].isdigit() or not input_str[2].isalpha() or not input_str[3].isdigit():
            print("Invalid input. Please enter the move in the format 'a2a4'.")
        else:
            return input_str

def is_valid_move(board, input_str):
    # Sample implementation: Check if the move is within the board bounds
    x1, y1, x2, y2 = ord(input_str[0]) - ord('a'), int(input_str[1]) - 1, ord(input_str[2]) - ord('a'), int(input_str[3]) - 1

    if 0 <= x1 < 8 and 0 <= y1 < 8 and 0 <= x2 < 8 and 0 <= y2 < 8:
        return True
    else:
        print("Invalid move. Move out of bounds.")
        return False

def update_board(board, input_str):
    # Sample implementation: Swap the pieces at the specified positions
    x1, y1, x2, y2 = ord(input_str[0]) - ord('a'), int(input_str[1]) - 1, ord(input_str[2]) - ord('a'), int(input_str[3]) - 1

    board[x1][y1], board[x2][y2] = board[x2][y2], board[x1][y1]

def main():
    board = create_board()
    while True:
        display_board(board)
        input_str = get_input()
        if is_valid_move(board, input_str):
            update_board(board, input_str)
        else:
            print("Invalid move. Please try again.")

if __name__ == "__main__":
    main()