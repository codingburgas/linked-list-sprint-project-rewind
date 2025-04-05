#include "./eventMenu.h"

void showEventsMenu() {
    clearScreen();

    bool selecting = true;
    int selectedOption = 0;

    std::string eventsMenuOptions[4] = {
        "             Add Event              ",
        "             Edit Event             ",
        "            Delete Event            ",
        "                Back                "
    };

    while (selecting) {
        clearScreen();

        printLogo("eventsLogo.txt");

        for (int i = 0; i < 4; i++) {
            printBoxA(eventsMenuOptions[i], i == selectedOption, 38);
        }

        char key = _getch();

        if (key == 72) {
            selectedOption = (selectedOption == 0) ? 3 : selectedOption - 1;
        }
        else if (key == 80) {
            selectedOption = (selectedOption == 3) ? 0 : selectedOption + 1;
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
                selecting = false;
            }
        }
    }
}