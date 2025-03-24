#include "./mainMenu.h"
#include "./visualFunctions.h"
#include <conio.h> // For _getch()
#include <iostream>
using namespace std;

void PrintMenuOption(string option, bool isSelected) {
    cout << string((getConsoleWidth() - 38) / 2, ' ') << char(201);
    for (int i = 0; i < 36; i++) cout << char(205);
    cout << char(187) << endl;

    cout << string((getConsoleWidth() - 38) / 2, ' ') << char(186)
        << string(36, ' ') << char(186) << endl;


    cout << string((getConsoleWidth() - 38) / 2, ' ') << char(186)
        << option << char(186) << endl;

    cout << string((getConsoleWidth() - 38) / 2, ' ') << char(186)
        << string(36, ' ') << char(186) << endl;

    cout << string((getConsoleWidth() - 38) / 2, ' ') << char(200);
    for (int i = 0; i < 36; i++) cout << char(205);
    cout << char(188) << "\n\n";
}

void ShowMainMenu() {
    clearScreen(); // Clear console
    bool selecting = true;
    int selectedOption = 0;

    string menuOptions[4] = {
        "               Events               ",
        "              Reports               ",
        "              Sign Out              ",
        "               Exit                 "
    };

    while (selecting) {
        clearScreen(); // Refresh UI
        cout << "\n\n";
        centerText(" /$$$$$$$  /$$$$$$$$ /$$      /$$ /$$$$$$ /$$   /$$ /$$$$$$$ ");
        centerText("| $$__  $$| $$_____/| $$  /$ | $$|_  $$_/| $$$ | $$| $$__  $$");
        centerText("| $$  \\ $$| $$      | $$ /$$$| $$  | $$  | $$$$| $$| $$  \\ $$");
        centerText("| $$$$$$$/| $$$$$   | $$/$$ $$ $$  | $$  | $$ $$ $$| $$  | $$");
        centerText("| $$__  $$| $$__/   | $$$$_  $$$$  | $$  | $$  $$$$| $$  | $$");
        centerText("| $$  \\ $$| $$      | $$$/ \\  $$$  | $$  | $$\\  $$$| $$  | $$");
        centerText("| $$  | $$| $$$$$$$$| $$/   \\  $$ /$$$$$$| $$ \\  $$| $$$$$$$/");
        centerText("  |__/  |__/|________/|__/     \\__/|______/|__/  \\__/|_______/ \n\n");

        for (int i = 0; i < 4; i++) {
            PrintMenuOption(menuOptions[i], i == selectedOption);
        }

        char key = _getch();
        if (key == 72) { // Up Arrow Key
            selectedOption = (selectedOption == 0) ? 3 : selectedOption - 1;
        }
        else if (key == 80) { // Down Arrow Key
            selectedOption = (selectedOption == 3) ? 0 : selectedOption + 1;
        }
        else if (key == 13) { // Enter Key
            if (selectedOption == 0) {
                // Open Events Menu
            }
            else if (selectedOption == 1) {
                // Open Reports Menu
            }
            else if (selectedOption == 2) {
                // Sign Out
            }
            else if (selectedOption == 3) {
                exit(0); // Immediately closes the program
            }

        }
    }
}
