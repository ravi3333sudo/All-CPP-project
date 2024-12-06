#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int BOARD_SIZE = 10;
const char EMPTY = ' ';
const char BALL = '0';
const char PLAYER = 'P';

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            cout << board[row][col] << ' ';
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Correct spelling of srand

    char board[BOARD_SIZE][BOARD_SIZE];
    int playerRow = BOARD_SIZE - 1;
    int playerCol = BOARD_SIZE / 2;
    int ballRow = 0;
    int ballCol = rand() % BOARD_SIZE;

    // Initialize board
    for (int row = 0; row < BOARD_SIZE; ++row) { // Correct variable name and capitalization
        for (int col = 0; col < BOARD_SIZE; ++col) {
            board[row][col] = EMPTY;
        }
    }

    board[playerRow][playerCol] = PLAYER;
    board[ballRow][ballCol] = BALL;

    bool gameRunning = true;
    int score = 0;

    while (gameRunning) {
        // Display the board
        system("clear"); // For Linux/macOS; use "cls" on Windows
        displayBoard(board);

        // Move the ball
        board[ballRow][ballCol] = EMPTY; // Clear old ball position
        if (ballRow + 1 < BOARD_SIZE) {
            ballRow++;
        } else {
            gameRunning = false; // Ball reached the bottom
            cout << "Game Over! Your score: " << score << endl;
            break;
        }
        board[ballRow][ballCol] = BALL;

        // Player movement
        char input;
        cout << "Move left (a) or right (d): ";
        cin >> input;

        board[playerRow][playerCol] = EMPTY; // Clear old player position
        if (input == 'a' && playerCol > 0) {
            playerCol--;
        } else if (input == 'd' && playerCol < BOARD_SIZE - 1) {
            playerCol++;
        }
        board[playerRow][playerCol] = PLAYER;

        // Check for collision
        if (ballRow == playerRow && ballCol == playerCol) {
            score++;
            ballRow = 0;
            ballCol = rand() % BOARD_SIZE;
            board[ballRow][ballCol] = BALL;
        }
    }

    return 0;
}
    