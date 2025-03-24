#include "./pch.h"
#include "./eventsMenu.h"
#include "./visualFunctions.h"

void PrintEventMenuOption(std::string option, bool isSelected) {
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

void ShowEventsMenu() {
    clearScreen();

    bool selecting = true;
    int selectedOption = 0;

    std::string eventMenuOptions[5] = {
        "             Add Event              ",
        "             Edit Event             ",
        "            Delete Event            ",
        "            Search Event            ",
        "          Back to Main Menu         "
    };

    while (selecting) {
        clearScreen();
        printLogo("eventslogo.txt");

        for (int i = 0; i < 5; i++) {
            PrintEventMenuOption(eventMenuOptions[i], i == selectedOption);
        }

        char key = _getch();

        if (key == 72) {
            selectedOption = (selectedOption == 0) ? 4 : selectedOption - 1;
        }
        else if (key == 80) {
            selectedOption = (selectedOption == 4) ? 0 : selectedOption + 1;
        }
        else if (key == 13) { // Enter Key
            if (selectedOption == 0) {
                // Function to add event
            }
            else if (selectedOption == 1) {
                // Function to edit event
            }
            else if (selectedOption == 2) {
                // Function to delete event
            }
            else if (selectedOption == 3) {
                // Function to search event
            }
            else if (selectedOption == 4) {
                selecting = false;
            }
        }
    }
}
