#include<iostream>
#include<vector>
#include<cstdlib>
#include <ctime>
using namespace std;

const int row = 5;
const int col = 5;
vector<vector<char>> board(row, vector<char>(col));
char colors[] = {'R', 'G', 'B'};

char randomColor() {
    return colors[rand() % 3];
}

void printBoard() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void swapCells(int r1, int c1, int r2, int c2) {
    char temp = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = temp;
}

vector<pair<int, int>> checkMates() {
    vector<pair<int, int>> matched;
    for (int i = 0; i < row; i++) {
        int count = 1;
        for (int j = 1; j < col; j++) {
            if (board[i][j] == board[i][j - 1]) {
                count++;
            } else {
                if(count >= 3) {
                    for(int k = col - count - 1; k < col; k++) {
                        matched.push_back({i, k});
                    }
                }

                count = 1;
            }
        }

        if(count >= 3) {
            for(int k = col - count - 1; k < col; k++) {
                matched.push_back({i, k});
            }
        }
    }
    return matched;
}

void removeMatches(vector<pair<int,int>> matched) {
    for (auto &p : matched) {
        board[p.first][p.second] = ' ';  // empty cell
    }
    for (int c = 0; c < col; c++) {
        vector<char> stack;
        for (int r = row-1; r >= 0; r--) {
            if (board[r][c] != ' ') stack.push_back(board[r][c]);
        }
        for (int r = row - 1; r >= 0; r--) {
            if (!stack.empty()) {
                board[r][c] = stack.front();
                stack.erase(stack.begin());
            } else {
                board[r][c] = randomColor();
            }
        }
    }
}

int main() {
    srand(time(0));
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            board[r][c] = randomColor();
        }
    }

    cout << "Initial Board:\n";
    printBoard();

    while (true) {
        int r1,c1,r2,c2;
        cout << "Enter first cell (row col): ";
        cin >> r1 >> c1;
        cout << "Enter second cell (row col): ";
        cin >> r2 >> c2;

        if (r1<0 || r1>=row || c1<0 || c1>=col || r2<0 || r2>=row || c2<0 || c2>=col) {
            cout << "Invalid positions! Try again.\n";
            continue;
        }

        swapCells(r1, c1, r2, c2);

        vector<pair<int, int>> matched = checkMates();

        if (!matched.empty()) {
            cout << "\nMatch found! Blocks removed.\n\n";
            removeMatches(matched);
        } else {
            cout << "\nNo match! 🎭 Basket effect appears!\n\n";
            swapCells(r1, c1, r2, c2); 
        }

        printBoard();
    }

    return 0;
}
