#include "./mainMenu.h"

void showMainMenu(std::string username) {
    clearScreen();

    bool selecting = true;

    int selectedOption = 0;

    std::string menuOptions[4] = {
        "               Events               ",
        "              Reports               ",
        "              Sign Out              ",
        "                Exit                "
    };

    while (selecting) {
        clearScreen();

        printLogo("logo.txt");

        for (int i = 0; i < 4; i++) {
            printBoxA(menuOptions[i], i == selectedOption, 38);
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        std::cout << std::endl;
        centerText("Logged in as: " + username);
        std::cout << std::endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        char key = _getch();

        if (key == 72) {
            selectedOption = (selectedOption == 0) ? 3 : selectedOption - 1;
        }
        else if (key == 80) {
            selectedOption = (selectedOption == 3) ? 0 : selectedOption + 1;
        }
        else if (key == 13) {
            if (selectedOption == 0) {
                showEventsMenu();
            }
            else if (selectedOption == 1) {
                ShowReportsMenu();
            }
            else if (selectedOption == 2) {
                selecting = false;
                logInScreen();
            }
            else if (selectedOption == 3) {
                exit(0);
            }
        }
    }
}