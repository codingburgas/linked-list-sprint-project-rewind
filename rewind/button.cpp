#include "./button.h"

void printBoxA(std::string option, bool isSelected, int fullWidth) {
    if (isSelected) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(201);
    std::cout << std::string(fullWidth - 2, char(205));
    std::cout << char(187) << std::endl;

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(186)
        << std::string(fullWidth - 2, ' ') << char(186) << std::endl;

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(186)
        << option << char(186) << std::endl;

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(186)
        << std::string(fullWidth - 2, ' ') << char(186) << std::endl;

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(200);
    std::cout << std::string(fullWidth - 2, char(205));
    std::cout << char(188) << "\n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void printEyePassword(bool isSelected, bool isTurnedOn) {

    if (isSelected) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

    if (isTurnedOn) {
        centerText(std::string({ char(95), char(95), char(95) }));
        centerText(std::string({ char(196), char(205), char(196), char(205), char(196), char(205), char(196) }));
        centerText(std::string({ char(238), char(238), char(238) }));
    }
    else {
        centerText(std::string({ char(201), char(205), char(205), char(205), char(187) }));
        centerText(std::string({ char(196), char(205), char(205), ' ', char(254), ' ', char(205), char(205), char(196) }));
        centerText(std::string({ char(200), char(205), char(205), char(205), char(188) }));
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}