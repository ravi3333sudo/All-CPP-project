#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to draw a line
void drawLine(int n, char symbol) {
    for (int i = 0; i < n; i++) {
        cout << symbol;
    }
    cout << endl;
}

// Function to display the game rules
void rules() {
    cout << "\t\t\tRULES OF THE GAME\n";
    drawLine(60, '-');
    cout << "\t1. Choose a number between 1 to 10.\n";
    cout << "\t2. If you win, you get 10 times your bet amount.\n";
    cout << "\t3. If you lose, you lose your bet amount.\n";
    drawLine(60, '-');
}

int main() {
    string playerName;
    int amount;           // Player's balance amount
    int bettingAmount;    // Amount the player wants to bet
    int guess;            // Player's guess
    int dice;             // Computer-generated number
    char choice;

    srand(time(0)); // Seed the random generator

    // Welcome the player
    drawLine(60, '_');
    cout << "\n\n\n\t\tWELCOME TO THE CASINO GAME\n\n\n";
    drawLine(60, '_');

    // Player details
    cout << "\nEnter Your Name: ";
    getline(cin, playerName);

    cout << "\nEnter Deposit amount to play the game: $";
    cin >> amount;

    do {
        system("cls"); // Clear the screen
        rules();       // Show the rules

        cout << "\nYour current balance is $ " << amount << "\n";

        // Betting amount
        do {
            cout << playerName << ", enter money to bet: $";
            cin >> bettingAmount;
            if (bettingAmount > amount) {
                cout << "Your betting amount is more than your current balance.\nRe-enter data.\n";
            }
        } while (bettingAmount > amount);

        // Player's guess
        do {
            cout << "Guess your number to bet between 1 to 10: ";
            cin >> guess;
            if (guess <= 0 || guess > 10) {
                cout << "Please check the number! It should be between 1 and 10.\n";
            }
        } while (guess <= 0 || guess > 10);

        // Generate random number
        dice = rand() % 10 + 1;

        // Check if the player wins
        if (dice == guess) {
            cout << "\n\nCongratulations! You have won $" << bettingAmount * 10 << "!\n";
            amount += bettingAmount * 10; // Update balance
        } else {
            cout << "\n\nSorry, you lost $ " << bettingAmount << ".\n";
            cout << "The winning number was: " << dice << "\n";
            amount -= bettingAmount; // Update balance
        }

        // Check if the player wants to play again
        cout << "\nDo you want to play again (Y/N)? ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    // Game over message
    cout << "\n\nThanks for playing the game, " << playerName << "!\n";
    cout << "Your final balance is $ " << amount << ".\n";
    return 0;
}