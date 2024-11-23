#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

enum Color
{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    PURPLE
};

Color generateRandomColor()
{
    int randomNum = rand() % 5;
    return static_cast<Color>(randomNum);
}

string colorString(Color color)
{
    switch (color)
    {
    case RED:
        return "Red";
    case GREEN:
        return "Green";
    case BLUE:
        return "Blue";
    case YELLOW:
        return "Yellow";
    case PURPLE:
        return "Purple";
    default:
        return "Unknown";
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Color targetColor = generateRandomColor(); // Fixed missing semicolon

    string guess;

    while (true)
    {
        system("cls");
        cout << "Welcome to the Colored Square Game!" << endl;
        cout << "***********************************" << endl;
        cout << "Guess the color of the square (Red, Green, Blue, Yellow, or Purple.)" << endl;
        cout << "Enter your guess: ";
        cin >> guess;

        // Convert the guess to lowercase for case-insensitive comparison
        for (int i = 0; i < guess.length(); ++i)
        {
            guess[i] = tolower(guess[i]);
        }

        Color userColor;
        if (guess == "red")
            userColor = RED;
        else if (guess == "green")
            userColor = GREEN;
        else if (guess == "blue")
            userColor = BLUE;
        else if (guess == "yellow")
            userColor = YELLOW;
        else if (guess == "purple")
            userColor = PURPLE;
        else
        {
            cout << "Invalid color. Please enter a valid color." << endl;
            Sleep(1000);
            continue; // Skip the rest of the loop and prompt again
        }

        if (userColor == targetColor)
        {
            cout << endl;
            cout << "Congratulations! You guessed the correct color: " << colorString(targetColor) << "." << endl;
            break;
        }
        else
        {
            cout << "Wrong guess. Try again!" << endl;
            Sleep(1000);
        }
    }

    return 0;
}
