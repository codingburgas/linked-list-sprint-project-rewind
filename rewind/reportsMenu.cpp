#include "./pch.h"
#include "./reportsMenu.h"
#include "./visualFunctions.h"
#include "./reportsManager.h"
#include "./eventManager.h"

extern std::vector<Event> events;

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

    std::string reportsOptions[8] = {
        "          Events by Date            ",
        "          Events by Title           ",
        "          Events by Theme           ",
        "         Events by Location         ",
        "       Events by Participants       ",
        "          Events by Result          ",
        "          Search an Event           ",
        "               Back                 "
    };

    while (selecting) {
        clearScreen();
        printLogo("reportsLogo.txt");

        for (int i = 0; i < 8; i++) {
            PrintReportsMenuOption(reportsOptions[i], i == selectedOption);
        }

        char key = _getch();

        if (key == 72) {
            selectedOption = (selectedOption == 0) ? 7 : selectedOption - 1;
        }
        else if (key == 80) {
            selectedOption = (selectedOption == 7) ? 0 : selectedOption + 1;
        }
        else if (key == 13) {
            clearScreen();
            if (selectedOption == 0) {
                ShowEventsByDate();
            }
            else if (selectedOption == 1) {
                ShowEventsByTitle();
            }
            else if (selectedOption == 2) {
                ShowEventsByTheme();
            }
            else if (selectedOption == 3) {
                ShowEventsByLocation();
            }
            else if (selectedOption == 4) {
                ShowEventsByParticipants();
            }
            else if (selectedOption == 5) {
                ShowEventsByResult();
            }
            else if (selectedOption == 6) {
                SearchEvent();
            }
            else if (selectedOption == 7) {
                selecting = false;
            }
        }
    }
}
