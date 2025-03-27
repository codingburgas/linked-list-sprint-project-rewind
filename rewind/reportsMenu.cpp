#include "./pch.h"
#include "./reportsMenu.h"
#include "./visualFunctions.h"

void PrintReportsMenuOption(std::string option, bool isSelected) {
    if (isSelected) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    std::cout << std::string((getConsoleWidth() - 38) / 2, ' ') << char(201);
    for (int i = 0; i < 36; i++) std::cout << char(205);
    std::cout << char(187) << std::endl;

    std::cout << std::string((getConsoleWidth() - 38) / 2, ' ') << char(186)
        << std::string(36, ' ') << char(186) << std::endl;

    std::cout << std::string((getConsoleWidth() - 38) / 2, ' ') << char(186)
        << option << char(186) << std::endl;

    std::cout << std::string((getConsoleWidth() - 38) / 2, ' ') << char(186)
        << std::string(36, ' ') << char(186) << std::endl;

    std::cout << std::string((getConsoleWidth() - 38) / 2, ' ') << char(200);
    for (int i = 0; i < 36; i++) std::cout << char(205);
    std::cout << char(188) << "\n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void ShowReportsMenu() {
    clearScreen();

    bool selecting = true;
    int selectedOption = 0;

    std::string reportsOptions[4] = {
        "        List All Event Titles       ",
        "          Events By Date            ",
        "         Events by leader           ",
        "                Back                "
    };

    while (selecting) {
        clearScreen();

        printLogo("reportsLogo.txt");

        for (int i = 0; i < 4; i++) {
            PrintReportsMenuOption(reportsOptions[i], i == selectedOption);
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
                // Function to list all event titles
            }
            else if (selectedOption == 1) {
                // Function to show events by theme
            }
            else if (selectedOption == 2) {
                
            }
            else if (selectedOption == 3) {
                selecting = false; // Go back to Main Menu
            }
        }
    }
}
