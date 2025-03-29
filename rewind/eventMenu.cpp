#include "./pch.h"
#include "./eventMenu.h"
#include "./visualFunctions.h"
#include "./eventManager.h"

void PrintEventsMenuOption(std::string option, bool isSelected) {
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

    std::string eventsMenuOptions[5] = {
        "              Add Event             ",
        "             Edit Event             ",
        "            Delete Event            ",
        "            Search Event            ",
        "                Back                "
    };

    while (selecting) {
        clearScreen();

        printLogo("eventsLogo.txt");

        for (int i = 0; i < 5; i++) {
            PrintEventsMenuOption(eventsMenuOptions[i], i == selectedOption);
        }

        char key = _getch();

        if (key == 72) {
            selectedOption = (selectedOption == 0) ? 4 : selectedOption - 1;
        }
        else if (key == 80) {
            selectedOption = (selectedOption == 4) ? 0 : selectedOption + 1;
        }
        else if (key == 13) {
            clearScreen();
            if (selectedOption == 0) {
                AddEvent();
            }
            else if (selectedOption == 1) {
                EditEvent();
            }
            else if (selectedOption == 2) {
                DeleteEvent();
            }
            else if (selectedOption == 3) {
                SearchEvent();
            }
            else if (selectedOption == 4) {
                selecting = false;
            }
        }
    }
}
