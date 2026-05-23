#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, moves;

    Point(int _x, int _y, int _moves) : x(_x), y(_y), moves(_moves) {}
};

int minMovesKnight(int startX, int startY, int targetX, int targetY, int boardSize) {
    // Possible moves for the knight
    vector<int> dx = {2, 2, 1, 1, -1, -1, -2, -2};
    vector<int> dy = {1, -1, 2, -2, 2, -2, 1, -1};

    // Create a chessboard to track visited squares and store the minimum moves
    vector<vector<bool>> visited(boardSize, vector<bool>(boardSize, false));

    // Initialize the queue for BFS
    queue<Point> q;
    q.push(Point(startX, startY, 0));
    visited[startX][startY] = true;

    // Perform BFS
    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        // Check if the target position is reached
        if (current.x == targetX && current.y == targetY) {
            return current.moves;
        }

        // Explore possible moves
        for (int i = 0; i < 8; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            // Check if the new position is within the board and not visited
            if (newX >= 0 && newX < boardSize && newY >= 0 && newY < boardSize && !visited[newX][newY]) {
                q.push(Point(newX, newY, current.moves + 1));
                visited[newX][newY] = true;
            }
        }
    }

    // If the target position cannot be reached
    return -1;
}

int main() {
    // Example usage:
    int startX = 0, startY = 0;
    int targetX = 7, targetY = 7;
    int boardSize = 8;

    int moves = minMovesKnight(startX, startY, targetX, targetY, boardSize);

    if (moves != -1) {
        cout << "Minimum number of moves: " << moves << endl;
    } else {
        cout << "The target position cannot be reached." << endl;
    }

    return 0;
}