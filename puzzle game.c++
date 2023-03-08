#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void shuffleBoard(vector<vector<int>>& board) {
    srand(time(nullptr));
    for (int i = 0; i < 100; ++i) {
        int row1 = rand() % 4;
        int col1 = rand() % 4;
        int row2 = rand() % 4;
        int col2 = rand() % 4;
        swap(board[row1][col1], board[row2][col2]);
    }
}

bool isSolved(const vector<vector<int>>& board) {
    int count = 1;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell != count % 16) {
                return false;
            }
            ++count;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> board {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 0 }
    };
    
    shuffleBoard(board);
    displayBoard(board);
    
    while (!isSolved(board)) {
        int row, col;
        cout << "Enter the row and column of the cell you want to move: ";
        cin >> row >> col;
        
        if (row < 1 || row > 4 || col < 1 || col > 4) {
            cout << "Invalid row or column." << endl;
            continue;
        }
        
        if (board[row - 1][col - 1] == 0) {
            cout << "You can't move an empty cell." << endl;
            continue;
        }
        
        if (row > 1 && board[row - 2][col - 1] == 0) {
            swap(board[row - 1][col - 1], board[row - 2][col - 1]);
        }
        else if (row < 4 && board[row][col - 1] == 0) {
            swap(board[row - 1][col - 1], board[row][col - 1]);
        }
        else if (col > 1 && board[row - 1][col - 2] == 0) {
            swap(board[row - 1][col - 1], board[row - 1][col - 2]);
        }
        else if (col < 4 && board[row - 1][col] == 0) {
            swap(board[row - 1][col - 1], board[row - 1][col]);
        }
        else {
            cout << "You can't move this cell." << endl;
        }
        
        displayBoard(board);
    }
    
    cout << "Congratulations! You solved the puzzle." << endl;
    
    return 0;
}
